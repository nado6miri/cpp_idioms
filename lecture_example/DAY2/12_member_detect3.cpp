#include <iostream>
#include <type_traits>

class Point
{
	int x, y;
public:
	//Point() {}
	Point(int a, int b) : x(a), y(b) {}
	int foo() { return 0; }
};

//Point& declval();   // 핵심 : 구현이 없습니다.

template<typename T> T& declval();

int main()
{
//	int n = sizeof( Point().foo() ); // 반드시 Point에 
								// 디폴트 생성자가 있어야 한다.
//	int n = sizeof(declval().foo());
//	int n = sizeof(declval<Point>().foo());

	int n = sizeof(std::declval<Point>().foo());
}


