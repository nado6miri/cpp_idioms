#include<iostream>

//C++ 부터 다양한 traits를 표준에서 제공합니다.
#include<type_traits>

int main()
{
	std::cout << std::is_reference<int>::value << std::endl; // 0
	std::cout << std::is_reference<int&>::value << std::endl; // 1
	std::cout << std::is_const<int>::value << std::endl; // 0
	std::cout << std::is_const<const int>::value << std::endl; // 1
}