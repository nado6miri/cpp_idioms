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


void foo(const Point& p) {}

int main()
{
//	Point pt(1, 2);
//	foo(pt);

	// �Լ� ���ڷ� �ӽð�ü�� �����ϴ� ��찡 ����.
	foo(Point(1, 2));

	//goo(std::is_pointer<T>());


	std::cout << "-------" << std::endl;
}







