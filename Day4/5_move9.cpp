#include <iostream>
#include <vector>
#include <string>
#include <vector>


// sizeof()
// decltype()

// nonexcept 지시어 : 함수가 예외가 없음(있음)을 알리는 것
// void foo() noexcept
// void foo() noexcept(true)
// void foo() noexcept(false)

// noexcept 연산자 : 표현식에 예외가 있는지 조사하는것
// bool b = noexcept(foo())
// bool b = noexcept(T()) //default 생성자가 예외가 있는지 없는지 확인
// bool b = noexcept(T(T()))



class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {} // resource = new int;
	~Test() { std::cout << __FUNCSIG__ << std::endl; } // 소멸자

	Test(const Test& t) : data(t.data), s(t.s) { std::cout << __FUNCSIG__ << std::endl; } // 복사생성자

	// 대입 연산자
	Test& operator=(const Test& t)
	{
		data = t.data;
		s = t.s;
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}

	// move 생성자 -move 생성자에서는 모든 멤버를 반드시 move로 옮기자
	// move 예외
	// move 계열 함수를 만들때는 예외가 나오지 않게 만들고, 예외가 없다고 꼭 컴파일러에게 알려주자. (noexcept)
	// noexcept : 예외가 없다는 의미
	// noexcept(true) : 예외가 없다.
	// noexcept(false) : 예외가 있을 수 있다.

	//Test(Test&& t) noexcept(std::string(std::string())) : data(t.data), s(std::move(t.s))
	Test(Test&& t) noexcept(std::is_nothrow_move_constructible<std::string>::value) : data(t.data), s(std::move(t.s))
		//Test(Test&& t) : data(t.data), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	// move 대입 연산자
	Test& operator=(const Test&& t) noexcept(std::is_nothrow_move_assignable<std::string>::value)
		//Test& operator=(const Test&& t)
	{
		data = t.data;
		s = std::move(t.s);
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
};


// 1. 사용자가 복사와 move를 모두 제공하지 않으면 ==> 컴파일러가 모두 제공해 준다.
// 2. 사용자가 복사계열 함수를 제공하면 컴파일러는 move계열을 제공하지 않는다.
// 결론 : 복사 생성자를 만들지 말아라... 하지만 동적 할당 char *를 하게 되면 복사 생성자를 만들어야 함. 따라서 string 을 사용해라..
// 따라서  class 안에서 raw pointer를 사용하지 마라. .그러면 복사 생성자를 만들 필요가 없다...
// rule of zefo :  사용자가 직접 자원을 관리하지 않으면 소멸자, 복사계열 2개, Move 계열 2개를 만들 필요 없다. 컴파일러가 모두 제공.
class Object
{
	Test data;
	// char *s;
	std::string s;
public:
	Object() {}; // 
	Object(const Object& o) : data(o.data) {} // 사용자가 복사 생성자를 만들었다. 컴파일러 입장에서는  ㅡmove생성자를 만들 수 없다. 이 경우 둘다 복사가 됨.
};

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = std::move(o2);
}