// 3 make

#include <iostream>
#include <memory>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}
};

int foo() { return 0;  }

void goo(const std::unique_ptr<Point>& p, int n) {}

int main()
{
	// 아래 한줄은 안전할까요? 문제점을 찾아보세요.
	// 아래  param을 생성하는 순서가 표준에 명시되어 있지 않음. Point 생성후 foo() 생성 후 unique_ptr 생성 순서로 될 경우
	// Point malloc 후 foo에서 exception이 발생하면 unique_ptr이 안만들어 진 상태이기 때문에 메모리 해제를 할 수 없다. 메모리 누수 발생 가능성
	// new Point(1,2) --> foo() --> unique_ptr 생성
	goo(std::unique_ptr<Point>(new Point(1, 2)), foo());
}