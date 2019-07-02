// 7_예외 안전성1 - 59page 
#include <exception>
#include <iostream>

// 예외 안정성 (Exception Safety)
// 1. 완전보장 : 예외가 없다. ex) int n = 0; int* p = nullptr;
// 2. 강력보장 : 예외가 있지만 잡아서 처리하면 객체의 상태는 예외 발생 이전의 상태가 된다. 계속 사용 가능하다.
// 3. 기본보장 : 예외가 발생해도 잡으면 자원 누수는 없다. 단 객체의 상태는 알 수 없다. 사용할 수 없다.

template<typename T> class Stack
{
	int idx = 0;
public :
	void push(const T& a) { buff[idx++] = a; }
	T pop()
	{
		--idx;
		if (idx < 0)
			throw std::out_of_range("stack empty");
	}
};


int main()
{
	Stack<int> s;

	try 
	{
		s.pop();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// 여기서 stack 을 계속 사용해도 될까? 이미 index를 -- 했기 때문에 다시 사용하려면 ++ 해줘야 함.
}