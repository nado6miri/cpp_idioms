// 11_is_abstract1
#include <iostream>
#include <type_traits>

class Shape
{
public:
	virtual void Draw() = 0;
};

// �ٽ� 1. �Լ� ���ø� ������ �������� ������ 2���� �Լ��� �����
//      2. ���ø� ������ ������ �������� ������ �����ϰ� �����.

// T arg : �߻�Ŭ������� ����. ������ ���ڸ� ������ ��ü�� �ʿ�!
// T* arg : �߻�Ŭ������ �����ʹ� ����� �ִ�. 

// T(*arr)[1] : �迭�� ����Ű�� ������ - �߻�Ŭ������ �迭��
//				����Ű�� �����͸� ����� ����.

template<typename T> short test(T(*arr)[1]);
template<typename T> char test(...);

int main()
{
	//test<Shape>(0); // ȣ��. �򰡵Ǵ� ǥ����

	// ȣ������ ����, ��� �Լ��� ȣ��Ǵ����� ����.
	int n = sizeof( test<Shape>(0) );

	std::cout << n << std::endl;
}







