#include <iostream>

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// ���� ������ ��� 1. call by value
	// ���� �����ڸ� ������ ȣ���ϴ� ǥ�� - error
	// Point(Point p) {} // Point p = p1

	// 2. ���� ���
	// rvalue�� ������ ����. ��, ���� ��ȯ�ϴ� �Լ��� 
	// ��ȯ���� ������ ����.
	//Point(Point& p) {} // Point& p = p1

	// 3. const lvalue reference
	//    lvalue �� rvalue�� ��� ������ �ִ�
	Point( const Point& p) 
	{
		std::cout << "lvalue�϶�. ���� ������" << std::endl;
	} 
	Point(Point&& p)
	{
		std::cout << "rvalue�϶�. Move ������" << std::endl;
	}

};

Point goo()
{
	Point pt;
	return pt;
}
int main()
{
	const Point p1;
	Point p2(1, 2);
	Point p3(p1); // Point(Point) �� �ʿ� �ϴ�.
	Point p4 =goo(); // Point p4( goo() );
}


