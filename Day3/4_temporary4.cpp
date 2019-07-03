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

// call by value - copy�� ������
void foo(Point p) {} 

Point pt(0, 0);

// return by value - copy���� ��ȯ�ȴ�. - �ӽð�ü(�̸��� ����) return �� �ӽð�ü�� �������.
Point goo() { return pt; }

// return by value�� �ӽð�ü�� ������ ���� ������ �����϶�....
Point& hoo() { return pt; }

int main()
{
	//	Point p(1, 2);
	//	foo(p);
	goo(); // temporay �ӽ� ��ü�� �Ѿ��. ����  goo().x = 10�� �ϸ� error�߻�.
	//goo().x = 10 // error
	hoo().x = 10; // ok 

	std::cout << " ----- " << std::endl;
}