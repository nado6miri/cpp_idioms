// EBCO - page 73 : Empty Base Class Optimization
// empty class�� ��� Ŭ������ �Ǹ� ũ�Ⱑ 1�� �ƴ� 0�� �ȴ�. unique_ptr�� �̰� �����.

#include <iostream>

class Empty {};

class AAA
{
	Empty a; // size 1 (4byte) �� ���
	int b;
};

// Empty�� ��ӹ����� ũ�Ⱑ 0��. - EBCO
class BBB : public Empty
{
	int b;
};


int main()
{
	std::cout << sizeof(AAA) << std::endl; // 8
	std::cout << sizeof(BBB) << std::endl; // 4
}