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

// 중요한 이야기
class Object
{
	Test data;
public:
	Object() {}
	//void setData(Test d) { data = d; }

	// setter 만들기 1. const &  -항상 복사 사용
	// void setData(const Test& d) { data = d; }
	// 아래 코드는 역시 항상 복사(const 는 move 될수 없다.)
	// void setData(const Test& d) { data = std::move(d); }

	// setter 2. 2개를 만들자
	// const & 버전과 && 버전으로 2개 만들자
	//void setData(const Test& d)  { data = d; }
	//void setData(Test&& d) { data = std::move(d); }

	// setter 3. call by value 는 아주 나쁠까 ?
	// void  setData(Test d) { data = std::move(d); }

	// setter 4. forwarding reference
	template<typename T> void setData(T&& d)
	{
	//	data = d; // 1   무조건 복사
	//	data = std::move(d); // 2 무조건 move
		data = std::forward<T>(d); // 3
	}
};

int main()
{
	Object obj;

	Test data;


	obj.setData(data);			// 복사 대입 1회
								// 복사 생성 1회, move 대입 1회
	obj.setData(std::move(data));// move 대입 1회
								 // move 생성 1회, move대입 1회
}






