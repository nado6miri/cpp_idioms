#include <iostream>

template<typename T> void foo(const T* a)
{
	std::cout << __FUNCSIG__ << std::endl;
}
template<typename T> void goo(const T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
}
int main()
{
	int n = 0;
	foo(&n);       // a�� ����Ű�� ���� const
	foo<int*>((int**)&n);

	goo(n);      // goo(const int& ) �Դϴ�.
	goo<int&>(n);// goo( int& const&) �Դϴ�.
				 // ��� ������ const �Դϴ�. ����
					// goo(int& & ) �Դϴ�. 
					// goo(int&) �� �˴ϴ�.

	int n1 = 20;
	int& r = n; // r�� ������ ���� n�� ����Ű�� �˴ϴ�.
				// ��, �����Ҽ� �����ϴ�.
				// int& const r = n; �� �ǹ� �Դϴ�.

	r = n1; // r�� ���� ? r�� ����Ű�� ���� ���� ?
}


