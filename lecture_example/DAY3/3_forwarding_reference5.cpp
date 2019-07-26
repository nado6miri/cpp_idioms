#include <iostream>
// lvalue�� rvalue�� ��� ���޹޴� �Լ� �����
// 1. call by value
// void f1(int a) {}

// 2. const lvalue reference
//void f1(const int& a) {}

// 3. 2���� �Լ� 
//void f1(int&  a) {}
//void f1(int&& a) {}

// 4. 2���� �Լ��� �ڵ�����
// T&&  : forwarding reference(universal reference ��� �մϴ�)
// int&&: rvalue reference
template<typename T> void f1(T&& a) 
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 0;
	f1(n);    // T : int&    f1(int& )
	f1(10);   // T : int     f1(int&&)
}

