#include<iostream>
#include<type_traits>

template<int N> struct int2type   // 115 page code
{
	enum { value = N };
};


// �������� ���� �����Ͱ� �ƴ� ���� �и��ؼ� 2���� �Լ� ���ø��� �����.
template<typename T> void printv_imp(T v, int2type<1>)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}


template<typename T> void printv_imp(T v, int2type<0>)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}

template<typename T> void printv(T a)
{
	// T�� ������������ ���� �ٸ� �Լ��� ȣ���ϰ� �Ѵ�.
	// std::is_pointer<T>::value �� ���� true / false�̱� ������ type�� ���� �Լ� �����ε� �Ұ���. ���� int2type�� ����ؾ� ��.
	// int2type<0> �� type�̱� ������ �Լ� param���� ��� �Ұ���, ���� ()�� ���̰� �Ǹ� �ӽ� ��ü ���� - int2type<0>() : �ӽð�ü
	printv_imp(a, int2type<std::is_pointer<T>::value>());
}


int main()
{
	int n = 0;
	printv(n); // 1 - error 
	printv(&n); // 2
}

// ? ä��������. �� ������ �����ϱ��? - �����Ϸ����� if(false) �� �̹� �˰� ������  if���� runtime���̱� ������ �ڵ� ���Խ�Ű�� ���� ���� �߻���.
// 1, 2�� ������� �����ϱ��? 1��