// 1_addressof1.cpp   7page
#include <iostream>

class Point
{
	int x, y;
public:
	// �ּҸ� ��Ÿ������ 0��� nullptr �� ������� - C++11
	Point* operator&() const { return nullptr; }
};

template<typename T> 
T* addressof( T& obj)
{
//	return reinterpret_cast<T*>(
//		&(reinterpret_cast<char&>(
//			const_cast<T&>(obj))));
		// const_cast<const Point&>(obj)

	// 7page �Ʒ� �ҽ� : 2��°�� 3��° ĳ���� ������ �߿��մϴ�.
	return reinterpret_cast<T*>(
				&(const_cast<char&>(
			reinterpret_cast<const volatile char&>(obj))));

}
int main()
{
	const Point pt;	
	// Point* p = addressof(pt); 

	const Point* p = std::addressof(pt);  // C++11 ǥ��

				// T : const Point �Դϴ�.

	std::cout << p << std::endl;
}



// ������ ������ ������ ������.



