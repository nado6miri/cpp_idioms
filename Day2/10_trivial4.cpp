// 10_trivial4
#define _ENABLE_ATOMIC_ALIGNMENT_FIX
#include<iostream>
#include<atomic>


struct Point
{
	//int x, y;	// lock_free : 1   - 64bit����
	int x, y, Z; // lock_free : 0   - 64bit �Ѿ.

	// ����ڰ� ������ ���� ������
	//��������ڰ� trivial�Ҷ� atomic�� ����� �� �ִ�. - ���� �Ʒ� �ڵ� ���־� ��. �ȸ��� ��
	//Point() {}
	//Point(const Point& p) : x(p.x), y(p.y), z(p.z) {}
};

std::atomic<int> an;
std::atomic<Point> ap;

int main()
{
	//��Ƽ �����忡�� �����ϰ� load...
	int n = an.load(); 

	// ��Ƽ�����忡 �����մϴ�. ������ lock free�� �ƴ� �������� ����ȭ ����� ����մϴ�.
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

	// ��Ƽ�����忡�� �����ϰ� 1���� - ���� �迭 cpu�� lock prefix ���.
	__asm
	{
		// lock free : os��  lock �� ���� �ʰ� cpu�� lock�� ���(mutex, sema ������� ����)
		lock inc n
	}
	*/
}