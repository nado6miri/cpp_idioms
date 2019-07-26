// 4_temporary1
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
// call by value : ���� ���� ���� �ȴ�
void foo(Point p) {}

Point pt(0, 0);

// return by value : ���� ���� ��ȯ �ȴ�.
//        ���Ͽ� �ӽð�ü ����
Point  goo() { return pt; } 
Point& hoo() { return pt; } // �ӽð�ü�� ������ ����� �ǵ�.

int main()
{
//	Point p(1, 2);
//	foo(p);

//	goo().x = 10; // error. return value�̹Ƿ� �ӽð�ü �̴�.
	hoo().x = 10; // ok.. 

	std::cout << "-------" << std::endl;
}







