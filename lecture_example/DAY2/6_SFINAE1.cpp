// 6_SFINAE1    215page

#include <iostream>

//void foo(int    n) { std::cout << "int"    << std::endl; }
//void foo(float  n) { std::cout << "float"  << std::endl; }
//void foo(double n) { std::cout << "double" << std::endl; }
void foo(...)      { std::cout << "..."    << std::endl; }

//template<typename T>
//void foo(T    n)   { std::cout << "T" << std::endl; }

int main()
{
	float f = 3.4f;
	
	// overloading resolution 
	// ���� �̸��� �Լ��� ������ ������  �Լ� ã�� ����
	foo(f); // 1. exactly matching - float
			// 2. template �� ����ؼ� float ���� - T
			// 3. promotion( ����Ÿ �ս��� ���� ��ȯ) - double
			// 4. standard conversion(ǥ�� Ÿ�Գ��� ��ȯ) - int	
			// 5. ��� �ĺ��� ������ �������� ��� - ...
}

