// 4_temporary1
#include <iostream>

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0 ) : x(a), y(b) 
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};
int main()
{
	//Point p1(1, 2); // �̸� �ִ� ��ü. named object

	//Point(1, 2); // �ӽð�ü. unnamed object


	//Point(1, 2), std::cout << "X" << std::endl;

	//Point&& r = Point(1, 2);

	const Point& r = Point(1, 2);

	std::cout << "-------" << std::endl;
}




