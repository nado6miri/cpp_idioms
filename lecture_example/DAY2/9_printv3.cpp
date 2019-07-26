#include <iostream>
#include <type_traits>

// 방법 3. if constexpr - C++17 스타일.

// cppreference.com 에서 invoke 찾아 보세요
// possible implementation 참고 해보세요.
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
