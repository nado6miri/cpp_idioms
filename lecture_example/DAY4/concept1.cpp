// concept1 - c++20 �� �߰��Ǵ� ����

// 1. concept �� ����ϴ�.
template<typename T>
cencept LessThanComparable(T a, T b)
{
	{a < b}->bool;
};

// 2. ���ø��� ���鶧 T�� ������ �ϴ� ����(����)�� ����մϴ�.
template<typename T> requires LessThanComparable 
T Max(T a, T b)
{
	return b < a ? a : b;
}

// �Ʒ� ó�� ����ؼ� ��밡���մϴ�.
LessThanComparable
Max(LessThanComparable a, LessThanComparable b)
{
	return b < a ? a : b;
}


int main()
{
	Max(1, 2);
}

template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
foo(T p) {}

template<typename T>
typename std::enable_if<!std::is_pointer<T>::value>::type
foo(T p) {}

// g++ �ҽ��̸�.cpp  -fconcepts  �� ������ ����.
void foo(PointerConcept)    {}
void foo(NotPointerConcept) {}
void goo(std::DefaultConstructible a)
{
	using T = std::DefaultConstructible;
	T b; // ����Ʈ ������ �ʿ�
}
// cppreference.com