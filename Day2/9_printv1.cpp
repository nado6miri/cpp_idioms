// 9_printv1

#include <iostream>
#include <type_traits>

// 분리할 방법 3가지 존재함. - 가장 많이 사용하는 것이 enable_if를 많이 사용함.

// 방법 1. true_type / false_type을 사용한 함수 overloading....
template<typename T> void printv_imp(T v, std::true_type)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}


template<typename T> void printv_imp(T v, std::false_type)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}


template<typename T> void printv(T v)
{
	// T가 포인터인지에 따라 다른 함수를 호출하게 한다.
	// std::is_pointer<T>::value 의 값은 true / false이기 때문에 type이 같아 함수 오버로딩 불가함. 따라서 int2type을 사용해야 함.
	// int2type<0> 은 type이기 때문에 함수 param으로 사용 불가능, 따라서 ()를 붙이게 되면 임시 객체 생성 - int2type<0>() : 임시객체
	// is_pointer의 기반클래스는 true_type / false_type임.

	printv_imp(v, std::is_pointer<T>());
}

/*
// 방법 2.  enable_if를 사용하는 방법
// template이 동일하기 때문에 if_enable로 컴파일 단계에서 치환시 빼줘야 함.

// 포인터일만 사용할 템플릿
template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
printv(T v)
{
	std::cout << v << " : " << *v << std::endl;
}

// 포인터가 아닐때 사용할 템플릿
template<typename T>
typename std::enable_if<!std::is_pointer<T>::value>::type
printv(T v)
{
	std::cout << v << std::endl;
}
*/

/*
// 방법 3. if constexpr - C++17 style - cppreference.com 에서 invoke를 찾아 보세요. possible implementation 을 찾아보세요.
template<typename T> void printv(T v)
{
	if constexpr (std::is_pointer<T>::value)
	{
		std::cout << v << ":" << *v << std::endl;
	}
	else
	{
		std::cout << v < , std::endl;
	}
}
*/

int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}