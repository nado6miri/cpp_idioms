#include<iostream>


struct Point
{
	int x, y;
};

int main()
{
	// ��� �����͸� ���� ������
	int n = 0;
	int* p1 = &n;
	int Point::*p2 = &Point::y; // ����ü �ȿ��� y�� ��ġ(offset)

	Point pt;
	pt.*p2 = 10;				// *(((char*)&pt) + p2) = 10
	printf("%d\n", p2);  // 4;
	printf("%d\n", pt.y); // 10;

	// error - ���� �ȵ� type�� �ٸ� ��쿡 ���� �߻� int -> double...
	// p2 = p2 + 1;
}