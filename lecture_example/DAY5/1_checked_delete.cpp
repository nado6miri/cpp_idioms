// 1_checked_delete    37page
#include <iostream>

class Test;  // 클래스 전방 선언
			 // 완전한 선언이 없어도 포인터 변수는 만들수 있다
			 // 불완전한 타입(incomplete type)

// check 후에 delete
void foo(Test* p)
{
	//sizeof(Test); // complete 타입만 크기를 구할수 있다.
	
	// 안드로이드 소스의 예전 버전에서 볼수 있었던 코드
	//enum { type_must_be_complete = sizeof(Test)};

	// C++11 이후에는 static assert 사용
	static_assert(sizeof(Test) > 0,
					"error, delete incomplete type");

	delete p;
}

class Test
{
public:
	Test()  { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }
};

int main()
{
	std::default_delete<int> df;

	Test* p = new Test;
	foo(p);
}
