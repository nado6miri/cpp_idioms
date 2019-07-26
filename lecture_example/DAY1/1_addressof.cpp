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
	Point pt;
	//std::cout << &pt; // pt.operator&()

//	char& c = pt;
//	char* pc = &c;

	//char* p = reinterpret_cast<char*>(&pt);// &pt이므로0
	//char* p = &(reinterpret_cast<char>(pt));// error. 값 캐스팅

//	char* p = &(reinterpret_cast<char&>(pt));//

	Point* p = reinterpret_cast<Point*>(
			&(reinterpret_cast<char&>(pt)));//


	std::cout << p << std::endl; // 주소 나오도록 위코드
							// 수정해 보세요.
}




