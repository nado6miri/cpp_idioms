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


// 중요한 이야기
class Object
{
	Test data;
public:
	Object() {}
	//void setData(Test d) { data = d; } --> copy보다는 참조가 좋음 아래처럼...

	// setter 만들기 1.  const & - data = d;는 항상 복사 사용됨
	//void setData(const Test& d) { data = d; }
	//void setData(const Test& d) { data = std::move(d); } // 앞에 const가 붙어 있기 때문에 move를 하더라도 항상 복사가 됨. const는 move될 수 없다.

	// setter 2.  2개를 만들자.. const & 와 && 버전 2개 만들자... 
	//void setData(const Test& d) { data = d;  }  // const/lvalue 처리
	//void setData(Test&& d) { data = std::move(d); } // rvalue처리...

	// setter 3. call by value는 아주 나쁠까? - move 가 빠르다고 가정하면 call by  value 하나만 만들어도 됨...setter3 조건에서 복사대입, move대입 몇번 이루어 졌는지 확인
	//void setData(Test d) { data = std::move(d); }

	//setter 4. forwarding reference T&& 는 lvalue보내면 lvalue, rvalue 보내면 rvalue
	template<typename T> void setData(T&& d)
	{
		//data = d; // 1 무조건 복사
		//data = std::move(d); // 2 무조건 move
		data = std::forward<T>(d); //3 둘다 만족함. lvalue 보내면 복사, rvalue 보내면 이동
	}
	// 결론은 2개를 만드는 것이 가장 좋다.
};

int main()
{
	Object obj;
	Test data;
	obj.setData(data); // data를 계속 쓸 의도 - 복사 대입 1회 발생, setter3 에서는 복사생성 1회, move대입 1회
	obj.setData(std::move(data)); // move를 했기 때문에 계속 안쓸 의도. // move 대입 1회, setter3 에서는 move 생성 1회, move대입 1회
}