// 9_printv1

#include <iostream>
#include <type_traits>

// �и��� ��� 3���� ������. - ���� ���� ����ϴ� ���� enable_if�� ���� �����.

// ��� 1. true_type / false_type�� ����� �Լ� overloading....
template<typename T> void printv_imp(T v, std::true_type)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}


template<typename T> void printv_imp(T v, std::false_type)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}


template<typename T> void printv(T v)
{
	// T�� ������������ ���� �ٸ� �Լ��� ȣ���ϰ� �Ѵ�.
	// std::is_pointer<T>::value �� ���� true / false�̱� ������ type�� ���� �Լ� �����ε� �Ұ���. ���� int2type�� ����ؾ� ��.
	// int2type<0> �� type�̱� ������ �Լ� param���� ��� �Ұ���, ���� ()�� ���̰� �Ǹ� �ӽ� ��ü ���� - int2type<0>() : �ӽð�ü
	// is_pointer�� ���Ŭ������ true_type / false_type��.

	printv_imp(v, std::is_pointer<T>());
}

/*
// ��� 2.  enable_if�� ����ϴ� ���
// template�� �����ϱ� ������ if_enable�� ������ �ܰ迡�� ġȯ�� ����� ��.

// �������ϸ� ����� ���ø�
template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
printv(T v)
{
	std::cout << v << " : " << *v << std::endl;
}

// �����Ͱ� �ƴҶ� ����� ���ø�
template<typename T>
typename std::enable_if<!std::is_pointer<T>::value>::type
printv(T v)
{
	std::cout << v << std::endl;
}
*/

/*
// ��� 3. if constexpr - C++17 style - cppreference.com ���� invoke�� ã�� ������. possible implementation �� ã�ƺ�����.
template<typename T> void printv(T v)
{
	if constexpr (std::is_pointer<T>::value)
	{
		std::cout << v << ":" << *v << std::endl;
	}
	else
	{
		std::cout << v < , std::endl;
	}
}
*/

int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}