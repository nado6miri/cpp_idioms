#include <iostream>
#include <functional> // invoke

// �ٽ� 1. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ������ ����.
//     2. �Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҸ� ������ �ִ�.
//     3. ��� �Լ��� �����͸� ����� ����ϴ� ���.
//     4. C++ 17 invoke �Լ�.
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

	// ��� �Լ��� ����Ű�� ������ ���� ����� ���
	// pointer to member
	void(Dialog::*f2)() = &Dialog::Close; 
	
	//f2();  // error. ��ü�� ����.
	Dialog dlg;
	//dlg.f2();// f2��� �Լ��� ã�� �ȴ�. error.
	//dlg.*f2(); // .* :  pointer to memeber operator
				 // ->*
	(dlg.*f2)();
	((&dlg)->*f2)();

	// invoke : C++17 ���� �߰�.
	std::invoke(f1); // f1 �Լ� ȣ��.. 

	//invoke(f1, 10, 20); f1(10,20)
	std::invoke(f2, &dlg); // (dlg.*f2)() �� �ǹ�
	
	//invoke(f2, &dlg, 10, 20); // (dlg.*f2)(10,20);
}



