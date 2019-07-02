// "android source github
// 1_new1.cpp
// platform_system_core/libutils/include/utilstypeHelpers.h

#include<iostream>
// page 103
// �ٽ� 1. new�� 2���� ����
// new Point(1,1) : �޸� �Ҵ� �� ������ ȣ�� -  opensource���� ������. ������ ���� - ���� �и��ؼ� �����.
// new(p) Point(1,1) : �̹� �����ϴ� �޸�(�ּ� p)�� ������ ȣ�� -   placement new (��ġ���� new)

// �ٽ� 2. ������ ���� �޸𸮸� �Ҵ��ϴ� ���
// operator new(�޸� ũ��)

// �ٽ� 3.
// delete p1 ; �Ҹ��� ȣ��, �޸� ����
// operator delete(p1) ; �޸𸮸� ������.

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}
};

int main()
{
	//1. 0, 0���� �ʱ�ȭ�� Point �� ���� �Ѱ� ����� ������.
	Point* p1 = new Point(0, 0);

	//2. 0, 0���� �ʱ�ȭ�� Point�� ���� 10�� ����� ������.
	// �� class���� default�����ڰ� ���� ����� ���� ����. ���� �и��ϸ� ������.
	//Point*p2 = new Point[10];

	//3. �޸� �Ҵ�� ������ ȣ���� �и��ϸ� �׻� ���ϴ�.
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10)); // �޸� ������ �Ҵ���.

	// 4. 10���� �޸𸮿� ���� ������ ȣ��
	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0);
	}

	// ����Ŀ��� �Ҹ��� ȣ��
	for (int i = 0; i < 10; i++)
	{
		p2[i].~Point();
	}

	// ����� �޸� ����
	operator delete(p2);
}