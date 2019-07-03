#include <iostream>

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		//std::cout << __FUNCSIG__ << std::endl;
	}

	// 복사 생성자 모양 1. call by value
	// Point p = p1 형태임 - 복사 생성자를 무한히 호출하는 표현 - error임.. 
	//Point(Point p) {} // error

	// 2. 참조 사용
	// rvalue를 받을 수 없다. 즉 값을 반환하는 함수의 반환값(임시객체)을 받을 수 없다.
	 //Point(Point& p) {} // Point&p = p1;

	 // 3. const lvalue reference : lvalue와 rvalue를 모두 받을 수 있다.
	 Point(const Point& p) 
	 {
		 std::cout << "lvalue일때 복사 생성자" << std::endl;
	 }

	 Point(Point&& p) // rvalue를 보내면 우선순위상 이 함수가 호출됨
	 {
		 std::cout << "rvalue일때 Move 생성자" << std::endl;
	 }

	//~Point() { std::cout << __FUNCSIG__ << std::endl; }
};


Point goo()
{
	Point pt;
	return pt;
}


int main()
{
	Point p1;
	Point p2(1, 2);

	// move 생성자의 시초... 복사시... 임시객체가 사라질거 뻔한데 복사할때...사라질 임시객체를 그냥 재사용하기 위함...
	Point p3(p1); // Point(Point) 생성자가 필요함. 컴파일러가 복사 생성자를 자동으로 만들어 줌. 하지만 우리가 만들어 보자
	Point p4 = goo(); // 임시객체(rvalue)가 넘어옴 Point p4(goo()); - error


}