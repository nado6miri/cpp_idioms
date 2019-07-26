// 1_addressof1.cpp   7page
#include <iostream>

class Point
{
	int x, y;
public:
	// 주소를 나타낼때는 0대신 nullptr 을 사용하자 - C++11
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
// 에러가 없도록 수정해 보세요.



