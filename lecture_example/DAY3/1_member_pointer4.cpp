// 1_member_pointer4
#include <iostream>

struct Point
{
	int x, y;
//	double z;
};
int main()
{
	// ��� ����Ÿ�� ���� ������
	int n = 0;
	int* p1 = &n;

	int Point::*p2 = &Point::y; // ����ü �ȿ��� y�� ��ġ(offset)
							// 4

	Point pt;
	pt.*p2 = 10; // *(((char*)&pt) + p2) = 10

	printf("%d\n", p2); // 4
	printf("%d\n", pt.y);// 10

	//p2 = p2 + 1; // error. ���� �ȵ�
}


