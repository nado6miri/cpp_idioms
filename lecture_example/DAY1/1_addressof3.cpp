// 1_addressof1.cpp   7page
#include <iostream>

class Point
{
	int x, y;
public:
	// 주소를 나타낼때는 0대신 nullptr 을 사용하자 - C++11
	Point* operator&() const { return nullptr; }
};

template<typename T> 
T* addressof( T& obj)
{
//	return reinterpret_cast<T*>(
//		&(reinterpret_cast<char&>(
//			const_cast<T&>(obj))));
		// const_cast<const Point&>(obj)

	// 7page 아래 소스 : 2번째와 3번째 캐스팅 순서가 중요합니다.
	return reinterpret_cast<T*>(
				&(const_cast<char&>(
			reinterpret_cast<const volatile char&>(obj))));

}
int main()
{
	const Point pt;	
	// Point* p = addressof(pt); 

	const Point* p = std::addressof(pt);  // C++11 표준

				// T : const Point 입니다.

	std::cout << p << std::endl;
}



// 에러가 없도록 수정해 보세요.



