//tupleũ��
#include <tuple>
#include <iostream>


struct Empty {};

int main()
{
	std::tuple<Empty, int> t1;

	std::cout << sizeof(t1) << std::endl; // �� ���ñ�� ?
					// g++ : 4,   vc++ : 8
}