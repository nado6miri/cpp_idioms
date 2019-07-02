#include<iostream>
#include<type_traits>


// �������� ���� �����Ͱ� �ƴ� ���� �и��ؼ� 2���� �Լ� ���ø��� �����.
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
	// if�� : ����ð� ���ǹ� - ���ǹ��� ����� ������� �����Ͻ� �Ʒ� 2�� �Լ� ���ø� ��� ���ȴٰ� �����Ϸ��� �����ϰ� 2�� �Լ� �ν��Ͻ�ȭ ��.
	// �������Ҷ� ������ ��Ű�� �ʵ��� ��ġ �ʿ�...�Լ� overloading�� �����Ͻ� �ڵ带 ���Խ�Ű�� �ʵ��� �ؾ� ��. - �ذ�å
	if (std::is_pointer<T>::value)  //������ ���� ���� - �������Ҷ� �˰� �ִ�. true ���� false ����...
	{
		printv_imp_pointer(a);
	}
	else
	{
		printv_imp_not_pointer(a);
	}
}


int main()
{
	int n = 0;
	printv(n); // 1 - error 
	printv(&n); // 2
}

// ? ä��������. �� ������ �����ϱ��? - �����Ϸ����� if(false) �� �̹� �˰� ������  if���� runtime���̱� ������ �ڵ� ���Խ�Ű�� ���� ���� �߻���.
// 1, 2�� ������� �����ϱ��? 1��