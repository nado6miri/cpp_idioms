// 2_explicit

class Vector
{
public:
	// explicit ������ : ���� �ʱ�ȭ�� ����Ҽ� ����.
	//					���� �ʱ�ȭ�� �����ϴ�.
	explicit Vector(int size) {}
};
void foo(Vector v) {} // Vector v = 10
					// Vector v = v1

int main()
{
	Vector v1(10);  // direct initialization
	//Vector v2 = 10; // copy initialization
	Vector v3{ 10 }; // direct

	foo(v1); // ok
	foo(10); // ?
}






