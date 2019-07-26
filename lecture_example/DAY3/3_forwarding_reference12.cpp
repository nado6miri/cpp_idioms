#include <iostream>

struct Test
{	
	int data;

	void foo() &  { std::cout << __FUNCSIG__ << std::endl; }
	void foo() && { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	Test t; // 이름이 있습니다. 블럭을 벗어날때 까지 생존
			// 이름을 통해서 언제라도 접근 가능. lvalue
	t.data = 10;

	t.foo(); // foo() &

	Test&& r = Test(); // 이름이 없습니다. 단일문장에서만 사용. rvalue
			// 임시객체
	//Test().data = 10;// error. 임시객체는 rvalue

	Test().foo(); // foo() &&
}


