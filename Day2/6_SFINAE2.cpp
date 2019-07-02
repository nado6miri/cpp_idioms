// 6_SFINAE2

#include <iostream>

// �ٽ� 1. �Լ� ȣ��� � �Լ��� ȣ���ϴ��� ���ڸ� ������ �����Ѵ�. ��ȯ Ÿ���� ���þ���.
// ���ø��� ����ϱ�� �����ϰ� T�� Ư�� Ÿ������ ġȯ�Ҷ� �����ϸ� ������ �ƴ϶� �ٸ� ������ �Լ��� ����ϰ� �ȴ�. (SFINAE)
//template<typename T> int foo(T n) { std::cout << "T" << std::endl; return 0; }
template<typename T>
typename T::type foo(T n) { std::cout << "T" << std::endl; return 0;  }
// int::type foo(int n) {} �Լ��� �����Ϸ� �Ѵ�. int::type�� ����..

void foo(...) { std::cout << "..." << std::endl; }
//void foo(int n) { std::cout << "int" << std::endl; }



int main()
{
	// overloading resolution
	foo(10); 
}