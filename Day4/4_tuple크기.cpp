#include <tuple>
#include <iostream>

struct Empty {};

int main()
{
	std::tuple<Empty, int> t1;
	std::cout << sizeof(t1) << std::endl; // 얼마 나올까요? 8(vc) - compressed , 4(g++) - 내부적으로 tuple로 보관
}