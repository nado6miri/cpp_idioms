#include<iostream>
#include<type_traits>

template<int N> struct int2type   // 115 page code
{
	enum { value = N };
};

int main()
{
	// foo(0) foo(1)�� ���� �Լ��� ȣ����.
	foo(0);
	foo(1);

	// t0 / t1�� �ٸ�Ÿ��,   foo(t0), foo(t1)�� �ٸ��Լ� ȣ���.
	// int2type �� �̿��ϸ� ������ ���� Ÿ�Ե� �ٸ��� �Լ��� ȣ���� �� �ִ�. 90��� ���� ....
	int2type<0> t0;
	int2type<1> t1;
	foo(t0);
	foo(t1);
}

