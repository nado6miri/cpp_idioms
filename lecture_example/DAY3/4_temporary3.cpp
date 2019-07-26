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

	// 함수 인자로 임시객체를 전달하는 경우가 많다.
	foo(Point(1, 2));

	//goo(std::is_pointer<T>());


	std::cout << "-------" << std::endl;
}







