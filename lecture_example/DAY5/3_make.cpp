// 3_make
#include <iostream>
#include <memory>
class Point
{
	int x, y;
public:
	Point( int a, int b) { }
};

int foo() { return 0; }

void goo(const std::unique_ptr<Point>& p, int n) {}

int main()
{
	// 아래 한줄은 안전할까요 ? 문제점을 찾아 보세요
	// 아래 처럼 실행되면 문제가발생할수 있습니다.
	// 1. new Point(1,2) 
	// 2. foo()		=> 여기서 예외가 나오면 1의 코드가 메모리 누수
	// 3. unique_ptr 생성
	goo(std::unique_ptr<Point>(new Point(1, 2)), foo());
}



