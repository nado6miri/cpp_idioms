#include <iostream>
#include <type_traits>

// 아래 int2type을 발전시켜서 C++11 표준에 추가했습니다.
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
	// T가 포인터 인지에 따라 다른 함수를 호출하게 한다.

	printv_imp(a, int2type< std::is_pointer<T>::value >() );
					// int2type<0> :타입
					// int2type<0>() : 임시객체
}


int main()
{
	int n = 0;
	printv(n);
}
