// concept1 - c++20�� �߰��Ǵ� ����

// 1. concept�� ����ϴ�.
template<typename T>
concept LessThanCompareable(T a, T b)
{
	{ a < b }-> bool; // {} ���� ���� �����  bool�� ���;� ��.
};


// Max �Լ��� �Ѿ��  T type�� < �����ڸ� �������� ���� ���.... concept�� �̿��ؼ� error msg�� �������� ���δ�.
//template<typename T> T Max(T a, T b)
template<typename T> requires LessThanComparable 
T Max(T a, T b)
{
	return b < a ? a : b;
}

// �Ʒ�ó�� ����ؼ� ����� �����մϴ�. - �Ʒ��� template��.
LessThanComparable
T Max(LessThanComparable a, LessThanComparable b)
{
	return b < a ? a : b;
}


int main()
{
	Max(1, 2);
}


//  �Ʒ� 2�� �Լ� ����� ���� �� �� �����ϰ� ����
template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
foo(T p) {}

template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
foo(T p) {}


void foo(PointerConcept) {}
void foo(NotPointerConcept) {}

void goo(std::DefaultConstructible a)
{
	using T = std::DefaultConstructible
}

// cppreference.com ������ concept lib�� Ȯ�� ����.