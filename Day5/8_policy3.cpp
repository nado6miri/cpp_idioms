#include <iostream>
#include <vector>


struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { std::cout << __FUNCSIG__ << std::endl; }
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	std::allocator<Point> ax;

	Point* p1 = ax.allocate(2); // �޸� �Ҵ縸
	ax.construct(&p1[0], 1, 2); // ������ ȣ��
	ax.construct(&p1[1], 1, 2); // ������ ȣ��

	ax.destroy(&p1[0]); // �Ҹ��� ȣ��
	ax.destroy(&p1[1]); // �Ҹ��� ȣ��

	ax.deallocate(p1, 2); // �޸� ����

	// vector �� ���������� allocator�� ����Ѵ�.
	//std::vector<
}

