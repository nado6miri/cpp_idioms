#include <iostream>

struct Point
{
	int x;
	int y;
};
int main()
{
	int n = 0;
	int* p1 = &n;	 // ok.
	//int* p2 = &Point::y; // error 
	int Point::*p2 = &Point::y; // ok.. ��� �� �ּ�
								// pointer to member
	//std::cout << p2 << std::endl; // 4 �ǹ� �׷���, 1

	printf("%d\n", p2); // 4

	Point pt;
	pt.*p2 = 10; // �ᱹ p2.y = 10 �� ���� �ǹ�.
				// .* : pointer to member operator

	p2 = &Point::x;
	//p2 = p2 + 1; // 

}



