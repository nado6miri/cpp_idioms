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

int main()
{
	std::vector<Test> v(5);
	std::cout << "------------" << std::endl;
	// vector는 size를 늘릴시 move가 불리는게 효과적일것 같으나 중간에 예외 나오면 복구가 안됨 따라서 복사 생성자가 불림 - 실제 실행해 보면 복사생성자 불림.
	// 강력보장이 안됨 따라서 STL에서는 이 조건에서 move를 안씀
	// noxcept로 예외가 없다고 명시하면 move생성자 호출됨.
	v.resize(7); // noexcept 여부에 따르 복사 또는 move를 사용하기 때문에  move_if_noexept 를 이용해서 구현되어 있음.
	std::cout << "------------" << std::endl;

	Test t1;
	Test t2 = t1; // 무조건 복사 생성자 사용
	Test t3 = std::move(t2); // 무조건 move생성자 사용 - 예외가 있어도 사용, 단지, 캐스팅일뿐...static_cast<Test&&>(t2)
	Test t4 = std::move_if_noexcept(t3); // move생성자의 예외여부 조사, 예외가 없으면 move사용, 있으면 복사 생성자 사용

}