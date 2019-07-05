#include <iostream>
#include <functional>

using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	void(*f1)(int); // 인자가 1개인 함수 주소만 담을 수 있다.

	// c++11 에서 추가된 함수 포인터의 역할의 템플릿
	// 주로 bind와 같이 사용한다.
	std::function<void(int)> f; //parameter가 int 1개이고 void type의 function ptr 넣을 수 있는 f 선언

	//f = &foo; // foo 함수가 param이 4개라 담을 수 없음
	f = std::bind(&foo, _1, 0, 0, 0);
	f(10); // 10, 0, 0, 0

}