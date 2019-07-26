#include <iostream>
#include <type_traits>

// ��� 3. if constexpr - C++17 ��Ÿ��.

// cppreference.com ���� invoke ã�� ������
// possible implementation ���� �غ�����.
template<typename T> void printv(T v)
{
	if constexpr ( std::is_pointer<T>::value )
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}


int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}
