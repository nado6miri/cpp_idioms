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

//Point& declval();   // �ٽ� : ������ �����ϴ�.

template<typename T> T& declval();

int main()
{
//	int n = sizeof( Point().foo() ); // �ݵ�� Point�� 
								// ����Ʈ �����ڰ� �־�� �Ѵ�.
//	int n = sizeof(declval().foo());
//	int n = sizeof(declval<Point>().foo());

	int n = sizeof(std::declval<Point>().foo());
}


