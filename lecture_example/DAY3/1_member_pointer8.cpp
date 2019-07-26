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
// 일반 함수 포인터를 관리하는 클래스
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
	using HANDLER = void(T::*)(); // C++11. typedef와 유사
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

// Object Generator 라는 기술. 177 page
// 클래스 템플릿을 직접 사용하지 말고 함수 템플릿을 통해서 만들자
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
//	p1->Execute(); // foo() 실행

	Dialog dlg;
//	IAction* p2 = new MemberFunctionAction<Dialog>(	&Dialog::Close, &dlg);

	IAction* p1 = makeAction(&foo);
	IAction* p2 = makeAction(&Dialog::Close, &dlg);
	p1->Execute();
	p2->Execute();
}
// webkit 소스  source/wtf/wtf/scope.h 소스



/*
// 함수 템플릿
square<int>(3); // 정확한 표현.
square(3);      // 템플릿 인자 생략 가능.

// 클래스 템플릿
list<int> s(10, 3);
list s(10, 3); // C++17 부터는 템플릿 인자 생략가능.
			   // C++14까지는 반드시 표기해야 한다.
			   */




