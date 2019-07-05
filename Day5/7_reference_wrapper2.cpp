#include <iostream>
#include <functional>

int main()
{
	int n1 = 10;
	int n2 = 20;
	std::reference_wrapper<int> r1 = n1;
	std::reference_wrapper<int> r2 = n2;

	// c++의 참조는 const임. 따라서 참조가 이동하지 않고 값이 이동함.
	// 하지만 reference_wrapper 를 사용하면 reference가 다른곳 즉 r2는 n2를 가리키지 않고 n1 을 가리킨다. 즉 이동 가능한 참조 !!!
	r2 = r1; //  이 한줄의 의미를 생각해 보세요.

	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 20
	std::cout << r1 << std::endl; // 10
	std::cout << r2 << std::endl; // 10

	r2.get() = 30;
	std::cout << n1 << std::endl; // ?
	std::cout << r2 << std::endl; // ?
}