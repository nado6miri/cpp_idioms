#include <iostream>

template<typename T> void foo(T f)
{
	// lamda�� ������ �Լ� �̸� Ȯ��
	std::cout << __FUNCSIG__ << std::endl;
	f(1, 2);
};

int main()
{
	// C++ ���� ǥ���� :
	// �Ʒ� �ڵ�� ������ ��ü�� �����ǰ� �̷��� class�� ������. ()������ ���� - �Լ���ü - �ӽ� �Լ���ü�� �����. 
	// ���ٽ����� ������ �ӽ� ��ü�� defalut �����ڰ� ����. ���� decltype(f) f2; �� ������ �ȴ�.
	// class xx { operator () (int, int) }; xx();
	foo([](int a, int b) { return a + b; });

	// ���ٽ� �Ʒ��� �ӽð�ü��. (1,2)�� ���̸� �Լ��� ȣ����.
	[](int a, int b) { return a + b; } (1, 2);

	auto f = [](int a, int b) { return a + b; }; 
	f(1, 2);

	auto& a1 = [](int a, int b) { return a + b; }; // �ӽð�ü�� lvalue�� rvalue�� �� �� ���� - error
	const auto& a2 = [](int a, int b) { return a + b; }; // ok. const �� ���� �� ����
	const auto&& a3 = [](int a, int b) { return a + b; }; // ok

	// ���ٽ����� ������ �ӽ� ��ü�� defalut �����ڰ� ����. ���� decltype(f) f2; �� ������ �ȴ�.
	decltype(f) f2; // ���蹮��  error
	
	// ���ٽ����� ������ �ӽð�ü�� default �����ڴ� ������ ���� �����ڴ� �ִ�. - �Լ����� T f = ����ǥ����(); �̱� ������ ���� ������ �ʿ� ��.
	decltype(f) f3(f); // OK

	int n = 10;
	//int&& r = 10; // rvalue reference
	//T&& r = �Լ����� // forward reference
	//auto&& r = �캯; // forward reference �� auto�� T�� ������.
	auto&& a5 = 10; //  int&& a5 = 10;
	auto&& a6 = n; // int& a6 = n;
}

// cppreference.com
// Closure �˻��� ������.
// Closure : ���� ǥ������ ����� �ӽ� ��ü�� Ŭ������ �մϴ�.
