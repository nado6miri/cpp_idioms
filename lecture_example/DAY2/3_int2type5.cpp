// int2type5.cpp

// ���ø� ���ڷδ� "Ÿ��" �� �ƴ϶� "����"�� �������� �ֽ��ϴ�.
template<int N> struct int2type    // 115 page �ڵ��Դϴ�.
{
	enum { value = N};
};
int main()
{
	foo(0);
	foo(1); // 0, 1�� ���� Ÿ��. foo(0),foo(1)�� ������ �Լ�ȣ��
	int2type<0> t0;
	int2type<1> t1;
	foo(t0);
	foo(t1); // t0, t1 �� �ٸ� Ÿ��. foo(t0), foo(t1)�� 
			// �ٸ� �Լ� ȣ��.
}