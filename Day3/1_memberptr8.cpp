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



template<typename T> class MemberFunctionAction : public IAction
{
	using HANDLER = void(T::*)(); // c++11, typdef와 유사함.
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


// Object Generator라는 기술
// 클래스 템플릿을 직접 사용하지 말고 함수 템플릿을 통해서 만들자.. 그러면 클래스 템플릿의 typename T를 생략할 수 있다.
// c++17에서는 클래스 템플릿에서도  tpyename 생략가능함. 맨 아래 주석 참조
template<typename T> IAction* makeAction(void(T::*handler)(), T* target)
{
	return new MemberFunctionAction<T>(handler, target);
}

// 클래스 템플릿은  makeAction을 쓰고 함수 템플릿은 다른걸 쓰면 일관성 없어 동일하게 함수 템플릿을 위해 만든다.
IAction* makeAction(void(*handler)())
{
	return new FunctionAction(handler);
}

int main()
{
	//IAction* p1 = new FunctionAction(&foo);
	IAction* p1 = makeAction(&foo);
	p1->Execute();  // foo() 실행

	Dialog dlg;
	//IAction* p2 = new MemberFunctionAction<Dialog>(&Dialog::Close, &dlg);// 이 부분이 사용하기 어려우니 간단히 만드는 방법을 알아보자
	IAction* p2 = makeAction(&Dialog::Close, &dlg);
	p2->Execute();
}

// webkit 소스 source/wtf/wtf/scope.h 소스 참조 .makeScopeExit() 함수...유사 패턴임.

/*
// 함수 템플릿
square<int>(3);  // 정확한 표현임
square(3);		 // 함수 템플릿 인자 생략 가능함. 3이 int이기 때문에 컴파일러가 이미 알고 있음

// 클래스 템플릿
list<int> s(10, 3);
list s(10, 3); // c++17 이전에는 클래스 템플릿 생각 불가능 - c++17부터는 템플릿 인자 생략 가능,  3이 int이기 때문에 컴파일러가 이미 알고 있음
*/