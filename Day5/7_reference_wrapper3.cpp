#include <iostream>
#include <functional>

// 그럼 std::reference_wrapper 를 사용하지 말고 직접 만들어 보자. - 포인터로 만들면 됨. 결국 참조가 포인터임.
template<typename T> class reference_wrapper
{
	T* ptr;
public:
	reference_wrapper(T& p) { ptr = &p; }

	// 변환 연산자 : 반환타입을 표기하지 않는 특징이 있다.
	// 객체가 다른 타입으로 변환되기 위해 필요함.
	operator T&() { return *ptr; }
	T& get() const { return *ptr; }
};

void foo(int& a) { a = 100; }

// 아래 함수가 bind처럼 인자를 값으로 받고 있습니다. perfect forwarding &&를 사용하지 않고...
template<typename F, typename T>
void valueForwarding(F f, T arg)
{
	f(arg);
}


// reference_wrapper를 만들어 주는 helper함수
// class template 을 직접 만들게 하지 말고 함수 템플릿으로 만들게 하자 ==> Object Generator !!
template<typename T> reference_wrapper<T> ref(T& obj)
{
	return reference_wrapper<T>(obj);
}


// reference wrapper는 주소를 가지고 있음.
int main()
{
	int x = 0;
	//valueForwarding(&foo, x);

	/*
	reference_wrapper<int> r(x);
	valueForwarding(&foo, r); // ok
	*/
	//valueForwarding(&foo, reference_wrapper<int>(x)); // 위 2줄과 동일함. 단지 임시객체를 만들었다는 차이점.
	valueForwarding(&foo, ref(x)); // 위 1줄을 helper로 만들었다.


	std::cout << x << std::endl;
}