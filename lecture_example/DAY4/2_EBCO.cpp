// 2_EBCO
#include <iostream>
// EBCO : Empty Base Class Optimization  73 page
// empty class �� ��� Ŭ������ �Ǹ� ũ�Ⱑ 0���� ���ȴ�.
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

