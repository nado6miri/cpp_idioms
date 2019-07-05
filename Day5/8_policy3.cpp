#include <iostream>
#include <vector>


struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { std::cout << __FUNCSIG__ << std::endl; }
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	std::allocator<Point> ax;

	Point* p1 = ax.allocate(2); // 메모리 할당만
	ax.construct(&p1[0], 1, 2); // 생성자 호출
	ax.construct(&p1[1], 1, 2); // 생성자 호출

	ax.destroy(&p1[0]); // 소멸자 호출
	ax.destroy(&p1[1]); // 소멸자 호출

	ax.deallocate(p1, 2); // 메모리 해제

	// vector 는 내부적으로 allocator를 사용한다.
	//std::vector<
}

