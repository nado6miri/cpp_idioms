// 3 make

#include <iostream>
#include <memory>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}
};

int foo() { return 0;  }

void goo(const std::unique_ptr<Point>& p, int n) {}

int main()
{
	// �Ʒ� ������ �����ұ��? �������� ã�ƺ�����.
	// �Ʒ�  param�� �����ϴ� ������ ǥ�ؿ� ��õǾ� ���� ����. Point ������ foo() ���� �� unique_ptr ���� ������ �� ���
	// Point malloc �� foo���� exception�� �߻��ϸ� unique_ptr�� �ȸ���� �� �����̱� ������ �޸� ������ �� �� ����. �޸� ���� �߻� ���ɼ�
	// new Point(1,2) --> foo() --> unique_ptr ����
	goo(std::unique_ptr<Point>(new Point(1, 2)), foo());
}