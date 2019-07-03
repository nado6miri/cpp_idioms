#include <iostream>

struct Test
{
	int data;
	void foo() & { std::cout << __FUNCSIG__ << std::endl;  }
	void foo() && { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	Test t; // 이름이 있습니다. 블럭을 벗어날때까지 생존, 이름을 통해서 언제라도 접근가능, lvalue
	t.data = 10;
	t.foo(); // 이름을 가지고 호출을 하면 foo() & 함수가 호출됨.

	Test(); // 이름이 없습니다. 단일 문장에서만 사용 가능. rvalue, ;(문장 마지막) 만나면 소멸됨.
	//Test().data = 10; // error , 임시객체는 이름이 없다. lvalue로 올수 없다. rvalue 임.
	Test().foo(); // rvalue인 임시객체를 가지고 함수를 호출 하면 foo() && 함수가 호출됨.

	Test&& r = Test(); // 임시객체를 ref로 참조하면 수명이 연장된다. {}을 넘어가면 해제 됨.
	r.foo();
}