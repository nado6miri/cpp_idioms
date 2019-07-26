//tuple크기
#include <tuple>
#include <iostream>


struct Empty {};

int main()
{
	std::tuple<Empty, int> t1;

	std::cout << sizeof(t1) << std::endl; // 얼마 나올까요 ?
					// g++ : 4,   vc++ : 8
}