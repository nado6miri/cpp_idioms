
class Vector
{
public:
	//���� ������ ����� explicit ������ - ���� �ʱ�ȭ�� ����� �� ����.���� �ʱ�ȭ�� �����ϴ�.
	//������ ���鶧 �����ϸ� explicit�� ������.
	explicit Vector(int size) {}
};

void foo(Vector v) {} // foo(10) ȣ��� Vector v = 10 �� �� �������� �����ϳ� ������� ����... 

int main()
{
	Vector v1(10);  // ���� �ʱ�ȭ direct initialization
	Vector v2 = 10; // copy initialization
	Vector v3{ 10 }; // direct initialization

	foo(v1); // ok
	foo(10); // explict�� ����ϸ� ����, ������� ������ ng ���� explict �� ����.
}; 
