#include <iostream>

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	Point pt(0, 0);
	pt.x = 10; //ok
	//Point(0, 0).x = 10; // �ӽð�ü�� ���ʿ� �� �� ����. �ӽð�ü�� rvalue �̴�. error

	Point* p1 = &pt;  // �ּҷ� �����ϱ� ������ ok
	//Point* p2 = &Point(0, 0); // �ӽð�ü�� rvalue�̰� rvalue �� �ּҸ� ���� �� ����. error

	Point& r1 = pt; // ok
	//Point& r2 = Point(0, 0); // �ӽð�ü�� �ٷ� ������� ������ ������ ����ų �� ����. rvalue �� �ּҸ� ���� �� ����. error

	// const lvalue reference�� lvalue �� rvalue�� ��� ����Ų��.
	const Point& r3 = Point(0, 0); // ������ ����Ǿ���. �ٷ� �Ҹ� �ȵ�.
	//r3.x = 

}