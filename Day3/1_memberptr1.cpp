#include <iostream>
#include <functional>  // invoke

// �ٽ� 1. �Ϲ��Լ� �����Ϳ� ��� �Լ��� �ּҸ� ���� �� ����.
// 2. �Ϲ��Լ� �����Ϳ� static ����Լ��� �ּҸ� ���� �� �ִ�.
// 3. member �Լ��� �����͸� ����� ����ϴ� ���.
// 4. c++ 17 invoke �Լ�.

class Dialog
{
public:
	void Close()  // void Close(Dialog* this) �ǹ���.
	{ std::cout << "Close" << std::endl; }

	static void Close2() {}  // ���� static�Լ��� �߰��ߴٸ� ��ü ���� ������ ȣ�� ����
};

void foo() { std::cout << "foo" << std::endl; }

int main()
{
	void(*f1)() = &foo;  // void�� ��ȯ�ϰ� param�� ���� �Լ��� �����͸� �����ϰڴ�.
	//void(*f2)() = &Dialog::Close; // �� �Լ��� ȣ���Ϸ��� ��ü�� �����ؾ� ��. error
	void(*f3)() = &Dialog::Close2; // static �Լ��̱� ������ ������. 

	// �ذ��� - ����Լ��� ����Ű�� ������ ���� ����� ��� - pointer to member
	void(Dialog::*f2)() = &Dialog::Close; 

	//f2(); // error - ��ü�� ���� ���¿��� ȣ��Ǿ��� ������....

	Dialog dlg;
	//dlg.f2();  // f2��� �Լ��� ã�Եȴ�. error��

	//dlg.*f2(); // *. :  pointer to member operator �����ڷ� �����ϸ� ȣ�� ������. ������ �켱���� ���̱� ���� ()�� ����ؾ� ��. (dlg.*f2)();
	(dlg.*f2)(); //(&(dlg)->*f2)();  // ->* :  pointer to member operator ��.

	// c++�������� �Լ� ȣ���� �پ��ϰ� ����� ���� �����ϴ� �������� invoke��� �Լ� ����
	std::invoke(f1); // f1�Լ� ȣ��
	//std::invoke(f1, 10, 20); f1(10, 20)
	std::invoke(f2, &dlg); // (dlg.*f2)()
	// std::invode(f2, &dlg, 10, 20); // (dlg.*f2)(10, 20);

	//invoke()�Լ��� ����Լ��� �ƴҶ��� ����Լ��϶��� �ٸ��� ȣ���.... �бⰡ �Ǿ� ����. cppreference.com���� invoke ã�ƺ��� �б�Ǿ� ����.

}