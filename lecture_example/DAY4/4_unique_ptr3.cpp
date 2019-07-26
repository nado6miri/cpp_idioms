#include <iostream>
#include <memory>

// 삭제자 함수 객체
template<typename T> struct default_delete
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete p;
	}
};

struct Freer
{
	// free는 소멸자를 호출하지 않으므로 void* 를 사용해도 됩니다.
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p); 
	}
};


template<typename T, typename D = default_delete<T> >
class unique_ptr
{
	T* obj;
public:
	inline unique_ptr(T* p = 0) : obj(p) {}
	
	inline ~unique_ptr() 
	{
		D d;
		d(obj); // 삭제자 함수 객체를 사용해서 삭제.
	}

	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int>  p1(new int);
	unique_ptr<int, Freer> p2((int*)malloc(100));

	//아래 sp1, sp2는 다른 타입 ? 같은 타입 ?
	//std::shared_ptr<int> sp1(new int);
	//std::shared_ptr<int> sp2(new int, foo);
}



