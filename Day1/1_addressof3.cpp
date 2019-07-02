// 1_addressof3.cpp

#include <iostream>

class Point
{
	int x, y;
public:
	// �ּҸ� ��Ÿ������ 0 ��� nullptr�� ������� - c++11
	Point* operator&() const { return nullptr; }
};

// 7page �Ʒ� �ҽ� : 2��°�� 3��° ĳ���� ������ �߿��մϴ�.
template<typename T>
T* addressof(T& obj)
{
	//return reinterpret_cast(<T*>(&(reinterpret_cast<char&>(const_cast<T&>(obj))))); //const_cast<const Point&>(obj)
	return reinterpret_cast(<T*>(&(const_cast<char&>(reinterpret_cast<const volatile char&>(obj)))));
}

int main()
{
	const Point pt;
	const Point *p = addressof(pt); // �� �̷����?
	std::cout << p << std::endl; // �ּ� �������� ������ ������.

	const Point *p1 = std::addressof(pt); // �� �̷����?
	std::cout << p1 << std::endl; // �ּ� �������� ������ ������.
}