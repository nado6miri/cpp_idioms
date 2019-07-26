#include <iostream>

// is_pointer : ������ �Ҷ� T�� ������ ���� �����ϴ� ����
//              ������ �Ҷ� ����ϴ� �Լ� ��� �ǹ̷� metafunction
//			    �̶�� �Ѵ�.

// ����� ��
// 1. ����ü ���ø��� �����.
// 2. enum { value = false } �� �ִ´�.
// 3. ������ �����ϴ� �κ� Ư��ȭ ������ �����. 
//    �׸��� enum { value = true } �� �ִ´�.
// 



template<typename T> struct is_pointer
{
	enum { value = false };
};
// ���ø� �κ� Ư��ȭ(specialization) ����
// T�� ���¿� ���� �ٸ� ������ ����ϰڴٴ� �ǹ�.
template<typename T> struct is_pointer<T*>
{
	enum { value = true };
};

template<typename T> 
void foo(T v)
{
	if ( is_pointer<T>::value )
		std::cout << "������" << std::endl;
	else
		std::cout << "������ �ƴ�" << std::endl;
}


int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}