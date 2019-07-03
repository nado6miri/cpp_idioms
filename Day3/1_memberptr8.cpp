#include <iostream>

void foo() { std::cout << "foo" << std::endl; }

class Dialog
{
public:
	void Close() { std::cout << "Dialog Close" << std::endl; }
};

struct IAction
{
	virtual void Execute() = 0;
	virtual ~IAction() {}
};

// �Ϲ� �Լ� �����͸� �����ϴ� Ŭ����
class FunctionAction : public IAction
{
	typedef void(*HANDLER)();
	HANDLER handler;

public:
	FunctionAction(HANDLER h) : handler(h) {}

	virtual void Execute() override
	{
		handler();
	}
};



template<typename T> class MemberFunctionAction : public IAction
{
	using HANDLER = void(T::*)(); // c++11, typdef�� ������.
	HANDLER handler;
	T* target;
public:
	MemberFunctionAction(HANDLER h, T* t) : handler(h), target(t)
	{

	}

	virtual void Execute() override
	{
		(target->*handler)();
	}
};


// Object Generator��� ���
// Ŭ���� ���ø��� ���� ������� ���� �Լ� ���ø��� ���ؼ� ������.. �׷��� Ŭ���� ���ø��� typename T�� ������ �� �ִ�.
// c++17������ Ŭ���� ���ø�������  tpyename ����������. �� �Ʒ� �ּ� ����
template<typename T> IAction* makeAction(void(T::*handler)(), T* target)
{
	return new MemberFunctionAction<T>(handler, target);
}

// Ŭ���� ���ø���  makeAction�� ���� �Լ� ���ø��� �ٸ��� ���� �ϰ��� ���� �����ϰ� �Լ� ���ø��� ���� �����.
IAction* makeAction(void(*handler)())
{
	return new FunctionAction(handler);
}

int main()
{
	//IAction* p1 = new FunctionAction(&foo);
	IAction* p1 = makeAction(&foo);
	p1->Execute();  // foo() ����

	Dialog dlg;
	//IAction* p2 = new MemberFunctionAction<Dialog>(&Dialog::Close, &dlg);// �� �κ��� ����ϱ� ������ ������ ����� ����� �˾ƺ���
	IAction* p2 = makeAction(&Dialog::Close, &dlg);
	p2->Execute();
}

// webkit �ҽ� source/wtf/wtf/scope.h �ҽ� ���� .makeScopeExit() �Լ�...���� ������.

/*
// �Լ� ���ø�
square<int>(3);  // ��Ȯ�� ǥ����
square(3);		 // �Լ� ���ø� ���� ���� ������. 3�� int�̱� ������ �����Ϸ��� �̹� �˰� ����

// Ŭ���� ���ø�
list<int> s(10, 3);
list s(10, 3); // c++17 �������� Ŭ���� ���ø� ���� �Ұ��� - c++17���ʹ� ���ø� ���� ���� ����,  3�� int�̱� ������ �����Ϸ��� �̹� �˰� ����
*/