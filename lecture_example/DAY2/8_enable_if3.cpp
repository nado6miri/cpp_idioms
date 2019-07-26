// 8_enable_if3
#include <iostream>
#include <type_traits> // �� �ȿ� is_pointer ���� traits��
					   // enable_if �� �ֽ��ϴ�.
// ������ �϶��� ����� ���ø�
template<typename T> 
typename std::enable_if< std::is_pointer<T>::value >::type
printv(T v)
{
	std::cout << v << " : " << *v << std::endl;
}
// �����Ͱ� �ƴҶ��� ����� ���ø�
template<typename T>
typename std::enable_if< !std::is_pointer<T>::value >::type
printv(T v)
{
	std::cout << v << std::endl;
}

int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}

