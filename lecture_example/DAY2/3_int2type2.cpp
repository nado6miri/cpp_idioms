#include <iostream>
#include <type_traits>
template<typename T> void printv(T a)
{
	if ( std::is_pointer<T>::value )  // if ( false )
		std::cout << a << " : " << *a << std::endl;
	else
		std::cout << a << std::endl;
}
int main()
{
	int n = 0;
	printv(n); // 1
	//printv(&n);// 2
}
// ? 채워 보세요.  왜 컴파일 하며 에러일까요 ?
// 1, 2중 어느곳이 문제 일까요 ?