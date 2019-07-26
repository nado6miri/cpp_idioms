// "android source github"
// platform_system_core/libutils/include/utils/typeHelpers.h
// 1_new1.cpp    103 page. 
#include <iostream>

// �ٽ� 1. new�� 2���� ����
// new    Point(1,1) : �޸� �Ҵ� �� ������ ȣ��
// new(p) Point(1,1) : �̹� ���� �ϴ� �޸�(�ּ� p)�� ������ ȣ��
//				placement new ( ��ġ ���� new )

// �ٽ� 2. ������ ȣ����� �޸𸮸� �Ҵ��ϴ� ���
//		   operator new( �޸� ũ��)

// �ٽ� 3
// delete p1;   �Ҹ��� ȣ��, �޸� ����
// operator delete(p1) : �޸𸮸� ����

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
	// malloc : �޸𸮸� �Ҵ�
	// new    : �޸� �Ҵ� + ������ ȣ��
	//Point* p1 = new Point(0, 0); 
	//delete p1;    �Ҹ��� ȣ���� �޸� ����


	// �޸� �Ҵ�� ������ ȣ���� �и�
	// 1. �޸𸮸� �Ҵ�
	Point* p2 = static_cast<Point*>( operator new(sizeof(Point))); // malloc�� ����

	std::cout << "�Ҵ�� �ּ� : " << p2 << std::endl;

	// 2. �Ҵ�� �޸𸮿� ������ ȣ��
	new(p2) Point(0, 0);

	// �޸� �Ҵ�� ������ ȣ���� �и��� ���
	// �Ҹ��� ȣ��� �޸� ������ �и��Ѵ�.

	// 3. �Ҹ��� ȣ��
	p2->~Point();

	// 4. �޸� ����
	operator delete(p2); 

}








