// policy 183 page (Policy Clone)
// 단위 전략 디자인 (Policy base design)
// webkit 소스 "source/wtf/wtf/nolock.h"를 열어보세요. class NoLock 참조

#include <iostream>

// 전역변수 s는 multi thread에 안전하지 않다. 그럼 동기화 코드를 class에 넣는게 좋을거냐 안넣는 것이 좋을거냐?
// 따라서  template인자로 동기화 인자를 받자....
template<typename T, typename ThreadModel = nolock> class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		// ...
		tm.unlock();
	}
};

// 동기화 정책을 담은 정책 클래스를 제공합니다. - c++20에서는 concept으로 사용 - 문서에 명시하지 않고 
struct nolock
{
	// 아무것도 하지 않은 inline함수는 컴파일 단계에서 사라짐
	inline void lock() {}
	inline void unlock() {}
};

struct posix_mutex_lock
{
	inline void lock() {} // pthread_mutex_acquire();
	inline void unlock() {} // 
};

// ----------------------
// 전역변수 s는 multi thread에 안전하지 않다. 그럼 동기화 코드를 class에 넣는게 좋을거냐 안넣는 것이 좋을거냐?
// 따라서  template인자로 동기화 인자를 받자....
//List<int> s;
List<int, nolock> s;
int main()
{
	s.push_front(10);
}

