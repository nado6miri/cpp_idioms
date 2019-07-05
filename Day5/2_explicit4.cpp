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
	// explicit를 넣고 빼고 비교해 보자.
	Vector v1(10, 3);
	Vector v2{ 10, 3 }; // c++ 11부터 가능함. // ok 2번 생성자 호출, 없으면 1번 생성자 호출
	Vector v3{ 10, 2, 4, 5, 6, 7 }; // 2번 호출됨

	Vector v4 = 10; // error
	Vector v5 = { 10 }; // ok
}