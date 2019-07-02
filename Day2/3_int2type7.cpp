#include <iostream>
#include<type_traits>

// int2type�� �������� c++11 ǥ�ؿ� �߰��� ���ø�
template<typename T, T N> struct integral_constant
{
	// c++11 ���� ��Ÿ�� - �����Ͻ� ����� ���� �� �ִ� ������ ���
	//enum { value = N };
	static constexpr T value = N; // C++ ���� ��Ÿ�� - constexpr�� ����� ������ �ð� ��� 
};

/*
integral_constant<int, 0> t0;
integral_constant<int, 1> t1;
integral_constant<short, 1> t2;

integral_constant<bool, true> b0;
integral_constant<bool, false> b1;

// true/false : ��, ������ ��Ÿ���� ��. ���� Ÿ��
// true_type / false_type : ��, ������ ��Ÿ���� Ÿ��. �ٸ� Ÿ��
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

//C++ ǥ���� is_pointer�� �Ʒ�ó�� ����� �����ϴ�.
template<typename T> struct is_pointer : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};
*/


// �������� ���� �����Ͱ� �ƴ� ���� �и��ؼ� 2���� �Լ� ���ø��� �����.
template<typename T> void printv_imp(T v, std::true_type)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}


template<typename T> void printv_imp(T v, std::false_type)
{
	std::cout << "not pointer" << std::endl;
	std::cout << v << std::endl;
}

template<typename T> void printv(T a)
{
	// T�� ������������ ���� �ٸ� �Լ��� ȣ���ϰ� �Ѵ�.
	// std::is_pointer<T>::value �� ���� true / false�̱� ������ type�� ���� �Լ� �����ε� �Ұ���. ���� int2type�� ����ؾ� ��.
	// int2type<0> �� type�̱� ������ �Լ� param���� ��� �Ұ���, ���� ()�� ���̰� �Ǹ� �ӽ� ��ü ���� - int2type<0>() : �ӽð�ü
	// is_pointer�� ���Ŭ������ true_type / false_type��.
	printv_imp(a, std::is_pointer<T>());
}


int main()
{
	int n = 0;
	printv(n); // 1 - error 
	printv(&n); // 2
}



