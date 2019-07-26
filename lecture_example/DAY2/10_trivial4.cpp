// 10_trivial4
#define _ENABLE_ATOMIC_ALIGNMENT_FIX
#include <iostream>
#include <atomic>

struct Point
{
	int x, y, z;

	Point() {}

	// 사용자가 제공한 복사 생성자
	Point(const Point& p) : x(p.x), y(p.y), z(p.z) {}

};
std::atomic<int> an;
std::atomic<Point> ap;

int main()
{
	int n = an.load(); // 멀티 스레드에 안전하게 load.

	Point pt = ap.load(); // 멀티스레드에 안전합니다.
						// 하지만 lock free가 아닌
						// 내부적인 동기화 기법을 사용합니다.
						// 대부분 "busy waiting" 합니다.

	std::cout << an.is_lock_free() << std::endl; // 1
	std::cout << ap.is_lock_free() << std::endl; // ?





	/*
	// n = n + 1 의 어셈
	__asm
	{
		mov eax, n
		add eax, 1
		mov n, eax
	}
	// 멀티스레드에 안전하게 1증가
	// 인텔 계열 CPU는 lock prefix 사용.
	// lock free : OS 의 lock 을 사용하지 않는다는 의미
	__asm
	{
		lock inc n
	}
	*/
}


