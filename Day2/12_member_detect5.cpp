#include <iostream>

// member variable detection

struct Point
{
	int x;
	int y;
};

int main()
{
	// Point�� ��ü�� �������� �ʾ���...���� Point�� ����ü���� offset �� ����.

	int n = 0;
	int* p1 = &n;  // OK
	//int* p2 = &Point::y;   // error
	int Point::*p2 = &Point::x;   // OK...  ����� x�ּ� -   pointer to member
	int Point::*p3 = &Point::y;   // OK...  ����� y�ּ� -   pointer to member

	std::cout << p2 << std::endl; // 0 �ǹ�, �׷��� 1�� ����. - cout�� ������� ����  printf�� ��� ����� ����
	printf("%d\n", p2); // 4

	std::cout << p3 << std::endl; // 4 �ǹ�, �׷��� 1�� ����. - cout�� ������� ����  printf�� ��� ����� ����
	printf("%d\n", p3); // 4

	Point pt;
	pt.*p2 = 10; // pt.x = 10�� ���� �ǹ���. - .* : pointer to member operator

}