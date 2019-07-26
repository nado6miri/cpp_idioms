#include <iostream>
#include <type_traits>

// ������ ���ο� ���� �ٸ��� ó���ϴ� ���

// 1. C++17 �� ������ ������.
/*
template<typename T> void foo_imp(T v, true_type)  {}
template<typename T> void foo_imp(T v, false_type) {}

template<typename T> void foo(T v)
{
	// 1. is_pointer<T>::value ���
	if (std::is_pointer<T>::value)
	{
		// ��, �Ʒ��� ���� ǥ������ ����Ҽ� ����.
		//*v = 10; // error
	}
	else
	{
	}
	// 2. true_type/false_type�� ����� �����ε�
	//    foo_imp �ȿ����� *v = 10   ��밡��.
	foo_imp(v, is_pointer<T>() );
}
*/

// 2. enable_if ���

// 3. C++17 ���Ŀ��� 
// /std:c++17
// g++ : g++ �ҽ��̸�.cpp -std=c++17

template<typename T> void foo(T v)
{
	// if constexpr : ������ �ð� if ��
	// ������ ������ ��� �ڵ� ��ü�� �������� �ʴ´�.
	if constexpr (std::is_pointer<T>::value) {
		//*v = 10; 
		std::cout << v << " : " << *v << std::endl;
	}
	else {
		std::cout << v << std::endl;
	}
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}

