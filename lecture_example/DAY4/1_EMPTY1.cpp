// 1_EMPTY1 - 73 page
#include <iostream>

// empty class : non static ��� ����Ÿ�� ���� Ŭ����
struct AAA
{
};
int main()
{
	AAA aaa;
	std::cout << sizeof(aaa) << std::endl; // 1
}