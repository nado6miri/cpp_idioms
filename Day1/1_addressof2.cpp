// 1_addressof2.cpp

#include <iostream>

class Point
{
	int x, y;
public:
	// �ּҸ� ��Ÿ������ 0 ��� nullptr�� ������� - c++11
	Point* operator&() const { return nullptr; }
};

int main()
{
	const Point pt;
	Point *p = reinterpret_cast<Point*>(&(reinterpret_cast<char&>(const_cast<Point&>(pt))));
	std::cout << p << std::endl; // �ּ� �������� ������ ������.
}