// 3_�Լ���ü4
#include <iostream>

// cppreference.com
// Closure �˻��غ�����
// Closure : ����ǥ������ ����� �ӽð�ü�� Ŭ���� ��� �մϴ�.
template<typename T> void foo(T f)  //T f = ����ǥ����()
{
	std::cout << __FUNCSIG__ << std::endl;
	f(1, 2);
}
int main()
{
	// C++11 ����ǥ���� : 
	foo( [](int a, int b) {return a + b; } );
	// class xx{ int operator()(int, int) }; xx();

	[](int a, int b) {return a + b; }(1, 2);
			// ����ǥ�����̸����ӽð�ü(1, 2);

	auto f = [](int a, int b) {return a + b; };
			// class xx{operator()}; xx();
	f(1, 2);

	auto&       a1 = [](int a, int b) {return a + b; }; // 1 error
	const auto& a2 = [](int a, int b) {return a + b; }; // 2 ok
	auto&&      a3 = [](int a, int b) {return a + b; }; // 3 ok

	decltype(f) f2; // error. ����ǥ������ ����� Ŭ��������
					//        ����Ʈ �����ڸ� ����Ҽ� �����ϴ�.

	decltype(f) f3(f); // ok.. ���� �����ڴ� �ֽ��ϴ�.



	int n = 10;
	// int&& r  = 10;      rvalue reference
	// T&& r    = �Լ�����; forwarding reference
	// auto&& r = �캯;     forwarding reference

	auto&& a5 = 10; // int&& a5 = 10
	auto&& a6 = n;  // int&  a6 = n
}








