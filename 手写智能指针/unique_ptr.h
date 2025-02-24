#include <iostream>

template<typename T>
class unique_ptr{
	
private:
	T* ptr;
	
public:
	explicit unique_ptr(T* _ptr = nullptr):ptr(_ptr){
		
	}
	// 移动构造函数：
	// 使用右值引用实现移动赋值：
	// 先把p.ptr 赋值给新的ptr
	// 然后将p.ptr 置空
	unique_ptr(unique_ptr &&p) noexcept : ptr(p.ptr){
		p.ptr = nullptr;
	}
	//将拷贝构造运算ban掉，不允许拷贝，符合独占的定义
	//其中(const class &)是拷贝构造的常用写法
	unique_ptr(const unique_ptr &) = delete;
	//同理将拷贝赋值运算ban掉
	unique_ptr &operator=(const unique_ptr &) = delete;
	//析构函数
	~unique_ptr(){
		if(ptr) 
			delete ptr;
	}
	//移动赋值运算符
	inline unique_ptr<T> &operator=(unique_ptr &&p) noexcept{
		std::swap(*this,p);
		//p是一个右值引用，右值引用是临时的
		//出了这个作用域就会被释放掉，满足"移动赋值"的定义
		return *this;
	}
	// 有时可能需要对指针进行算数运算，或其它需求
	// 总之get()用来支持返回裸指针
	T* get() const {
		return ptr;
	}
	//inline表示内联函数，可以展开函数体直接嵌入
	//但编译器不一定采用，只是个建议
	//这里重载了解引用运算符(*)，且返回的是引用(&)
	inline T &operator*() const{
		return *get();
	}
	//重载*运算符，返回原指针
	inline T *operator->() const{
		return get();
	}
	//将ptr的值修改为q
	inline void reset(T *q = nullptr)noexcept{
		if(q != ptr){
			if(ptr) delete ptr;
			ptr = q;
		}
	}
	//释放资源并返回裸指针
	inline T *release(T *q = nullptr) noexcept{
		T *res = ptr;
		ptr = nullptr;
		return res;
	}
};
