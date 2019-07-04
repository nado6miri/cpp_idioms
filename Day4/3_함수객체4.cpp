#include <iostream>

template<typename T> void foo(T f)
{
	// lamda로 생성된 함수 이름 확인
	std::cout << __FUNCSIG__ << std::endl;
	f(1, 2);
};

int main()
{
	// C++ 람다 표현식 :
	// 아래 코드는 실제로 객체가 생성되고 이렇게 class가 생성됨. ()연산자 구현 - 함수객체 - 임시 함수객체를 만든다. 
	// 람다식으로 생성된 임시 객체는 defalut 생성자가 없다. 따라서 decltype(f) f2; 는 에러가 된다.
	// class xx { operator () (int, int) }; xx();
	foo([](int a, int b) { return a + b; });

	// 람다식 아래는 임시객체임. (1,2)를 붙이면 함수를 호출함.
	[](int a, int b) { return a + b; } (1, 2);

	auto f = [](int a, int b) { return a + b; }; 
	f(1, 2);

	auto& a1 = [](int a, int b) { return a + b; }; // 임시객체는 lvalue임 rvalue가 될 수 없음 - error
	const auto& a2 = [](int a, int b) { return a + b; }; // ok. const 는 받을 수 있음
	const auto&& a3 = [](int a, int b) { return a + b; }; // ok

	// 람다식으로 생성된 임시 객체는 defalut 생성자가 없다. 따라서 decltype(f) f2; 는 에러가 된다.
	decltype(f) f2; // 시험문제  error
	
	// 람다식으로 생성된 임시객체는 default 생성자는 없지만 복사 생성자는 있다. - 함수인자 T f = 람다표현식(); 이기 때문에 복사 생성자 필요 함.
	decltype(f) f3(f); // OK

	int n = 10;
	//int&& r = 10; // rvalue reference
	//T&& r = 함수인자 // forward reference
	//auto&& r = 우변; // forward reference 즉 auto는 T와 동일함.
	auto&& a5 = 10; //  int&& a5 = 10;
	auto&& a6 = n; // int& a6 = n;
}

// cppreference.com
// Closure 검색해 보세요.
// Closure : 람다 표현식이 만드는 임시 객체를 클로져라 합니다.
