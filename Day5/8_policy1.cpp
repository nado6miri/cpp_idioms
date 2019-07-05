// policy 183 page (Policy Clone)
// ���� ���� ������ (Policy base design)
// webkit �ҽ� "source/wtf/wtf/nolock.h"�� �������. class NoLock ����

#include <iostream>

// �������� s�� multi thread�� �������� �ʴ�. �׷� ����ȭ �ڵ带 class�� �ִ°� �����ų� �ȳִ� ���� �����ų�?
// ����  template���ڷ� ����ȭ ���ڸ� ����....
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

// ����ȭ ��å�� ���� ��å Ŭ������ �����մϴ�. - c++20������ concept���� ��� - ������ ������� �ʰ� 
struct nolock
{
	// �ƹ��͵� ���� ���� inline�Լ��� ������ �ܰ迡�� �����
	inline void lock() {}
	inline void unlock() {}
};

struct posix_mutex_lock
{
	inline void lock() {} // pthread_mutex_acquire();
	inline void unlock() {} // 
};

// ----------------------
// �������� s�� multi thread�� �������� �ʴ�. �׷� ����ȭ �ڵ带 class�� �ִ°� �����ų� �ȳִ� ���� �����ų�?
// ����  template���ڷ� ����ȭ ���ڸ� ����....
//List<int> s;
List<int, nolock> s;
int main()
{
	s.push_front(10);
}

