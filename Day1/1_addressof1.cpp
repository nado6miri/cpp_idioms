// 1_addressof1.cpp

#include <iostream>

class Point
{
	int x, y;
public :
	// 주소를 나타낼때는 0 대신 nullptr을 사용하자 - c++11
	Point* operator&() const { return nullptr;  }
};

int main()
{
	Point pt;
	std::cout << &pt << std::endl; // pt.operator&(); 연산재 재정의

	Point *p = &pt;
	std::cout << p << std::endl; // 주소 나오도록 수정해 보세요.

	//char *p1 = reinterpret_cast<char*>(&pt); // &pt 가 0임
	//char *p1 = &(reinterpret_cast<char>(pt)); // error. 값 casting이기 때문에... 
	//char *p1 = &(reinterpret_cast<char&>(pt));   
	Point *p2 = reinterpret_cast<Point*>(&(reinterpret_cast<char&>(pt)));
	std::cout << p2 << std::endl; // 주소 나오도록 수정해 보세요.
}