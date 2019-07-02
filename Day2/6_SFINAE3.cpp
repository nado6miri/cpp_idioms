// 6_SFINAE3

#include <iostream>

// �ٽ� 1. �Լ� ȣ��� � �Լ��� ȣ���ϴ��� ���ڸ� ������ �����Ѵ�. ��ȯ Ÿ���� ���þ���.
// ���ø��� ����ϱ�� �����ϰ� T�� Ư�� Ÿ������ ġȯ�Ҷ� �����ϸ� ������ �ƴ϶� �ٸ� ������ �Լ��� ����ϰ� �ȴ�. (SFINAE)
/*
template<typename T>
void foo(T n) 
{ 
	typename T::type n; // 1. SFINAE ���� �ȵ� - error�߻�  int type�� type�� ����.
}
*/

// SFINAE�� ����Ǵ� ��ġ 3�� (�Լ� SIGNATURE�� ����)
// 1. �Լ� ��ȯ�� - ���� ���� ���Ǵ� ���
template<typename T> typename T::type foo(T n)
{
}

// 2. �Լ� ����Ÿ�� - �����ڿ� ���� ��ȯ Ÿ���� ���� ������ SFINAE�� ����ϰ� ������..
template<typename T> void foo(T n, typename T::type n2)
{
}

// 3. ���ø� ���� - �Լ��� ����� ������ ���� �ʴ� Ư¡�� �ִ�. - �� ��� ����.
template<typename T, typename T2 = typename T::type> void foo(T n)
{
}



void foo(...) { std::cout << "..." << std::endl; }



int main()
{
	// overloading resolution
	foo(10);
}