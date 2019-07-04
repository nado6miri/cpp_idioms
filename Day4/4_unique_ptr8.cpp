#include <iostream>
#include <memory>

// c++ 표준을 쓰자
int main()
{
	std::unique_ptr<int> p1(new int);
	std::unique_ptr<int[]> p2(new int[10]);

	//p1[0] = 10; // error
	*p1 = 10; // ok
	p2[0] = 10; // ok
	// *p2 = 10; // error - 배열일 경우 역참조 못하게 해 놨음
}