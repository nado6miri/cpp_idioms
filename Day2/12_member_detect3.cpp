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

//Point& declval(); // �ٽ� : ������ �����ϴ�.
template<typename T> T& declval(); // ���� ���ø�ȭ ��Ŵ.

int main()
{
	//int n = sizeof(Point().foo());  // Point().foo()�� default�����ڰ� ������ �Ҹ�. default������ Point(){}�� ������ �ȵ�.
	//int n = sizeof(declval().foo());  // �򰡵��� �ʴ� ��������, ������ �ȵǾ �������. �����Ͻ� �����.
	int n = sizeof(declval<Point>().foo());
	std::cout << n << std::endl;

	// �� ������ �̹� ǥ�ؿ� ���� ��
	n = sizeof(std::declval<Point>().foo()); // �򰡵��� ���� ���� �ִµ� - ���蹮��
	std::cout << n << std::endl;
}