#include <iostream>

//template<typename T> void foo(const T& f)
template<typename T> void foo(T&& f)
{
	//f();
	std::forward<T>(f)();
}

void goo() { std::cout << "goo" << std::endl; }

int main()
{
	foo(goo);
	// 람다 표현식은 rvalue 입니다.
	// mutable 람다 표현식 : () 연산자 함수를 비상수 멤버로 해달라는 의미임.
	foo([]() mutable { std::cout << "lambda" << std::endl;  });
}