#include <iostream>
#include <vector>
#include <string>
#include <vector>


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


int main()
{
	Test t1;
	Test t2 = std::move(t2); //move - static_cast<Test&&>(t2) 로 casting됨

	// move 호출 ? copy 호출 ? -  copy호출... 이유는 const 는 자원 이동 불가 따라서 
	const Test t3;
	Test t4 = std::move(t3);  // static_cast<const Test&&>(t2) 로 casting됨 따라서 noexcept 문에서 copy 로 가게 됨
}