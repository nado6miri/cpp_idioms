// 1_addressof1.cpp   7page
#include <iostream>

class Point
{
	int x, y;
public:
	// �ּҸ� ��Ÿ������ 0��� nullptr �� ������� - C++11
	Point* operator&() const { return nullptr; }
};

int main()
{
	//Point pt;

	const Point pt;
	
	Point* p = reinterpret_cast<Point*>(
		&(reinterpret_cast<char&>(
			const_cast<Point&>(pt))));


	std::cout << p << std::endl;
}
// ������ ������ ������ ������.



