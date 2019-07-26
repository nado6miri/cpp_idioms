// 7_reference_wrapper
#include <iostream>
#include <functional>

// reference_wrapper : 이동 가능한 참조
//			  참조 끼리 대입시 참조가 이동

template<typename T> class reference_wrapper
{
	T* ptr;
public:
	reference_wrapper(T& p) { ptr = &p; }

	operator T&() { return *ptr; }
	T& get() const { return *ptr; }
};

void foo(int& a) { a = 100; }

// 아래 함수가 bind 처럼 인자를 값으로 받고 있습니다.
template<typename F, typename T> 
void valueForwarding(F f, T arg) 
{
	f(arg);
}

// reference_wrapper 를 만들어 주는 헬퍼 함수.
//"클래스 템플릿을 직접 만들게 하지 말고 
// 함수 템플릿으로 만들게 하자." => "Object Generator"
template<typename T> 
reference_wrapper<T> ref(T& obj)
{
	return reference_wrapper<T>(obj);
}


int main()
{
	int x = 0;
	//valueForwarding(&foo, x);

//	reference_wrapper<int> r(x);
//	valueForwarding(&foo, r); // ok..

	//valueForwarding(&foo, reference_wrapper<int>( x ) ); 

	valueForwarding(&foo, ref(x)); // ok.

	std::cout << x << std::endl;
}





