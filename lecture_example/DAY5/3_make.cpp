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
	// �Ʒ� ������ �����ұ�� ? �������� ã�� ������
	// �Ʒ� ó�� ����Ǹ� �������߻��Ҽ� �ֽ��ϴ�.
	// 1. new Point(1,2) 
	// 2. foo()		=> ���⼭ ���ܰ� ������ 1�� �ڵ尡 �޸� ����
	// 3. unique_ptr ����
	goo(std::unique_ptr<Point>(new Point(1, 2)), foo());
}



