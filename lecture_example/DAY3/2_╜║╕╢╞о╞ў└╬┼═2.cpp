// 2_스마트포인터2
#include <iostream>
#include <memory>

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};
// 메모리 할당에 사용되는 operator new() 함수를 재정의 할수 있습니다.
void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
	//std::shared_ptr<Point> sp(new Point);

	// sizeof(Point) + sizeof(관리객체)를 한번에 메모리 할당.
	std::shared_ptr<Point> sp = std::make_shared<Point>(1,2);					
}

// make_shared의 원리
template<typename T, typename ... Types> 
shared_ptr<T> make_shared(Types&& ... args)
{
	// 1. 메모리 할당 
	void* p = operator new(sizeof(T) + sizeof(12)); 
					// 관리객체의 크기를 12라고 가정.

	// 2. 메모리 윗쪽에 놓인 객체에 대해서 생성자 호출
	new(p) T(std::forward<Types>(args)...); // C++11 완벽한전달

	// 3. 관리 객체 초기화

	// 4. shared_ptr을 만들어서 반환

	char* p2 = static_cast<char*>(p);

	std::shared_ptr<T> sp;
	sp._reset(static_cast<T*>(p2),  // 객체 주소
				p2 + sizeof(T));   // 관리객체 주소

	return sp;
	
}





