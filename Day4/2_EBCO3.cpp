#include <iostream>
#include <type_traits>

class Empty {};

template<typename T
	, typename U
	, bool b = std::is_empty<T>::value> 
struct PAIR
//{};

// �ᱹ ���� pair�� ������� �ʰ� �Ʒ� 2���� ���˴ϴ�. �� ��쿡�� ���� �ص� �˴ϴ�.
// �Ʒ� �ҽ��� boost lib �� "compress_pair" �Դϴ�.
// c++  ǥ���� unique_ptr ���鶧 �� ����� ���ȴ�.

template<typename T, typename U> struct PAIR<T, U, false> // �κ� Ư��ȭ
{
	T v1;
	U v2;
	T& getValue1() { return v1; };
	U& getValue2() { return v2; };

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : v1(std::forward(<A>(a)), v2(std::forward<B>(b)) {};

	PAIR() = default; // default �����ڸ� ������.  PAIR {} �� ���� �ǹ�
};

template<typename T, typename U> struct PAIR : public T
{
	U v2;
	T& getValue1() { return *this; };
	U& getValue2() { return v2; };

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : T(std::forward(<A>(a))  // ��� Ŭ���� ������ ȣ��
		, v2(std::forward<B>(b)) {};

	PAIR() = default; // default �����ڸ� ������.  PAIR {} �� ���� �ǹ�
};


int main()
{
	PAIR<Empty, int> p;
	std::cout << sizeof(p) << std::endl;
	PAIR<int, Empty> p2;
	std::cout << sizeof(p2) << std::endl;
};

//4 / 8�� ��µž� �ϴµ�.... 8/4�� ���... ?? �����ʿ