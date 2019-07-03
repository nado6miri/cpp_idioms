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
	//Point(0, 0).x = 10; // 임시객체는 왼쪽에 올 수 없다. 임시객체는 rvalue 이다. error

	Point* p1 = &pt;  // 주소로 존재하기 때문에 ok
	//Point* p2 = &Point(0, 0); // 임시객체는 rvalue이고 rvalue 는 주소를 구할 수 없다. error

	Point& r1 = pt; // ok
	//Point& r2 = Point(0, 0); // 임시객체는 바로 사라지기 때문에 참조를 가리킬 수 없다. rvalue 는 주소를 구할 수 없다. error

	// const lvalue reference는 lvalue 와 rvalue를 모두 가리킨다.
	const Point& r3 = Point(0, 0); // 수명이 연장되었음. 바로 소멸 안됨.
	//r3.x = 

}