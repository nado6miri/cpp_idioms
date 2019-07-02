#include<iostream>

//C++ ���� �پ��� traits�� ǥ�ؿ��� �����մϴ�.
#include<type_traits>

int main()
{
	std::cout << std::is_reference<int>::value << std::endl; // 0
	std::cout << std::is_reference<int&>::value << std::endl; // 1
	std::cout << std::is_const<int>::value << std::endl; // 0
	std::cout << std::is_const<const int>::value << std::endl; // 1
}