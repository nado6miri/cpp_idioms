#include <iostream>

class Dialog
{
public:
	int color;
	void Close() {}
};
void foo() {}
/*
int main()
{
	int n = 0;

	// 아래 코드를 생각해 보세요.
	void* p1 = &n;		// ok
	void* p2 = &foo;	// ok
	//void* p3 = &Dialog::color; // error
	//void* p4 = &Dialog::Close; // error
}
*/
void goo(void* p) { printf("%p\n", p); }
void goo(bool b)  { printf("%d\n", b); }

int main()
{
	int n = 0;
	// 결과 예측해 보세요.
	goo(&n);	
	goo(&foo);
	goo(&Dialog::color);
	printf("%d\n", &Dialog::color);
	
	if (&Dialog::color) std::cout << "true" << std::endl;
//	bool b = &Dialog::color;
//	std::cout << b << std::endl;

	goo(&Dialog::Close);

	std::cout << &n;			// cout.operator<<(void*)
	std::cout << &Dialog::Close;// cout.operator<<(bool)
}





