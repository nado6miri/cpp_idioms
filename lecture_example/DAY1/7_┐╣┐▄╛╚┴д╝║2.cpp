// 7_���ܾ�����1 - 59 page ���� �̾߱�
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

	// ���ſ� ��ȯ�� ���ÿ� �ϸ� ���� ������ ��ų�� ����.
	// ���ſ� ��ȯ�� �и��Ѵ�.
	T& top() { return buff[idx]; } // ��ȯ��
	void pop() { --idx; }  // ���Ÿ�
};

// STL �� ���ſ� ��ȯ�� ���ÿ� ���� ���� ����

// 1. ���� �������� ���º����� ��Ű�� ����
// 2. ������ȯ�� ���ؼ� �ӽð�ü�� �����ϱ� ����



class People {};

int main()
{
	Stack<People> s;

	People p;
	s.push(p);

	try
	{
		People p = s.top(); // �����⸸
		s.pop(); // ���Ÿ�

		//People p = s.pop(); // 1. s.pop() ȣ��
							// 2. People �� ���� ������ ȣ��
							//    => ���⼭ ���ܰ� �߻��ϸ�
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// ���⼭ s�� ��� ����ص� �ɱ� ?
}


