// 7_reference_wrapper
#include <iostream>
#include <functional>

// reference_wrapper : �̵� ������ ����
//			  ���� ���� ���Խ� ������ �̵�

template<typename T> class reference_wrapper
{
	T* ptr;
public:
	reference_wrapper(T& p) { ptr = &p; }

	operator T&() { return *ptr; }
	T& get() const { return *ptr; }
};

void foo(int& a) { a = 100; }

// �Ʒ� �Լ��� bind ó�� ���ڸ� ������ �ް� �ֽ��ϴ�.
template<typename F, typename T> 
void valueForwarding(F f, T arg) 
{
	f(arg);
}

// reference_wrapper �� ����� �ִ� ���� �Լ�.
//"Ŭ���� ���ø��� ���� ����� ���� ���� 
// �Լ� ���ø����� ����� ����." => "Object Generator"
template<typename T> 
reference_wrapper<T> ref(T& obj)
{
	return reference_wrapper<T>(obj);
}


int main()
{
	int x = 0;
	//valueForwarding(&foo, x);

//	reference_wrapper<int> r(x);
//	valueForwarding(&foo, r); // ok..

	//valueForwarding(&foo, reference_wrapper<int>( x ) ); 

	valueForwarding(&foo, ref(x)); // ok.

	std::cout << x << std::endl;
}





