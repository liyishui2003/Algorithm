#include "../include/bPlusTree.h"

#include <stdlib.h>

#include <list>
#include <algorithm>
using std::swap;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;

namespace bPlusTree{
    
    //custom compare operator for STL algorithms
    OPERATOR_KEYCMP(index_t);
    OPERATOR_KEYCMP(record_t);
    /*
    在leaf_node_t和internal_node_t中都有children数组
    并给它们取了统一的别名：child_t，用模板类能返回首地址和结束地址
    而不用再写leaf_node_t.children或者是internal_node_t.children
    helper iterating function
    */
    template<class T>
    inline typename T::child_t begin(T &node){
        return node.children;
    }
    template<class T>
    inline typename T::child_t end(T &node){
        return node.children+node.n;
    }

    inline index_t *find(internal_node_t &node,const key_t &key){
        return upper_bound(begin(node),end(node)-1,key); 
    }

    inline record_t *find(leaf_node_t &node,const key_t &key){
        return lower_bound(begin(node),end(node),key);
    }

    bPlusTree::bPlusTree(const char *p,bool force_empty)
        :fp(NULL),fp_level(0){
        //p: the path of metaFile
        bzero(path,sizeof(path));
        strcpy(path,p);

        if(!force_empty){
            // read tree from metaFile
            if(map(&meta,OFFSET_META) != 0){
                force_empty=true;//read falied
            }
        }

        if(force_empty){
            open_file("w+");
            init_from_empty();
            close_file();
        }
    }
    //该函数读入key，并返回key对应的文件偏移量
    //查找过程就是从root出发不断往下走
    off_t bPlusTree::search_index(const key_t& key)const{
        off_t org = meta.rootOffset;
        int height = meta.height;
        while(height>1){
            internal_node_t node;
            map(&node,org);
            index_t *i=upper_bound(begin(node),end(node)-1,key);
            org=i->child;
            height--;
        }
        return org;
    }
    //此时index指向leaf节点的上一级节点
    //通过upper_bound找到对应的叶子节点
    off_t bPlusTree::search_leaf(off_t index,const key_t &key)const{
        internal_node_t node;
        map(&node,index);
        index_t *i=upper_bound(begin(node),end(node)-1,key);
        return i->child;
    }
    //此时来到了叶子节点
    //但叶子节点还存储了多条record
    //进一步根据传入的key找到对应的record并将record写入*value
    int bPlusTree::search(const key_t& key,value_t *value)const{
        leaf_node_t leaf;
        //search_leaf(key)会返回key对应的offset
        map(&leaf,search_leaf(key));

        record_t *record = find(leaf,key);
        if(record != leaf.children+leaf.n){
            *value = record->value;//写入数据
            return keycmp(record->key,key);//找到了也可能是大于，要再判断一下是不是
        }
        else {//说明相当于返回end()，找不到
            return -1;
        }
    }
    //返回的是key值在[left,right]里的key的个数，数据写在*value里
    //max表示最多返回多少
    //这里左边界之所以用指针是因为下面会用到left->next来移动
    //而有边界不需要移动，且不希望被改动，用const+引用来修饰
    int bPlusTree::search_range(key_t *left,const key_t &right,
                                value_t *values,size_t max,bool *next)const{
        if(left == NULL || keycmp(*left,right) > 0) {
            return -1;
        }

        off_t off_left = search_leaf(*left);
        off_t off_right = search_leaf(right);
        off_t off = off_left;
        size_t i = 0;
        record_t *b,*e;

        leaf_node_t leaf;
        while(off != off_right && off != 0 && i < max){
            map(&leaf,off);
            //如果还在左边界，用find在当前叶子节点中找键 *left 对应的记录，
            //并将指针 b 指向该record。
            //否则，将指针 b 指向当前叶子节点的第一个记录begin(leaf)
            //要这么写是因为每个叶子节点会对应很多条record
            //且我们可能要遍历好几个叶子节点才能走完这个范围
            if(off_left == off)
                b = find(leaf,*left);
            else 
                b = begin(leaf);
            //copy 
            e = leaf.children + leaf.n;
            for(; b != e && i < max;++b,++i){
                values[i] = b->value;
            }

            off = leaf.next;
        }

        if( i < max){
            map(&leaf,off_right);

            b = find(leaf,*left);
            e = upper_bound(begin(leaf),end(leaf),right);
            for(; b != e && i < max;++i,++e){
                values[i] = b->value;
            }
        }

        if(next != NULL){
            if(i == max && b != e){
                *next=true;
                *left=b->key;
            }
            else *next=false;
        }

        return i;
    }

