#include<iostream>
#include<type_traits>


// �������� ���� �����Ͱ� �ƴ� ���� �и��ؼ� 2���� �Լ� ���ø��� �����.
template<typename T> void printv_imp(T v, YES)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}


template<typename T> void printv_imp(T v, NO)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}

template<typename T> void printv(T a)
{
	// T�� ������������ ���� �ٸ� �Լ��� ȣ���ϰ� �Ѵ�.
	// std::is_pointer<T>::value �� ���� true / false�̱� ������ type�� ���� �Լ� �����ε� �Ұ���. ���� int2type�� ����ؾ� ��.
	printv_imp(a, std::is_pointer<T>::value);
}


int main()
{
	int n = 0;
	printv(n); // 1 - error 
	printv(&n); // 2
}

// ? ä��������. �� ������ �����ϱ��? - �����Ϸ����� if(false) �� �̹� �˰� ������  if���� runtime���̱� ������ �ڵ� ���Խ�Ű�� ���� ���� �߻���.
// 1, 2�� ������� �����ϱ��? 1��