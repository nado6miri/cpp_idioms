#include <iostream>
#include <functional>

// �׷� std::reference_wrapper �� ������� ���� ���� ����� ����. - �����ͷ� ����� ��. �ᱹ ������ ��������.
template<typename T> class reference_wrapper
{
	T* ptr;
public:
	reference_wrapper(T& p) { ptr = &p; }

	// ��ȯ ������ : ��ȯŸ���� ǥ������ �ʴ� Ư¡�� �ִ�.
	// ��ü�� �ٸ� Ÿ������ ��ȯ�Ǳ� ���� �ʿ���.
	operator T&() { return *ptr; }
	T& get() const { return *ptr; }
};

void foo(int& a) { a = 100; }

// �Ʒ� �Լ��� bindó�� ���ڸ� ������ �ް� �ֽ��ϴ�. perfect forwarding &&�� ������� �ʰ�...
template<typename F, typename T>
void valueForwarding(F f, T arg)
{
	f(arg);
}


// reference_wrapper�� ����� �ִ� helper�Լ�
// class template �� ���� ����� ���� ���� �Լ� ���ø����� ����� ���� ==> Object Generator !!
template<typename T> reference_wrapper<T> ref(T& obj)
{
	return reference_wrapper<T>(obj);
}


// reference wrapper�� �ּҸ� ������ ����.
int main()
{
	int x = 0;
	//valueForwarding(&foo, x);

	/*
	reference_wrapper<int> r(x);
	valueForwarding(&foo, r); // ok
	*/
	//valueForwarding(&foo, reference_wrapper<int>(x)); // �� 2�ٰ� ������. ���� �ӽð�ü�� ������ٴ� ������.
	valueForwarding(&foo, ref(x)); // �� 1���� helper�� �������.


	std::cout << x << std::endl;
}