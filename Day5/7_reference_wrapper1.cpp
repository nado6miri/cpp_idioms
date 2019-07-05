#include <iostream>

int main()
{
	int n1 = 10;
	int n2 = 20;
	int& r1 = n1;
	int& r2 = n2;

	// c++의 참조는 const임. 따라서 참조가 이동하지 않고 값이 이동함.
	r2 = r1; //  이 한줄의 의미를 생각해 보세요.

	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 10
	std::cout << r1 << std::endl; // 10
	std::cout << r2 << std::endl; // 10
}