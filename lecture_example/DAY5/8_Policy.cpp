// 8_Policy   183p (Policy Clone)
// ���� ���� ������ (policy base design)
// webkit �ҽ� "source/wtf/wtf/nolock.h" ���� ������

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
// ����ȭ ��å�� ���� ��å Ŭ������ �����մϴ�.
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
List<int, nolock> s;    // ��������.   ��Ƽ�����忡 �������� �ʴ�.

int main()
{
	s.push_front(10);
}