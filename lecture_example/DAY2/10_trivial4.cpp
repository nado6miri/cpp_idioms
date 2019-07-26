// 10_trivial4
#define _ENABLE_ATOMIC_ALIGNMENT_FIX
#include <iostream>
#include <atomic>

struct Point
{
	int x, y, z;

	Point() {}

	// ����ڰ� ������ ���� ������
	Point(const Point& p) : x(p.x), y(p.y), z(p.z) {}

};
std::atomic<int> an;
std::atomic<Point> ap;

int main()
{
	int n = an.load(); // ��Ƽ �����忡 �����ϰ� load.

	Point pt = ap.load(); // ��Ƽ�����忡 �����մϴ�.
						// ������ lock free�� �ƴ�
						// �������� ����ȭ ����� ����մϴ�.
						// ��κ� "busy waiting" �մϴ�.

	std::cout << an.is_lock_free() << std::endl; // 1
	std::cout << ap.is_lock_free() << std::endl; // ?





	/*
	// n = n + 1 �� ���
	__asm
	{
		mov eax, n
		add eax, 1
		mov n, eax
	}
	// ��Ƽ�����忡 �����ϰ� 1����
	// ���� �迭 CPU�� lock prefix ���.
	// lock free : OS �� lock �� ������� �ʴ´ٴ� �ǹ�
	__asm
	{
		lock inc n
	}
	*/
}


