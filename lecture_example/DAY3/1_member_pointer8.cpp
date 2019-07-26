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


template<typename T>
class MemberFunctionAction : public IAction
{
	using HANDLER = void(T::*)(); // C++11. typedef�� ����
	HANDLER handler;
	T* target;
public:
	MemberFunctionAction(HANDLER h, T* t)
		: handler(h), target(t) {}

	virtual void Execute() override
	{
		(target->*handler)();
	}
};

// Object Generator ��� ���. 177 page
// Ŭ���� ���ø��� ���� ������� ���� �Լ� ���ø��� ���ؼ� ������
template<typename T> 
IAction* makeAction(void(T::*handler)(), T* target)
{
	return new MemberFunctionAction<T>(handler, target);
}

IAction* makeAction(void(*handler)())
{
	return new FunctionAction(handler);
}

int main()
{
//	IAction* p1 = new FunctionAction(&foo);
//	p1->Execute(); // foo() ����

	Dialog dlg;
//	IAction* p2 = new MemberFunctionAction<Dialog>(	&Dialog::Close, &dlg);

	IAction* p1 = makeAction(&foo);
	IAction* p2 = makeAction(&Dialog::Close, &dlg);
	p1->Execute();
	p2->Execute();
}
// webkit �ҽ�  source/wtf/wtf/scope.h �ҽ�



/*
// �Լ� ���ø�
square<int>(3); // ��Ȯ�� ǥ��.
square(3);      // ���ø� ���� ���� ����.

// Ŭ���� ���ø�
list<int> s(10, 3);
list s(10, 3); // C++17 ���ʹ� ���ø� ���� ��������.
			   // C++14������ �ݵ�� ǥ���ؾ� �Ѵ�.
			   */




