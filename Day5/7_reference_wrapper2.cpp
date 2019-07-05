#include <iostream>
#include <functional>

int main()
{
	int n1 = 10;
	int n2 = 20;
	std::reference_wrapper<int> r1 = n1;
	std::reference_wrapper<int> r2 = n2;

	// c++�� ������ const��. ���� ������ �̵����� �ʰ� ���� �̵���.
	// ������ reference_wrapper �� ����ϸ� reference�� �ٸ��� �� r2�� n2�� ����Ű�� �ʰ� n1 �� ����Ų��. �� �̵� ������ ���� !!!
	r2 = r1; //  �� ������ �ǹ̸� ������ ������.

	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 20
	std::cout << r1 << std::endl; // 10
	std::cout << r2 << std::endl; // 10

	r2.get() = 30;
	std::cout << n1 << std::endl; // ?
	std::cout << r2 << std::endl; // ?
}