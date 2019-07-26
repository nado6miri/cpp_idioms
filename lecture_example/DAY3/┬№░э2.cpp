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
	foo(&n);       // a가 가리키는 것은 const
	foo<int*>((int**)&n);

	goo(n);      // goo(const int& ) 입니다.
	goo<int&>(n);// goo( int& const&) 입니다.
				 // 모든 참조는 const 입니다. 따라서
					// goo(int& & ) 입니다. 
					// goo(int&) 가 됩니다.

	int n1 = 20;
	int& r = n; // r은 죽을때 까지 n만 가리키게 됩니다.
				// 즉, 변경할수 없습니다.
				// int& const r = n; 의 의미 입니다.

	r = n1; // r을 변경 ? r이 가리키는 곳을 변경 ?
}


