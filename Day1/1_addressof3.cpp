// 1_addressof3.cpp

#include <iostream>

class Point
{
	int x, y;
public:
	// 주소를 나타낼때는 0 대신 nullptr을 사용하자 - c++11
	Point* operator&() const { return nullptr; }
};

// 7page 아래 소스 : 2번째와 3번째 캐스팅 순서가 중요합니다.
template<typename T>
T* addressof(T& obj)
{
	//return reinterpret_cast(<T*>(&(reinterpret_cast<char&>(const_cast<T&>(obj))))); //const_cast<const Point&>(obj)
	return reinterpret_cast(<T*>(&(const_cast<char&>(reinterpret_cast<const volatile char&>(obj)))));
}

int main()
{
	const Point pt;
	const Point *p = addressof(pt); // 왜 이럴까요?
	std::cout << p << std::endl; // 주소 나오도록 수정해 보세요.

	const Point *p1 = std::addressof(pt); // 왜 이럴까요?
	std::cout << p1 << std::endl; // 주소 나오도록 수정해 보세요.
}