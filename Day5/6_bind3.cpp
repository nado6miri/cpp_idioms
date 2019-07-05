#include <iostream>
#include <functional>

// bind�Լ��� �ȴٰ� �����Ͽ� ������ ����....

using namespace std::placeholders;

void foo(int a, int& b)
{
	b = 100;
}

int main()
{
	std::function<void(int)> f;
	int n = 0;

	f = std::bind(&foo, _1, n);  // n�� �ƴ϶� n�� ���� ������. ������ ���� �ʴ� ������ {} �ȿ� �����Ѵٸ� {}�� ����� �ı��Ǳ� ������ ������ ������.
	f(10); // foo(10, n);
	std::cout << n << std::endl; // �󸶳� ���ñ��? 0? 100 ---> 0�� ����

	// n�� �ƴ϶� n�� ���� ������. ������ ���� �ʴ� ������ {} �ȿ� �����Ѵٸ� {}�� ����� �ı��Ǳ� ������ ������ ������.-������ �ϰ� ������� ref()�� �����. ������ ����� ������.	
	f = std::bind(&foo, _1, std::ref(n));  
	//f = std::bind(&foo, _1, std::cref(n)); // cref() const ������.
	f(10); // foo(10, n);
	std::cout << n << std::endl; // �󸶳� ���ñ��? 0? 100 ---> 0�� ����

}