// 3_함수객체4
#include <iostream>

// cppreference.com
// Closure 검색해보세요
// Closure : 람다표현식이 만드는 임시객체를 클로져 라고 합니다.
template<typename T> void foo(T f)  //T f = 람다표현식()
{
	std::cout << __FUNCSIG__ << std::endl;
	f(1, 2);
}
int main()
{
	// C++11 람다표현식 : 
	foo( [](int a, int b) {return a + b; } );
	// class xx{ int operator()(int, int) }; xx();

	[](int a, int b) {return a + b; }(1, 2);
			// 람다표현식이만든임시객체(1, 2);

	auto f = [](int a, int b) {return a + b; };
			// class xx{operator()}; xx();
	f(1, 2);

	auto&       a1 = [](int a, int b) {return a + b; }; // 1 error
	const auto& a2 = [](int a, int b) {return a + b; }; // 2 ok
	auto&&      a3 = [](int a, int b) {return a + b; }; // 3 ok

	decltype(f) f2; // error. 람다표현식이 만드는 클래스에는
					//        디폴트 생성자를 사용할수 없습니다.

	decltype(f) f3(f); // ok.. 복사 생성자는 있습니다.



	int n = 10;
	// int&& r  = 10;      rvalue reference
	// T&& r    = 함수인자; forwarding reference
	// auto&& r = 우변;     forwarding reference

	auto&& a5 = 10; // int&& a5 = 10
	auto&& a6 = n;  // int&  a6 = n
}








