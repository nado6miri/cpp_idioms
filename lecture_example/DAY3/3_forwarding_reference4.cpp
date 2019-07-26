// �Լ� ���ڷ�
// int&  : int �� lvalue �� ���� ����
// int&& : int �� rvalue �� ���� ����
// T&    : ��� Ÿ���� lvalue�� ���� ����.

// T&&   : ��� Ÿ���� lvalue�� rvalue ���� ����.

// lvalue(n) �� ������ T : int&     �Լ�(int& )
// rvalue(0) �� ������ T : int      �Լ�(int&& )

void f1(int&  a) {}
void f2(int&& a) {}

template<typename T> void f3(T&  a) {}
//f3<int>( n );
//f3<int&>( n );
//f3<int&&>( n );

template<typename T> void f4(T&& a) {}

int main()
{
	int n = 0;
	// ����ڰ� Ÿ���� ���� �����ϸ� � �Լ��� ��������
	// ������ ���ô�. �����Ǵ� �Լ��� ����� ������ ������
	f4<int>(0);   // T : int   T&& : int&&      f4(int&& )
	f4<int&>(n);  // T : int&  T&& : int& &&    f4(int&)
	f4<int&&>(0); // T : int&& T&& : int&& &&   f4(int&&)

	// ����ڰ� Ÿ���� �������� ������ �����Ϸ��� Ÿ���� �����ؾ�
	// �մϴ�. ��� �������� ������ ������
	f4(n);  // T : int& �� �����ϰ�.. ���� �Լ� f4(int&)�� ����
	f4(0);  // T : int  �� �����ϰ�,  ���� �Լ� f4(int&&)�� ����
}




