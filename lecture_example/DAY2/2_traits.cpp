// 2_traits     115. int-To-Type ����
#include <iostream>

// Traits : ���ø� ���� T �� �پ��� Ư��(Traits)�� �����ϴ�
//          ���.
template<typename T> void printv(T v)
{
	if (T�� ������ ���)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}