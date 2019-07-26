// 2_traits     115. int-To-Type 관련
#include <iostream>

// Traits : 템플릿 인자 T 의 다양한 특질(Traits)를 조사하는
//          기술.
template<typename T> void printv(T v)
{
	if (T가 포인터 라면)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}