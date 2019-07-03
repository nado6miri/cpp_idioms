#include <iostream>
#include <functional>  // invoke

// 핵심 1. 일반함수 포인터에 멤버 함수의 주소를 넣을 수 없다.
// 2. 일반함수 포인터에 static 멤버함수의 주소를 넣을 수 있다.
// 3. member 함수의 포인터를 만들고 사용하는 방법.
// 4. c++ 17 invoke 함수.

class Dialog
{
public:
	void Close()  // void Close(Dialog* this) 의미임.
	{ std::cout << "Close" << std::endl; }

	static void Close2() {}  // 만약 static함수를 추가했다면 객체 생성 없더라도 호출 가능
};

void foo() { std::cout << "foo" << std::endl; }

int main()
{
	void(*f1)() = &foo;  // void를 반환하고 param이 없는 함수의 포인터를 저장하겠다.
	//void(*f2)() = &Dialog::Close; // 이 함수를 호출하려면 객체가 존재해야 함. error
	void(*f3)() = &Dialog::Close2; // static 함수이기 때문에 가능함. 

	// 해결방법 - 멤버함수를 가리키는 포인터 변수 만드는 모양 - pointer to member
	void(Dialog::*f2)() = &Dialog::Close; 

	//f2(); // error - 객체가 없는 상태에서 호출되었기 때문에....

	Dialog dlg;
	//dlg.f2();  // f2라는 함수를 찾게된다. error임

	//dlg.*f2(); // *. :  pointer to member operator 연산자로 접근하면 호출 가능함. 연산자 우선순위 높이기 위해 ()를 사용해야 함. (dlg.*f2)();
	(dlg.*f2)(); //(&(dlg)->*f2)();  // ->* :  pointer to member operator 임.

	// c++진영에서 함수 호출이 다양하게 방식이 생겨 통일하는 차원에서 invoke라는 함수 제공
	std::invoke(f1); // f1함수 호출
	//std::invoke(f1, 10, 20); f1(10, 20)
	std::invoke(f2, &dlg); // (dlg.*f2)()
	// std::invode(f2, &dlg, 10, 20); // (dlg.*f2)(10, 20);

	//invoke()함수는 멤버함수가 아닐때랑 멤버함수일때랑 다르게 호출됨.... 분기가 되어 있음. cppreference.com에서 invoke 찾아보면 분기되어 있음.

}