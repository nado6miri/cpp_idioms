#include <iostream>
#include <type_traits>


// ������ �� ���� �����Ͱ� �ƴ� ���� �и��ؼ� 
// 2���� �Լ� ���ø��� �����

template<typename T> void printv_imp_pointer(T v)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void printv_imp_not_pointer(T v)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}

template<typename T> void printv(T a)
{
	// if �� : ����ð� ���ǹ�
	//         ������ ����� ������� ������ �Ҷ���
	//         �Ʒ� 2���� �Լ� ���ø� ��� ���ȴٰ� 
	//         �����Ϸ��� �����ؼ� 2�� �Լ� ��� �ν��Ͻ�ȭ �˴ϴ�.
	if (std::is_pointer<T>::value)
		printv_imp_pointer(a);
	else
		printv_imp_not_pointer(a);
}


int main()
{
	int n = 0;
	printv(n); 
}