    int bPlusTree::remove(const key_t& key){
        internal_node_t parent;
        leaf_node_t leaf;

        // find parent node
        // 上面提到，search_index(key)返回的是key对应的上一级节点的偏移量
        off_t parent_off = search_index(key);
        map(&parent,parent_off);
        // find current node
        index_t *where = find(parent,key);
        off_t offset = where->child;
        map(&leaf,offset);

        //特判找不到的情况
        if(!binary_search(begin(leaf),end(leaf),key)){
            return -1;
        }

        size_t min_n = meta.leafNodeNum == 1 ? 0 : meta.order/2;
        assert(leaf.n >= min_n && leaf.n <= meta.order);

        //从代码层面删除了key对应的record，改动了数据结构leaf的信息
        record_t *to_dele = find(leaf,key);
        std::copy(to_dele+1,end(leaf),to_dele);
        leaf.n--;
        
        //merge or borrow
        if(leaf.n < min_n){ 
             bool borrowed = false;
             //from left
             if (leaf.prev != 0)
                borrowed = borrow_key(false,leaf);
             //from right
             if(!borrowed && leaf.next != 0){
                borrowed = borrow_key(true,leaf);
             }

             //just merge!
             if(!borrowed){
                assert(leaf.next != 0 || leaf.prev != 0);

                key_t index_key;

                if(where == end(parent) - 1){
                    // if leaf is last element then merge : | prev | leaf | -> | prev leaf |
                    assert(leaf.prev != 0);
                    leaf_node_t prev;
                    map(&prev,leaf.prev);

                    //这里原作者可能有笔误，存疑
                    index_key = begin(prev)->key;
                    //以及为什么是begin()而非其它值，指向第一个是我们设定的吗？

                    merge_leafs(&prev,&leaf);//数据结构层面合并
                    node_remove(&prev,&leaf);//物理层面合并(用到了map/unmap)
                    unmap(&prev,leaf.prev);//修改了prev，要回写
                }
                else {
                    assert(leaf.next!=0);
                    leaf_node_t next;
                    map(&next,leaf.next);
                    
                    //这里原作者可能有笔误，存疑
                    index_key = begin(leaf)->key;

                    merge_leafs(&leaf,&next);
                    node_remove(&leaf,&next);
                    unmap(&leaf,offset);
                }
                remove_from_index(parent_off,parent,index_key);
             }
             else {
                unmap(&leaf,offset);
            }
        }
        else {
            unmap(&leaf,offset);
        }
    }
    //当叶子节点合并完后，要修改上级节点的索引等
    //进一步可能引发内部节点的不平衡
    //和叶子节点类似，内部节点不平衡要考虑borrow或者merge
    void bPlusTree::remove_from_index(off_t offset,internal_node_t &node,
                            const key_t &key)
    {
        size_t min_n = meta.rootOffset == offset ? 1 : meta.order / 2;
        assert(node.n >= min_n && node.n <= meta.order);

        
        key_t index_key = begin(node)->key;
        index_t *toDel = find(node,key);
        if(toDel != end(node)){
            (toDel+1)->child = toDel->child;
            std::copy(toDel+1,end(node),toDel);
        }
        node.n--;
        
        /*
        B+ 树的根节点在只剩下一个键时，
        其唯一的子节点实际上包含了所有剩余的有效信息。
        根节点此时的存在只是增加了树的高度，对查找、插入等操作没有实际帮助。
        可以直接将根节点的唯一子节点提升为新的根节点。
        */
        if(node.n == 1 && meta.rootOffset == offset && 
                meta.internalNodeNum != 1)
        {
            unalloc(&node,meta.rootOffset);
            meta.height--;
            meta.rootOffset = node.children[0].child;
            unmap(&meta,OFFSET_META);
            return;
        }

        if(node.n < min_n){

            internal_node_t parent;
            map(&parent,node.parent);
            //内部节点不富裕时借的是key
            //borrow key from left
            bool borrowed = false;
            if(offset != begin(parent)->child){
                borrowed = borrow_key(false,node,offset);
            }

            if(!borrowed && offset != (end(parent)-1)->child){
                borrowed = borrow_key(true,node,offset);
            }

            if(!borrowed){

                assert(node.next != 0 || node.prev != 0);

                if(offset == (end(parent)-1)->child){

                    assert(node.prev != 0);
                    internal_node_t prev;
                    map(&prev,node.prev);
                    //where是分隔键，分隔node.pre和node，但这里好像其实没用
                    index_t *where = find(parent,begin(prev)->key);
                    //把node的子节点的parent都设置为node.prev
                    reset_index_children_parent(begin(node),end(node),node.prev);
                    merge_keys(where,prev,node);
                    unmap(&prev,node.prev);
                }
                else {
                    assert(node.next != 0);
                    internal_node_t next;
                    map(&next,node.next);

                    index_t *where = find(parent,index_key);
                    //把node的子节点的parent都设置为node.prev
                    reset_index_children_parent(begin(next),end(next),offset);
                    merge_keys(where,node,next);
                    unmap(&node,offset);
                }
                //开始递归调用，层层往上调整
                remove_from_index(node.parent,parent,index_key);
            }
            else {
                unmap(&node,offset);
            }
        }
        else {
            unmap(&node,offset);
        }

    }

