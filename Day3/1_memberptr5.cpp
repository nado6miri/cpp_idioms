#include <iostream>

class Dialog
{
public:
	void color() {};
	void Close() {};
};

void foo() {};

/*
int main()
{
	int n = 0;

	// 아래 코드를 생각해 보세요.
	void* p1 = &n; // ok
	void* p2 = &foo; // ok
	//void* p3 = &Dialog::color; // error --offset임
	//void* p4 = &Dialog::Close; // error --offset임
}
*/

void goo(void *p) { printf("%p\n", p); }
void goo(bool b) { printf("%d\n", b); }

int main()
{
	int n = 0;

	// 결과를 예측해 보세요.
	goo(&n);
	goo(&foo);
	goo(&Dialog::color);
	goo(&Dialog::Close);
	
	if (&Dialog::color) std::cout << "true" << std::endl;
	//bool b = &Dialog::color;
	//std::cout << b << std::endl;

	std::cout << &n;	// cout.operator << (void*)
	std::cout << &Dialog::Close; // cout.operator<<(void*) cout.operator<<(bool) --> cout값 이상하게 표시되는 케이스임... printf사용
}