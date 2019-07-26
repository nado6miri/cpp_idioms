#include <iostream>
#include <functional> // invoke

// 핵심 1. 일반 함수 포인터에 멤버 함수의 주소를 넣을수 없다.
//     2. 일반 함수 포인터에 static 멤버 함수의 주소를 넣을수 있다.
//     3. 멤버 함수의 포인터를 만들고 사용하는 방법.
//     4. C++ 17 invoke 함수.
class Dialog
{
public:
	void Close()  // void Close(Dialog* this)
	{ std::cout << "Close" << std::endl; }

	static void Close2() {}
};
void foo() { std::cout << "foo" << std::endl; }

int main()
{
	void(*f1)() = &foo; // ok
	//void(*f2)() = &Dialog::Close; // error
	void(*f3)() = &Dialog::Close2; // ok

	// 멤버 함수를 가리키는 포인터 변수 만드는 모양
	// pointer to member
	void(Dialog::*f2)() = &Dialog::Close; 
	
	//f2();  // error. 객체가 없다.
	Dialog dlg;
	//dlg.f2();// f2라는 함수를 찾게 된다. error.
	//dlg.*f2(); // .* :  pointer to memeber operator
				 // ->*
	(dlg.*f2)();
	((&dlg)->*f2)();

	// invoke : C++17 에서 추가.
	std::invoke(f1); // f1 함수 호출.. 

	//invoke(f1, 10, 20); f1(10,20)
	std::invoke(f2, &dlg); // (dlg.*f2)() 의 의미
	
	//invoke(f2, &dlg, 10, 20); // (dlg.*f2)(10,20);
}



