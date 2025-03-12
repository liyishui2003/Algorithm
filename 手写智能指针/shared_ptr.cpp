#include<iostream>

template <typename T>
class shared_ptr{

private:
	T* ptr;
	size_t* cnt;
	/*
	将引用计数减1，如果减后变为0
	说明没有其他实例引用该对象，于是释放占用的内存。
	*/
	void realse(){
		if(cnt && --(*cnt) == 0){
			delete ptr;
			delete cnt;
		}
	}
	
public:
	// 初始化
	explicit shared_ptr(T* _ptr = nullptr):ptr(_ptr),
		cnt(_ptr ? new size_t(1) : nullptr){
		
	}
	// 拷贝操作
	// 传入other，令this等于other并修改引用计数
	shared_ptr(const shared_ptr& other):ptr(other.ptr),cnt(other.cnt){
		if(cnt){
			++(*cnt);
		}
	}
	//赋值操作
	//shared_ptr& 表示返回的是一个引用，除了减少开销外
	//还可以支持a = b = c这样的操作
	shared_ptr& operator=(const shared_ptr& other){
		/*
		在赋值运算符重载函数中，通常是比较对象的地址是否相同
		常见的做法是将 other 的地址与 this 进行比较，即 this != &other
		如果写的是 *this != other，要重载 == 运算符
		*/
		if( this != &other){
			realse();
			ptr = other.ptr;
			cnt = other.cnt;
			if(cnt){
				++(*cnt);
			}
		}
		//这里this前加*号是this是指向当前实例的指针
		//解引用后才能返回实例(引用)
		return *this;
	}
	//析构函数
	~shared_ptr(){
		realse();
	}
	// 有时可能需要对指针进行算数运算，或其它需求
	// 总之get()用来支持返回原指针
	T* get() const {
		return ptr;
	}
	// 常规的解引用
	T* operator->() const {
		return *ptr;
	}
	T& operator*() const {
		return *ptr;
	}
	size_t getCnt() const {
		return cnt ? *cnt : 0;
	}
};
class Myclass{
public:
	Myclass(){
		
	}
	void doSomething(){
		
	}
};
int main(){
	shared_ptr<Myclass> ptrA(new Myclass());
	std::cout<< ptrA.getCnt() << '\n';
	shared_ptr<Myclass> ptrB;
	ptrB = ptrA;
	std::cout<< ptrA.getCnt() << '\n';
	std::cout<< ptrB.getCnt() << '\n';
}
