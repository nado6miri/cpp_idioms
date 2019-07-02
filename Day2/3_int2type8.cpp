#include <iostream>
#include <type_traits>

// 포인터 여부에 따라 다르게 처리하는 방법

// 1. C++ 17 이 나오기 전까지 ..............
/*
template<typename T> void foo_imp(T v, true_type) {}
template<typename T> void foo_imp(T v, false_type) {}


template<typename T> void foo(T v);
{
	// 1. is_pointer<T>::value 사용
	if (std::is_pointer<T>::value)
	{
		// 단 아래와 같은 표현식은 사용할 수 없다.
		// *v = 10; // error.
	}
	else
	{

	}

	// 2. true_type / false_type을 사용한 overloading
	// foo_imp 안에서 *v = 10 사용가능
	foo_imp(v, is_pointer<T>());
}
*/

// 2. enable_if사용


// 3. C++17 이후에는 아래와 같이 constexpr 사용함.
// /std:c++17 - project - 속성 - 명령줄에 추가
// g++ : g++ sorce.cpp -std=c++17

template<typename T> void foo(T v)
{
	// if constexpr : 컴파일 시간 if문이 거짓일 경우 코드 자체를 생성하지 않는다. constexpr()안에 변수가 오면 안됨.
	if constexpr (std::is_pointer<T>::value)
	{
		*v = 10;
		std::cout << v << " : " << *v << std::endl;
	}
	else
	{
		std::cout << v << std::endl;
	}
}


int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}