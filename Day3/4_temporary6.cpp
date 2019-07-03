#include <iostream>

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		//std::cout << __FUNCSIG__ << std::endl;
	}

	// ���� ������ ��� 1. call by value
	// Point p = p1 ������ - ���� �����ڸ� ������ ȣ���ϴ� ǥ�� - error��.. 
	//Point(Point p) {} // error

	// 2. ���� ���
	// rvalue�� ���� �� ����. �� ���� ��ȯ�ϴ� �Լ��� ��ȯ��(�ӽð�ü)�� ���� �� ����.
	 //Point(Point& p) {} // Point&p = p1;

	 // 3. const lvalue reference : lvalue�� rvalue�� ��� ���� �� �ִ�.
	 Point(const Point& p) 
	 {
		 std::cout << "lvalue�϶� ���� ������" << std::endl;
	 }

	 Point(Point&& p) // rvalue�� ������ �켱������ �� �Լ��� ȣ���
	 {
		 std::cout << "rvalue�϶� Move ������" << std::endl;
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

	// move �������� ����... �����... �ӽð�ü�� ������� ���ѵ� �����Ҷ�...����� �ӽð�ü�� �׳� �����ϱ� ����...
	Point p3(p1); // Point(Point) �����ڰ� �ʿ���. �����Ϸ��� ���� �����ڸ� �ڵ����� ����� ��. ������ �츮�� ����� ����
	Point p4 = goo(); // �ӽð�ü(rvalue)�� �Ѿ�� Point p4(goo()); - error


}