#include <iostream>

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 복사 생성자 모양 1. call by value
	// 복사 생성자를 무한히 호출하는 표현 - error
	// Point(Point p) {} // Point p = p1

	// 2. 참조 사용
	// rvalue를 받을수 없다. 즉, 값을 반환하는 함수의 
	// 반환값을 받을수 없다.
	//Point(Point& p) {} // Point& p = p1

	// 3. const lvalue reference
	//    lvalue 와 rvalue를 모두 받을수 있다
	Point( const Point& p) 
	{
		std::cout << "lvalue일때. 복사 생성자" << std::endl;
	} 
	Point(Point&& p)
	{
		std::cout << "rvalue일때. Move 생성자" << std::endl;
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
	Point p3(p1); // Point(Point) 가 필요 하다.
	Point p4 =goo(); // Point p4( goo() );
}


