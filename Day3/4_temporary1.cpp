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
	//Point p1(1, 2); // 이름있는 객체. named object
	//Point(1, 2);	// 임시객체. unnamed object
	//Point(1, 2), std::cout << "X" << std::endl; // 임시객체는 문장 끝 ; 에서 소멸자가 호출되었기 때문에 "X" 표시 후 소멸자 호출됨.
	//Point&& r = Point(1, 2); // 임시객체에 reference로 이름을 부여 했기 때문에  {} 벗어나면 소멸자 호출됨.
	const Point& r = Point(1, 2); // 
	std::cout << "---" << std::endl;
}