#include <iostream>
#include <type_traits>


// �ִ� ������� �����϶��� ����, �Ǽ��϶��� �ǹ̰� ���� - ���� �����϶��� �����ϰ� �Ǽ��϶��� �������� �ʵ��� ��.
/*
template<typename T> T gcd(T arg1, T arg2)
{
	// arg1, arg2�� �ִ� ������� ��ȯ�Ѵٰ� ����
	// static_assert : 1��° ���ڰ� false�̸� �������� �����Ѵ�.
	static_assert(std::is_integral<T>::value, "not integral");
	return 0;
}
*/

// ���� Ÿ���̸� enable, ������ �ƴϸ� enable_if�� false�� ������� �ʵ��� ������Ÿ�ӽ� ġȯ�� ���� �ʾ� �Ʒ� double gcd()�Լ��� �� �� �ִ�.
template<typename T> 
typename std::enable_if<std::is_integral<T>::value, T>::type
gcd(T arg1, T arg2)
{
	// arg1, arg2�� �ִ� ������� ��ȯ�Ѵٰ� ����
	// static_assert : 1��° ���ڰ� false�̸� �������� �����Ѵ�.
	static_assert(std::is_integral<T>::value, "not integral");
	return 0;
}


// double ������ �Լ� ����
double gcd(double arg1, double arg2)
{
	std::cout << "double" << std::endl;
	return 0;
}

int main()
{
	gcd(10, 6);
	gcd(3.4f, 2.4f);
}