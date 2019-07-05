#include <iostream>
#include <functional>

// bind함수를 안다고 가정하에 시작해 보자....

using namespace std::placeholders;

void foo(int a, int& b)
{
	b = 100;
}

int main()
{
	std::function<void(int)> f;
	int n = 0;

	f = std::bind(&foo, _1, n);  // n이 아니라 n의 값을 보관함. 참조로 하지 않는 이유는 {} 안에 존재한다면 {}을 벗어나면 파괴되기 때문에 값으로 보관함.
	f(10); // foo(10, n);
	std::cout << n << std::endl; // 얼마나 나올까요? 0? 100 ---> 0이 나옴

	// n이 아니라 n의 값을 보관함. 참조로 하지 않는 이유는 {} 안에 존재한다면 {}을 벗어나면 파괴되기 때문에 값으로 보관함.-참조로 하고 싶을경우 ref()를 사용함. 하지만 사용자 과실임.	
	f = std::bind(&foo, _1, std::ref(n));  
	//f = std::bind(&foo, _1, std::cref(n)); // cref() const 참조임.
	f(10); // foo(10, n);
	std::cout << n << std::endl; // 얼마나 나올까요? 0? 100 ---> 0이 나옴

}