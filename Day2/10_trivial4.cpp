// 10_trivial4
#define _ENABLE_ATOMIC_ALIGNMENT_FIX
#include<iostream>
#include<atomic>


struct Point
{
	//int x, y;	// lock_free : 1   - 64bit까지
	int x, y, Z; // lock_free : 0   - 64bit 넘어감.

	// 사용자가 제공한 복사 생성자
	//복사생성자가 trivial할때 atomic을 사용할 수 있다. - 따라서 아래 코드 없애야 함. 안만들어도 됨
	//Point() {}
	//Point(const Point& p) : x(p.x), y(p.y), z(p.z) {}
};

std::atomic<int> an;
std::atomic<Point> ap;

int main()
{
	//멀티 스레드에서 안전하게 load...
	int n = an.load(); 

	// 멀티스레드에 안전합니다. 하지만 lock free가 아닌 내부적인 동기화 기법을 사용합니다.
	Point pt = ap.load(); 

	std::cout << an.is_lock_free() << std::endl;
	std::cout << ap.is_lock_free() << std::endl;

	/*
	// n = n+1
	__asm
	{
		mov eax, n
		add eax, 1
		move n, eax
	}

	// 멀티스레드에서 안전하게 1증가 - 인텔 계열 cpu는 lock prefix 사용.
	__asm
	{
		// lock free : os의  lock 을 쓰지 않고 cpu의 lock을 사용(mutex, sema 사용하지 않음)
		lock inc n
	}
	*/
}