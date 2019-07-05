#include <iostream>
#include <type_traits>

/*
template<typename T> typename std::enable_if < std::is_pointer<T>::value, int>::type
foo(T a)
{
}
*/

// 위 코드를 _t와 _v버전을 사용해서 변경해 보세요.
// 1. 함수 반환파입을 이용한 SFINAE
template<typename T> 
std::enable_if_t < std::is_pointer_v<T>, int>
foo(T a)
{
	return 0;
}

// 2. 함수 인자를 사용한 SFINAE
template<typename T>
int 
goo(T a, std::enable_if_t < std::is_pointer_v<T>, int> = 0)
{
}

template<typename T, std::enable_if_t < std::is_pointer_v<T>, int> = 0>
int hoo(T a)
{
}


int main()
{

}