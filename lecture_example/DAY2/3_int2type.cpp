// 3_int2type1.cpp       115 page

/*
class A
{
	int data;
public:
	void foo(int a)
	{
		*a = 10;	// error
	}
};
*/
// ���ø� : Ŭ������ ����� Ʋ
//          ������� ������ Ŭ������ �������� �ʴ´�.
// lazy instantiation : ���� ���ø��� 
//					�ν��Ͻ�ȭ(���� C++�ڵ����) �ȴ�.

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
	A<int> a;
	a.foo(0);
}



