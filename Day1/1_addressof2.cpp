// 1_addressof2.cpp

#include <iostream>

class Point
{
	int x, y;
public:
	// 주소를 나타낼때는 0 대신 nullptr을 사용하자 - c++11
	Point* operator&() const { return nullptr; }
};

int main()
{
	const Point pt;
	Point *p = reinterpret_cast<Point*>(&(reinterpret_cast<char&>(const_cast<Point&>(pt))));
	std::cout << p << std::endl; // 주소 나오도록 수정해 보세요.
}