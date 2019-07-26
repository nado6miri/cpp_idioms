#include <iostream>
#include <string>
#include <vector>

// noexcept 지시어 : 함수가 예외가 없음(있음)을 알리는 것
// void foo() noexcept
// void foo() noexcept(true)
// void foo() noexcept(false)

// noexcept 연산자 : 표현식이 예외가 있는지 조사하는것
// bool b = noexcept(foo())
// bool b = noexcept(T())
// bool b = noexcept(T(T()))



class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {}
	~Test() {}
	Test(const Test& t) : data(t.data), s(t.s) { std::cout << __FUNCSIG__ << std::endl; }

	Test& operator=(const Test& t)
	{
		data = t.data;
		s = t.s;

		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}





	// move 와 예외
	// move 계열 함수를 만들때는 예외가 나오지 않게 만들고
	// 예외가 없다고 꼭 컴파일러에게 알려 주자!
	// noexcept : 예외가 없다는 의미
	// noexcept(true) : 예외가 없다.
	// noexcept(false) : 예외가 있을수 있다.

	// sizeof(표현식) : 표현식 크기
	// decltype(표현식) : 표현식 타입
	// noexcept(표현식) : 표현식의 예외 여부 조사.

//	Test(Test&& t) noexcept ( 
//		noexcept( std::string(std::string())) : data(t.data), s(std::move(t.s))

	Test(Test&& t) noexcept (
		std::is_nothrow_move_constructible<std::string>::value) : data(t.data), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	Test& operator=(Test&& t) noexcept (
		std::is_move_assignable<std::string>::value)
	{
		data = t.data;
		s = std::move(t.s);

		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
};

// move와 알고리즘
// move 에서 알아야 하는 것
// 1. 클래스 만들때 move 계열 함수 2개를 만드는 법
// 2. 일반 알고리즘 구현할때 move() 를 사용해서 옮기는 것이 빠른경우
//    가 있다.

template<typename T> void Swap(T& a, T& b)
{
//	T tmp = a;
//	a = b;
//	b = tmp;

	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
int main()
{
	Test t1, t2;
	Swap(t1, t2);
}



