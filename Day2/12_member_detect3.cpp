#include <iostream>
#include <type_traits>
class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) : x(a), y(b) {}
	int foo() { return 0;  }
};

//Point& declval(); // 핵심 : 구현이 없습니다.
template<typename T> T& declval(); // 위를 템플릿화 시킴.

int main()
{
	//int n = sizeof(Point().foo());  // Point().foo()는 default생성자가 있을때 불림. default생성자 Point(){}를 막으면 안됨.
	//int n = sizeof(declval().foo());  // 평가되지 않는 구현식임, 구현이 안되어도 상관없음. 컴파일시 조사됨.
	int n = sizeof(declval<Point>().foo());
	std::cout << n << std::endl;

	// 위 내용은 이미 표준에 존재 함
	n = sizeof(std::declval<Point>().foo()); // 평가되지 않은 식이 있는데 - 시험문제
	std::cout << n << std::endl;
}