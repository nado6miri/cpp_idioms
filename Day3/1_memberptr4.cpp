#include<iostream>


struct Point
{
	int x, y;
};

int main()
{
	// 멤버 데이터를 위한 포인터
	int n = 0;
	int* p1 = &n;
	int Point::*p2 = &Point::y; // 구조체 안에서 y의 위치(offset)

	Point pt;
	pt.*p2 = 10;				// *(((char*)&pt) + p2) = 10
	printf("%d\n", p2);  // 4;
	printf("%d\n", pt.y); // 10;

	// error - 덧셈 안됨 type이 다를 경우에 문제 발생 int -> double...
	// p2 = p2 + 1;
}