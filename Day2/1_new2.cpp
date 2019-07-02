// "android source github
// 1_new1.cpp
// platform_system_core/libutils/include/utilstypeHelpers.h

#include<iostream>
// page 103
// 핵심 1. new의 2가지 사용법
// new Point(1,1) : 메모리 할당 후 생성자 호출 -  opensource에서 사용안함. 문제가 있음 - 따라서 분리해서 사용함.
// new(p) Point(1,1) : 이미 존재하는 메모리(주소 p)에 생성자 호출 -   placement new (위치지정 new)

// 핵심 2. 생성자 없이 메모리만 할당하는 방법
// operator new(메모리 크기)

// 핵심 3.
// delete p1 ; 소멸자 호출, 메모리 해지
// operator delete(p1) ; 메모리만 해지함.

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}
};

int main()
{
	//1. 0, 0으로 초기화된 Point 를 힙에 한개 만들어 보세요.
	Point* p1 = new Point(0, 0);

	//2. 0, 0으로 초기화된 Point를 힙에 10개 만들어 보세요.
	// 위 class에서 default생성자가 없어 사용할 수가 없음. 따라서 분리하면 가능함.
	//Point*p2 = new Point[10];

	//3. 메모리 할당과 생성자 호출을 분리하면 항상 편리하다.
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10)); // 메모리 공간만 할당함.

	// 4. 10개의 메모리에 대해 생성자 호출
	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0);
	}

	// 사용후에는 소멸자 호출
	for (int i = 0; i < 10; i++)
	{
		p2[i].~Point();
	}

	// 사용후 메모리 해제
	operator delete(p2);
}