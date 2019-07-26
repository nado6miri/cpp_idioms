#include <iostream>

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
	// 1. 0,0 ���� �ʱ�ȭ�� Point�� ���� �Ѱ� ����� ������
	Point* p1 = new Point(0, 0);

	// 2. 0,0 ���� �ʱ�ȭ�� Point�� ���� 10�� ����� ������
	//Point* p2 = new Point[10]; // error. ����Ʈ ������ �ʿ�

	// �޸� �Ҵ�� ������ ȣ���� �и��ϸ� �׻� ���ϴ�.
	Point* p2 = static_cast<Point*>(
					operator new(sizeof(Point) * 10));

	// 10���� �޸𸮿� ���ؼ� ������ ȣ��
	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0);
	}
	// ����Ŀ���
	// 1. �Ҹ��� ȣ��
	for (int i = 0; i < 10; i++)
		p2[i].~Point();

	// �޸𸮸� ����
	operator delete(p2);

}








