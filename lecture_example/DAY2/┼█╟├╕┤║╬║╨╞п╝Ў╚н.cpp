// 템플릿부분특수화

#include <iostream>

// primary template
template<typename T> class Stack
{
public:
	void push(T a) { std::cout << "T" << std::endl; }
};
// partial specialization
template<typename T> class Stack<T*>
{
public:
	void push(T* a) { std::cout << "T*" << std::endl; }
};
// specialization
template<> class Stack<char*>
{
public:
	void push(char* a) { std::cout << "char*" << std::endl; }
};

int main()
{
	Stack<int>   s1; s1.push(0);
	Stack<int*>  s2; s2.push(0);
	Stack<char*> s3; s3.push(0);
}
