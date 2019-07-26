#include <iostream>
#include <type_traits>

// �Ʒ� int2type�� �������Ѽ� C++11 ǥ�ؿ� �߰��߽��ϴ�.
template<int N> struct int2type   
{
	enum { value = N };
};

template<typename T> void printv_imp(T v, int2type<1> )
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void printv_imp(T v, int2type<0>)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}

template<typename T> void printv(T a)
{
	// T�� ������ ������ ���� �ٸ� �Լ��� ȣ���ϰ� �Ѵ�.

	printv_imp(a, int2type< std::is_pointer<T>::value >() );
					// int2type<0> :Ÿ��
					// int2type<0>() : �ӽð�ü
}


int main()
{
	int n = 0;
	printv(n);
}
