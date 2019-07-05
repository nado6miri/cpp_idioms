#include <iostream>

class Vector
{
public:
	explicit Vector(int size) { }
	explicit Vector(int size, int valule) { std::cout << "1" << std::endl; }
	Vector(std::initializer_list<int> s) { std::cout << "2" << std::endl; }
};


int main()
{
	// explicit�� �ְ� ���� ���� ����.
	Vector v1(10, 3);
	Vector v2{ 10, 3 }; // c++ 11���� ������. // ok 2�� ������ ȣ��, ������ 1�� ������ ȣ��
	Vector v3{ 10, 2, 4, 5, 6, 7 }; // 2�� ȣ���

	Vector v4 = 10; // error
	Vector v5 = { 10 }; // ok
}