// 2_EBCO
#include <iostream>
// EBCO : Empty Base Class Optimization  73 page
// empty class 가 기반 클래스가 되면 크기가 0으로 계산된다.
class Empty {};

class AAA
{
	Empty a;
	int b;
};
class BBB : public Empty
{
	int b;
};
int main()
{
 	std::cout << sizeof(AAA) << std::endl; // 8
	std::cout << sizeof(BBB) << std::endl; // ?
}

