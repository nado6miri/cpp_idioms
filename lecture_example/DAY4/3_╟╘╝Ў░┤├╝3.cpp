//#include <iostream>

// �Լ� ��ü�� ���� 2.
// �ٸ� �Լ��� ���ڷ� ���޵Ǵ� �Լ��� ���鶧
// 1. �Ϲ� �Լ��� ������ �ٽ� ȣ��� �ζ��� ġȯ���� ���Ѵ�.
// 2. �Լ� ��ü�� ������ �ٽ� ȣ��� �ζ��� ġȯ�ȴ�.



// 1. �ζ��� �Լ��� ������ �Ҷ� �̷�� ����.

inline int Add(int a, int b) { return a + b; }

struct Plus
{
	inline int operator()(int a, int b) { return a + b; }
};

template<typename T> void foo(T f)
{
	//std::cout << __FUNCSIG__ << std::endl;

	int n = f(1, 2); // �̼����� �� ������ ������
		// f.operator()(1,2)
}
int main()
{
	Plus p;
	foo(Add);  // �Լ� ������ ���� foo(int(*f)(int, int))
//	foo(Sub);  // �Լ� ������ ���� foo(int(*f)(int, int))

	foo(p);    // Plus Ÿ������ ����  foo(Plus f)
//	Minus m;
//	foo(m);     // foo(Minus)
}


// cl 3_�Լ���ü3.cpp    /FAs      => 3_�Լ���ü3.asm
// cl 3_�Լ���ü3.cpp    /FAs /Ob1

// g++ 3_�Լ���ü3.cpp -S         => 3_�Լ���ü3.s



