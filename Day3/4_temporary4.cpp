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

// call by value - copy본 생성됨
void foo(Point p) {} 

Point pt(0, 0);

// return by value - copy본이 반환된다. - 임시객체(이름이 없음) return 용 임시객체가 만들어짐.
Point goo() { return pt; }

// return by value로 임시객체를 만들지 말고 참조를 전달하라....
Point& hoo() { return pt; }

int main()
{
	//	Point p(1, 2);
	//	foo(p);
	goo(); // temporay 임시 객체가 넘어옴. 따라서  goo().x = 10을 하면 error발생.
	//goo().x = 10 // error
	hoo().x = 10; // ok 

	std::cout << " ----- " << std::endl;
}