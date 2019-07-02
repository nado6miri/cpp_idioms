// 7_���� ������1 - 59page 
#include <exception>
#include <iostream>

// ���� ������ (Exception Safety)
// 1. �������� : ���ܰ� ����. ex) int n = 0; int* p = nullptr;
// 2. ���º��� : ���ܰ� ������ ��Ƽ� ó���ϸ� ��ü�� ���´� ���� �߻� ������ ���°� �ȴ�. ��� ��� �����ϴ�.
// 3. �⺻���� : ���ܰ� �߻��ص� ������ �ڿ� ������ ����. �� ��ü�� ���´� �� �� ����. ����� �� ����.

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
		People p = s.pop(p); // 1. s.pop() ȣ��,   2. People�� ��������� ȣ�� ==> ���⼭ ���ܰ� �߻��ϸ�..??
		*/
		People p = s.top(); // �����⸸. ���º����� ����...STL �� �⺻ ö��..
		s.pop(); // ���Ÿ�....
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// ���⼭ stack �� ��� ����ص� �ɱ�? �̹� index�� -- �߱� ������ �ٽ� ����Ϸ��� ++ ����� ��.
}

// STL�� ���ſ� ��ȯ�� ���ÿ� ���� �ʴ� ������ 
// 1. ���� �������� ���º����� ��Ű�� ����
// 2. ������ȯ�� ���ؼ� �ӽ� ��ü�� �����ϱ� ����...
