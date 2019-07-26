// 8_enable_if3
#include <iostream>
#include <type_traits> // 이 안에 is_pointer 등의 traits와
					   // enable_if 도 있습니다.
// 포인터 일때만 사용할 템플릿
template<typename T> 
typename std::enable_if< std::is_pointer<T>::value >::type
printv(T v)
{
	std::cout << v << " : " << *v << std::endl;
}
// 포인터가 아닐때만 사용할 템플릿
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

