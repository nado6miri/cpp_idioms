// 1_addressof1.cpp

#include <iostream>

class Point
{
	int x, y;
public :
	// �ּҸ� ��Ÿ������ 0 ��� nullptr�� ������� - c++11
	Point* operator&() const { return nullptr;  }
};

int main()
{
	Point pt;
	std::cout << &pt << std::endl; // pt.operator&(); ������ ������

	Point *p = &pt;
	std::cout << p << std::endl; // �ּ� �������� ������ ������.

	//char *p1 = reinterpret_cast<char*>(&pt); // &pt �� 0��
	//char *p1 = &(reinterpret_cast<char>(pt)); // error. �� casting�̱� ������... 
	//char *p1 = &(reinterpret_cast<char&>(pt));   
	Point *p2 = reinterpret_cast<Point*>(&(reinterpret_cast<char&>(pt)));
	std::cout << p2 << std::endl; // �ּ� �������� ������ ������.
}