    bool bPlusTree::borrow_key(bool fromRight,internal_node_t &borrower,off_t offset){

        typedef typename internal_node_t::child_t child_t;

        off_t lenderOff = fromRight ? borrower.next : borrower.prev;
        internal_node_t lender;
        map(&lender,lenderOff);

        assert(lender.n >= meta.order / 2);

        if(lender.n != meta.order / 2){
            child_t whereToLend,whereToPut;
            internal_node_t parent;

            if(fromRight){
                whereToLend = begin(lender);
                whereToPut = end(borrower);

                map(&parent,borrower.parent);
                /*
                当从右边节点（lender）借一个键时，右边节点的第一个键被借走，
                这会导致右子树中键的最小值发生变化。
                因此，需要更新上级节点中分隔借入节点和右边节点的索引键，
                使其等于新的右子树中键的最小值，即 where_to_lend->key。
                这里做的则是把
                */
                child_t where = lower_bound(begin(parent),end(parent)-1,(end(borrower)-1)->key);
                where->key = whereToLend->key;
                unmap(&parent,borrower.parent);
            }
            else {
                whereToLend = end(lender) - 1;
                whereToPut = begin(borrower);
              
                child_t where = find(parent,begin(lender)->key);
                whereToPut->key = whereToLend -> key;
                whereToLend->key = (whereToLend-1) -> key;
                unmap(&parent,lender.parent);
            }
            //save
            std::copy_backward(whereToPut,end(borrower),end(borrower)+1);
            *whereToPut = *whereToLend;
            borrower.n++;
            //erase
            reset_index_children_parent(whereToLend,whereToLend+1,offset);
            std::copy(whereToLend+1,end(lender),whereToLend);
            lender.n--;
            unmap(&lender,lenderOff);
            return true;
        }
        return false;
    }


    template<class T>
    void bPlusTree::node_remove(T *prev,T *node){
        unalloc(node,prev->next);//但unalloc里第二个参数并没用上
        prev->next = node->next;
        if(node->next != 0){
            T next;
            map(&next,node->next,SIZE_NO_CHILDREN);//从磁盘中加载出来
            next.prev = node->prev;//链表删除
            unmap(&next,node->next,SIZE_NO_CHILDREN);//写回去
        }
        unmap(&meta,OFFSET_META);//刚才unalloc更新了meta，meta也要写回去
    }
    //合并next的键到node中去
    void bPlusTree::merge_keys(index_t *where,internal_node_t &node,internal_node_t &next){
        std::copy(begin(next),end(next),end(node));
        node.n += next.n;
        node_remove(&node,&next);
    }
    //数据结构层面合并两个叶子节点
    void bPlusTree::merge_leafs(leaf_node_t *left,leaf_node_t *right){
        std::copy(begin(*right),end(*right),end(*left));
        left->n += right->n;
    }   

    //把[begin,end]范围内的节点的parent都修改为我们的指定值
    void bPlusTree::reset_index_children_parent(index_t *begin,index_t *end,off_t parent){
        internal_node_t node;
        while(begin!=end){
            map(&node,begin->child);
            node.parent = parent;
            unmap(&node,begin->child,SIZE_NO_CHILDREN);
            ++begin;
        }
    }
}
