#include <iostream>

int main()
{
	int n1 = 10;
	int n2 = 20;
	int& r1 = n1;
	int& r2 = n2;

	// c++�� ������ const��. ���� ������ �̵����� �ʰ� ���� �̵���.
	r2 = r1; //  �� ������ �ǹ̸� ������ ������.

	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 10
	std::cout << r1 << std::endl; // 10
	std::cout << r2 << std::endl; // 10
}