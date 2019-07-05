#include <iostream>
#include <functional>
#include <thread>

void foo(int a, int&b) { b = 100; }

int main()
{
	int n = 0;

	// thread의 생성자에서 스레드 생성, 즉 이순간 스레드가 생성됩니다.
	//std::thread t(&foo, 1, n);  // 1, n 은 foo  함수의 인자임. n이 참조로 넘어갈것이냐? 값으로 넘어갈 것이냐? bind와 동일하게 값으로 넘어감. - 빌드오류
	std::thread t(&foo, 1, std::ref(n));  // 1, n 은 foo  함수의 인자임. n이 참조로 넘겨라!! - bind와 동일함. 어쩔수 없이 값을 넘겨야 하는데 참조로 처리해야 할 경우 ref를 사용함.

	t.join();
	std::cout << n << std::endl; // ??
}