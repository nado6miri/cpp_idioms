// 3_int2type.cpp 115 page

/*
class A
{
	int data;
public :
	void foo(int a)
	{
		*a = 10; // error
	}
};
*/

// ���ø��� Ŭ������ ����� ����. - template�� ������� ������ ������ ���� ����.
// lazy instantiation : ���� ���ø��� �ν��Ͻ�ȭ (���� C++�ڵ����) �ȴ�.
template<typename T>
class A
{
	T data;
public:
	void foo(T a)
	{
		*a = 10; 
	}
};


int main()
{
	// �Ʒ� �ڵ�� ������ ���� �ʴ´�. foo() �Լ��� ȣ������ �ʾұ� ����.. ���� ������� �ʾҴٸ� ������ ���� ����.
	A<int> a;
	// �Ʒ����� foo ȣ��� ������ �ܰ迡�� ���� �߻���.
	a.foo(4);
}