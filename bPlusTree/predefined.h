#ifndef PREDEFINED_H
#define PREDEFINED_H

#include <string.h>
#include <strings.h>

namespace bPlusTree {

    //B+树的阶数，非叶节点最多BP_ORDER个节点
    //叶节点最多存BP_ORDER-1个键值对
	#define BP_ORDER 50

	/*key/value_type*/

	//value_type
	struct value_t {
		int age;
		char name[256];
		char email[256];
	};

	//key_type
	struct key_t {
		char k[16];
		key_t(const char* str = "") {
			bzero(k, sizeof(k));
            strcpy(k,str);
		}
	};

    inline int keycmp(const key_t &a,const key_t &b){
        int delta = strlen(a.k) - strlen(b.k);
        return delta == 0 ? strcmp(a.k,b.k) : delta; 
    }

    //重载运算符 
    //重定义key和其它任意类型的key的比较
    #define OPERATOR_KEYCMP(type) \
        bool operator< (const key_t &l, const type &r){\
            return keycmp(l,r.key) < 0;\
        }\
        bool operator< (const type &l, const key_t &r){\
            return keycmp(l.key,r) < 0;\
        }\
        bool operator== (const key_t &l, const type &r){\
            return keycmp(l,r.key) == 0;\
        }\
        bool operator< (const type &l, const key_t &r){\
            return keycmp(l.key,r) == 0;\
        }\

}

#endif PREDEFINED_H
