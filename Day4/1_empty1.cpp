//73 page
#include <iostream>

// empty class : non static 멤버 데이타가 없는 class

struct AAA
{
	
};

int main()
{
	AAA aaa;
	std::cout << sizeof(aaa) << std::endl;  // empty class 의 크기는 1로 정의되어 있음. 4바이트
}
