#pragma once

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef UNIT_TEST
#include "predefined.h"
#else 
#endif

namespace bPlusTree{

    /*offsets*/
    #define OFFSET_META 0
    //meta_t 是自定义的数据类型，用于表示元数据的结构。这个宏表示数据块中除元数据外其他数据的起始偏移量
    #define OFFSET_BLOCK OFFSET_META + sizeof(meta_t)
    //计算叶子节点中除了记录数据外其他部分的大小，比如节点的元信息、指针等。
    #define SIZE_NO_CHILDREN sizeof(leaf_node_t) - BP_ORDER * sizeof(record_t)

    /*
    存储键值对大小、内部节点数、叶节点数、树高
    slot:存储新数据时写到哪
    rootOffset:根节点在文件中的偏移量
    leafOffset:第一个叶节点在文件中的偏移量
    */
    typedef struct 
    {
        size_t order;
        size_t valueSize;
        size_t keySize;
        size_t internalNodeNum;
        size_t leafNodeNum;
        size_t height;
        off_t slot;
        off_t rootOffset;
        off_t leafOffset;
    }meta_t;
    
    //内部节点的键和指向孩子的指针
    struct index_t{
        key_t key;
        off_t child;
    };

    struct internal_node_t{
        typedef index_t *child_t;
        //中间节点的上级节点、前驱、后继、当前有多少孩子节点以及对应的index_t(键和指针)
        off_t parent;
        off_t next;
        off_t prev;
        size_t n;
        index_t children[BP_ORDER];
    };

    struct record_t{
        key_t key;
        value_t value;
    };

    struct leaf_node_t{
        typedef record_t *child_t;

        off_t parent;
        off_t next;
        off_t prev;
        size_t n;
        record_t children[BP_ORDER];
    };

    class bPlusTree{

        public:
            bPlusTree(const char *path,bool force_empty = false);

            int search(const key_t& key,value_t *value)const;

            int search_range(key_t *left,const key_t &right,
            value_t *values,size_t max,bool *next = NULL) const;

            int remove(const key_t& key);
            int insert(const key_t& key,value_t value);
            int update(const key_t& key,value_t value);

            meta_t getMeta()const{
                return meta;
            };
        //单元测试时暴露所有成员，所以是public
        #ifndef UNIT_TEST
        private:
        #else 
        public:
        #endif
            char path[512];
            meta_t meta;

            // build empty tree
            void init_from_empty();
            // search by index
            off_t search_index(const key_t &key)const;
            // find leaf
            /*
            index 代表内部节点的偏移量。
            从根节点开始根据键值逐步向下遍历内部节点，index用来定位某个内部节点在存储介质中的位置。
            key：要查找的键，通过比较键值决定在树中查找的方向。
            功能推测?：此函数会从指定偏移量 index 对应的内部节点开始,
            根据键 key 向下查找，直至找到包含该键的叶子节点，并返回叶子节点的偏移量。
            */
            off_t search_leaf(off_t index,const key_t &key)const;
            off_t search_leaf(const key_t &key)const{
                return search_leaf(search_index(key),key);
            }

            void remove_from_index(off_t offset,internal_node_t &node,const key_t &key);
            //borrow one key from other internal node
            bool borrow_key(bool fromRight,internal_node_t &borrower,off_t offset);
            //borrow one record from other leaf
            bool borrow_key(bool fromRight,leaf_node_t &borrower);
            //change one's parent key to another key
            void change_parent_child(off_t parent,const key_t &o,const key_t &n);
            //merge right leaf to left leaf
            void merge_leafs(leaf_node_t *left,leaf_node_t *right);
            void merge_keys(index_t *where,internal_node_t &left,internal_node_t &right);
            //insert into leaf without split
            void insert_record_no_split(leaf_node_t *leaf,const key_t &key,const value_t &value);
            //add key to the internal node
            void insert_key_to_index(off_t offset,const key_t &key,off_t value,off_t after);
            void insert_key_to_index_no_split(internal_node_t &node,const key_t &key,off_t value);
            //change children's parent
            void reset_index_children_parent(index_t *begin,index_t *end,off_t parent);

            template<class T>
            void node_create(off_t offset,T *node,T *next);

            template<class T>
            void node_remove(T *prev,T *node);

            /*
            multi-level file open and close
            */
            mutable FILE *fp;
            mutable int fp_level;
            void open_file(const char *mode ="rb+") const{
                if(fp_level == 0)
                    fp = fopen(path,mode);
                ++fp_level;
            }

            void close_file()const{
                if(fp_level == 1){
                    fclose(fp);
                }
                --fp_level;
            }
            // alloc from disk
            off_t alloc(size_t size){
                off_t slot=meta.slot;
                meta.slot+=size;
                return slot;
            }

            off_t alloc(leaf_node_t *leaf){
                leaf->n=0;
                meta.leafNodeNum++;
                return alloc(sizeof(leaf_node_t));
            }

            off_t alloc(internal_node_t *node){
                node->n=1;
                meta.internalNodeNum++;
                return alloc(sizeof(internal_node_t));
            }

            void unalloc(leaf_node_t *leaf,off_t offset){
                --meta.leafNodeNum;
            }

            void unalloc(internal_node_t *node,off_t offset){
                --meta.internalNodeNum;
            }

            /*
            从磁盘中读取数据到内存，存储在block里。
            offset表示在文件中的偏移量，size表示读取多少数据。
            */
            int map(void *block,off_t offset,size_t size)const{
                open_file();
                fseek(fp,offset,SEEK_SET);
                size_t rd = fread(block,size,1,fp);
                close_file();
                return rd-1;
            }
            //使用模板，能支持读取各种类型的数据
            template<class T>
            int map(T *block,off_t offset)const{
                return map(block,offset,sizeof(T));
            }

            int unmap(void *block,off_t offset,size_t size)const{
                open_file();
                fseek(fp,offset,SEEK_SET);
                size_t wd=fwrite(block,size,1,fp);
                close_file();
                return wd-1;
            }

            template<class T>
            int unmap(T *block,off_t offset)const{
                return ummap(block,offset,sizeof(T));
            }

    };
}
