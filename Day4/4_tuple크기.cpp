#include <tuple>
#include <iostream>

struct Empty {};

int main()
{
	std::tuple<Empty, int> t1;
	std::cout << sizeof(t1) << std::endl; // �� ���ñ��? 8(vc) - compressed , 4(g++) - ���������� tuple�� ����
}