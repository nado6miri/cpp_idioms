// EBCO - page 73 : Empty Base Class Optimization
// empty class가 기반 클래스가 되면 크기가 1이 아닌 0이 된다. unique_ptr이 이걸 사용함.

#include <iostream>

class Empty {};

class AAA
{
	Empty a; // size 1 (4byte) 로 계산
	int b;
};

// Empty를 상속받으면 크기가 0임. - EBCO
class BBB : public Empty
{
	int b;
};


int main()
{
	std::cout << sizeof(AAA) << std::endl; // 8
	std::cout << sizeof(BBB) << std::endl; // 4
}