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
	Point pt;
	//std::cout << &pt; // pt.operator&()

//	char& c = pt;
//	char* pc = &c;

	//char* p = reinterpret_cast<char*>(&pt);// &pt�̹Ƿ�0
	//char* p = &(reinterpret_cast<char>(pt));// error. �� ĳ����

//	char* p = &(reinterpret_cast<char&>(pt));//

	Point* p = reinterpret_cast<Point*>(
			&(reinterpret_cast<char&>(pt)));//


	std::cout << p << std::endl; // �ּ� �������� ���ڵ�
							// ������ ������.
}




