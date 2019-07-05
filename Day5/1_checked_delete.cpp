// 1_checked_delete  37page
#include <iostream>

class Test; // class 전방선언 - 완전한 선언이 없도도 포인터 변수는 만들 수 있다. 불완전한 타입(incomplete type)

// check 후에 delete하자.
void foo(Test* p)
{
	//sizeof(Test); // complete 타입만 크기를 구할 수 있다.
	// 안드로이드 소스의 예전 버전에서 볼수 있는 코드
	//enum { type_must_be_complete = sizeof(Test) };

	//c++11이후 static assert 사용
	static_assert(sizeof(Test) > 0, "error, delete incomplete type type");
	delete p;
};

class Test
{
public:
	Test() { std::cout << __FUNCSIG__ << std::endl; };
	~Test() { std::cout << __FUNCSIG__ << std::endl; };
};


int main()
{
	std::default_delete<int> df;
	Test*p = new Test;
	foo(p);
}