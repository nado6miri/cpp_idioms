// 6_SFINAE2
#include <iostream>

// �ٽ� 1. �Լ� ȣ��� � �Լ��� ȣ���ϴ����� ���ڸ� ������ ����
//         �Ѵ�. ��ȯ Ÿ���� ���� ����.

// ���ø��� ����ϱ�� �����ϰ�, T�� Ư�� Ÿ������ ġȯ�Ҷ�
// �����ϸ� ������ �ƴ϶� �ٸ� ������ �Լ��� ����ϰ� �Ѵ�.

// Subtitution Failure Is Not An Error => SFINAE

template<typename T>
typename T::type foo(T n) { std::cout << "T" << std::endl; return 0; }
// int::type foo(int n) {} �Լ��� �����Ϸ��� �Ѵ�.

void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	foo(10);
}

