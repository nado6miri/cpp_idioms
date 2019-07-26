#include <iostream>
#include <type_traits>

// �Լ� �����ε��� ����� �ذ�..

template<typename T> void printv_imp(T v, YES )
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void printv_imp(T v, NO)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}

template<typename T> void printv(T a)
{
	// T�� ������ ������ ���� �ٸ� �Լ��� ȣ���ϰ� �Ѵ�.
	printv_imp(a, std::is_pointer<T>::value  );
}


int main()
{
	int n = 0;
	printv(n);
}
