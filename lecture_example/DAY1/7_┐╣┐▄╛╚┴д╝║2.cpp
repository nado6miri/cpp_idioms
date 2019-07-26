// 7_예외안전성1 - 59 page 관련 이야기
#include <exception>
#include <iostream>




template<typename T> class Stack
{
	T buff[10];
	int idx = -1;
public:
	void push(const T& a) { buff[++idx] = a; }

	/*
	T    pop()
	{
		if (idx < 1)
			throw  std::out_of_range("stack empty");
		--idx;

		return buff[idx];
	}
	*/

	// 제거와 반환을 동시에 하면 강력 보장을 지킬수 없다.
	// 제거와 반환은 분리한다.
	T& top() { return buff[idx]; } // 반환만
	void pop() { --idx; }  // 제거만
};

// STL 이 제거와 반환을 동시에 하지 않은 이유

// 1. 예외 안전성의 강력보장을 지키기 위해
// 2. 참조반환을 통해서 임시객체를 제거하기 위해



class People {};

int main()
{
	Stack<People> s;

	People p;
	s.push(p);

	try
	{
		People p = s.top(); // 꺼내기만
		s.pop(); // 제거만

		//People p = s.pop(); // 1. s.pop() 호출
							// 2. People 의 복사 생성자 호출
							//    => 여기서 예외가 발생하면
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// 여기서 s를 계속 사용해도 될까 ?
}


