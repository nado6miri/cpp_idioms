#include<iostream>
#include<type_traits>

template<typename T> void printv(T a)
{
	if (std::is_pointer<T>::value)  //������ ���� ���� - �������Ҷ� �˰� �ִ�. true ���� false ����...
	{
		std::cout << a << " : " << *a << std::endl;
	}
	else
	{
		std::cout << a << std::endl;
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