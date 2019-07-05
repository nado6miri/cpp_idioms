// 3 make

#include <iostream>
#include <memory>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}
};

int foo() { return 0; }

void goo(const std::unique_ptr<Point>& p, int n) {}

// unique_ptr을 만드는 함수
/*
template<typename T> std::unique_ptr<T> make_unique()
{
	return std::unique_ptr<T>(new T());
}
//모든 함수를 다 받기 위해 아래와 같이 변경함.
*/

template<typename T, typename ... ARGS> std::unique_ptr<T> make_unique(ARGS&& ... args)
{
	return std::unique_ptr<T>(new T(std::forward<ARGS>(args)...));
}

int main()
{
	// 아래 코드는 문제가 있을 수 있기 때문에 아래아래 코드 make_unique()를 만들어서 (메모리와 포인터 동시 생성) 사용하자.
	goo(std::unique_ptr<Point>(new Point(1, 2)), foo());
	 
	goo(make_unique<Point>(1, 2), foo());
	goo(std::make_unique<Point>(1, 2), foo());

	std::unique_ptr<Point> up = std::make_unique<Point>(1, 2);
}