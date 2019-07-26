// 9_printv1
#include <iostream>
#include <type_traits>

// ��� 1. true_type/false_type�� ����� �Լ� �����ε�

template<typename T> void printv_imp(T v, std::true_type)
{
	std::cout << v << " : " << *v << std::endl;
}
template<typename T> void printv_imp(T v, std::false_type)
{
	std::cout << v << std::endl;
}

template<typename T> void printv(T v)
{
	printv_imp(v, std::is_pointer<T>());
}
int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}
