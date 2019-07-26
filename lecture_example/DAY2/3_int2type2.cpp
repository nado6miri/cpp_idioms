#include <iostream>
#include <type_traits>
template<typename T> void printv(T a)
{
	if ( std::is_pointer<T>::value )  // if ( false )
		std::cout << a << " : " << *a << std::endl;
	else
		std::cout << a << std::endl;
}
int main()
{
	int n = 0;
	printv(n); // 1
	//printv(&n);// 2
}
// ? ä�� ������.  �� ������ �ϸ� �����ϱ�� ?
// 1, 2�� ������� ���� �ϱ�� ?