// 8_enable_if3
#include <iostream>
#include <type_traits>

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

int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}