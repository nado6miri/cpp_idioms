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
	// mallock : �޸𸮸� �Ҵ�
	// new : �޸� �Ҵ� + ������ ȣ��
	// delete p1; �Ҹ��� ȣ�� �� �޸� ������.
	Point* p1 = new Point(0, 0);  

	// �޸� �Ҵ�� ������ ȣ���� �и�
	// 1. �޸� �Ҵ縸 - malloc�� ������. malloc  ��  operator new()�� ��ȯ���� void *��
	//Point* p2 = operator new(sizeof(Point));
	Point* p2 = static_cast<Point*> (operator new(sizeof(Point)));
	std::cout << "�Ҵ�� �ּ� : " << p2 << std::endl;

	// 2. �Ҵ�� �޸𸮿� ������ ȣ�� - new(ptr) �Ѱ��� ptr �� ���� �Լ��� ȣ���ض�.
	new(p2) Point(0, 0); // ���蹮��

	// �޸� �Ҵ�� ������ ȣ���� �и� �ߴٸ� �Ҹ��� ȣ��� �޸� ȣ�⵵ �и��ʿ�.
	// 3. �Ҹ��� ȣ��
	p2->~Point(); 
	// 4. �޸� ����
	operator delete(p2); 
}