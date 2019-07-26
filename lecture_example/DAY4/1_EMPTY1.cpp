// 1_EMPTY1 - 73 page
#include <iostream>

// empty class : non static 멤버 데이타가 없는 클래스
struct AAA
{
};
int main()
{
	AAA aaa;
	std::cout << sizeof(aaa) << std::endl; // 1
}