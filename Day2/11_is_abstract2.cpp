//11_is_abstract1
#include<iostream>
#include<type_traits>

// 143 page....

// �ٽ� 1. �Լ� ���ø� ������ �������� ������ 2�� �Լ��� �����.
// 2. ���ø� ������ ������ �������� ������ �����ϰ� �����. (�����Ͻ�)

// T arg : �߻�Ŭ������� ������. ������ ���ڸ� ������ ��ü�� �ʿ�!!
// T* arg : �߻�Ŭ������ �����ʹ� ���� �� �ִ�.
// T(*arr)[1] : �迭�� ����Ű�� ������ - �߻�Ŭ������ �迭�� ����Ű�� �����͸� ���� �� ����.

// �߻�Ŭ���������� �����ϵ��� ��.
template<typename T> short test(T(*arr)[1]);// {}

// �߻�Ŭ������ ��밡����.
template<typename T> char test(...);// { }


class Shape
{
public:
	//virtual void Draw() = 0;
};

int main()
{
	// test<Shape>(0); // ȣ��, �򰡵Ǵ� ǥ����
	int n = sizeof(test<Shape>(0)); // �Լ� call�� ���� �ʰ� return���� size��....������.

	std::cout << n << std::endl;
}


