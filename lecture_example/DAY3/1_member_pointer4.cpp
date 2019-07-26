// 1_member_pointer4
#include <iostream>

struct Point
{
	int x, y;
//	double z;
};
int main()
{
	// 멤버 데이타를 위한 포인터
	int n = 0;
	int* p1 = &n;

	int Point::*p2 = &Point::y; // 구조체 안에서 y의 위치(offset)
							// 4

	Point pt;
	pt.*p2 = 10; // *(((char*)&pt) + p2) = 10

	printf("%d\n", p2); // 4
	printf("%d\n", pt.y);// 10

	//p2 = p2 + 1; // error. 덧셈 안됨
}


