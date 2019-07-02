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
	// mallock : 메모리만 할당
	// new : 메모리 할당 + 생성자 호출
	// delete p1; 소멸자 호출 후 메모리 해지함.
	Point* p1 = new Point(0, 0);  

	// 메모리 할당과 생성자 호출의 분리
	// 1. 메모리 할당만 - malloc과 유사함. malloc  및  operator new()도 반환값이 void *임
	//Point* p2 = operator new(sizeof(Point));
	Point* p2 = static_cast<Point*> (operator new(sizeof(Point)));
	std::cout << "할당된 주소 : " << p2 << std::endl;

	// 2. 할당된 메모리에 생성자 호출 - new(ptr) 넘겨진 ptr 에 우측 함수를 호출해라.
	new(p2) Point(0, 0); // 시험문제

	// 메모리 할당과 생성자 호출을 분리 했다면 소멸자 호출과 메모리 호출도 분리필요.
	// 3. 소멸자 호출
	p2->~Point(); 
	// 4. 메모리 해지
	operator delete(p2); 
}