// 7_예외 안전성1 - 59page 
#include <exception>
#include <iostream>

// 예외 안정성 (Exception Safety)
// 1. 완전보장 : 예외가 없다. ex) int n = 0; int* p = nullptr;
// 2. 강력보장 : 예외가 있지만 잡아서 처리하면 객체의 상태는 예외 발생 이전의 상태가 된다. 계속 사용 가능하다.
// 3. 기본보장 : 예외가 발생해도 잡으면 자원 누수는 없다. 단 객체의 상태는 알 수 없다. 사용할 수 없다.

template<typename T> class Stack
{
	int idx = -1;
public:
	void push(const T& a) { buff[++idx] = a; }
	T& top() { return buff[idx]; }
	T pop() { --idx; }
};

class People {};


int main()
{
	Stack<int> s;

	People p;
	s.push(p);

	try
	{
		/*
		People p = s.pop(p); // 1. s.pop() 호출,   2. People의 복사생성자 호출 ==> 여기서 예외가 발생하면..??
		*/
		People p = s.top(); // 꺼내기만. 강력보장을 위해...STL 의 기본 철학..
		s.pop(); // 제거만....
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// 여기서 stack 을 계속 사용해도 될까? 이미 index를 -- 했기 때문에 다시 사용하려면 ++ 해줘야 함.
}

// STL이 제거와 반환을 동시에 하지 않는 이유는 
// 1. 예외 안정성의 강력보장을 지키기 위해
// 2. 참조변환을 통해서 임시 객체를 제거하기 위해...
