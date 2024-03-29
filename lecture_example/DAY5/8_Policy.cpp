// 8_Policy   183p (Policy Clone)
// 단위 전략 디자인 (policy base design)
// webkit 소스 "source/wtf/wtf/nolock.h" 열어 보세요

template<typename T, typename ThreadModel = nolock > class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//...
		tm.unlock();
	}
};
// 동기화 정책을 담은 정책 클래스를 제공합니다.
struct nolock
{
	inline void lock() {}
	inline void unlock() {}
};
struct posix_mutex_lock
{
	inline void lock()   { } // pthread_mutex_acquire()
	inline void unlock() { }
};
//---------------------------------
List<int, nolock> s;    // 전역변수.   멀티스레드에 안전하지 않다.

int main()
{
	s.push_front(10);
}