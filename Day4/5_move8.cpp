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


// move와 알고리즘
// move에서 알아야 하는 것
// 1. 클래스를 만들때 move계열 함수 2개를 만드는 방법
// 2. 일반 알고리즘을 구현할때 move()를 사용해서 옮기는 것이 가장 빠른경우가 있다.
template<typename T> void Swap(T& a, T& b)
{
	/*
	//swap은 깊은 복사를 3번 하는 구조로 되어 있어서 효율적으로 swap을 해야 함.
	T tmp = a;
	a = b;
	b = tmp;
	*/

	// 효율적으로 swap하는 방법
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	Test t1, t2;
	Swap(t1, t2);
}