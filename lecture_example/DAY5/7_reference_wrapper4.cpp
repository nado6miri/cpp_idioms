#include <iostream>
#include <functional>
#include <thread> 

void foo(int a, int& b) { b = 100; }

int main()
{
	int n = 0;
	//std::thread t(&foo, 1, n); // thread 의 생성자에서 스레드 생성
							   // 즉, 이순간 스레드가 생성됩니다.
	std::thread t(&foo, 1, std::ref(n));

	t.join();
	std::cout << n << std::endl; // ?? 
}



