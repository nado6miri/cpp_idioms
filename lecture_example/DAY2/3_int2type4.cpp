#include <iostream>
#include <type_traits>

// 함수 오버로딩을 사용한 해결..

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
	// T가 포인터 인지에 따라 다른 함수를 호출하게 한다.
	printv_imp(a, std::is_pointer<T>::value  );
}


int main()
{
	int n = 0;
	printv(n);
}
