
#include <iostream>
#include <memory>

// 삭제자 함수객체


template<typename T> struct default_delete
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete p; // delete는 void * type을 받으면 소멸자 호출 못함. 그래서 T를 사용
	}
};

struct Freer
{
	// free는 소멸자 호출하지 않으므로 void*를 사용해도 됩니다.
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};

template<typename T, typename D = default_delete<T>>
class unique_ptr
{
	T* obj;
	D d; // 삭제자를 보관합니다.
public:
	inline unique_ptr(T* p = 0, const D& del = D()) : obj(p), d(del) {}
	inline ~unique_ptr()
	{
		std::cout << "default delete" << std::endl;
		d(obj);
	}
	inline T* operator->() { return obj; };
	inline T& operator*() { return *obj; }

	// 복사 생성자와 대입 연산자를 삭제 합니다.
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int> p1(new int);
	//unique_ptr<void> p2(malloc(100)); // malloc으로 생성된 것은 소멸자로 delete하면 안됨, 
	//unique_ptr<void, Freer> p2((int*)malloc(100));

	// error. 람다 표현식은 타입이 아니라 객체임 
	//unique_ptr<void, [](int*) { free(p); } > p2((int*)malloc(100));

	//unique_ptr<void, decltype([](int*) { free(p); })> p2((int*)malloc(100));

	// 삭제자로 사용할 람다 표현식을 만들어서 auto에 담는다. 람다식을 이용해서 전달시 소멸자 처리..
	auto del = [](void* p) { free(p); std::cout << "lambda" << std::endl;  };
	unique_ptr<int, decltype(del)> p3(new int, del);
}