// 7_���� ������1 - 59page 
#include <exception>
#include <iostream>

// ���� ������ (Exception Safety)
// 1. �������� : ���ܰ� ����. ex) int n = 0; int* p = nullptr;
// 2. ���º��� : ���ܰ� ������ ��Ƽ� ó���ϸ� ��ü�� ���´� ���� �߻� ������ ���°� �ȴ�. ��� ��� �����ϴ�.
// 3. �⺻���� : ���ܰ� �߻��ص� ������ �ڿ� ������ ����. �� ��ü�� ���´� �� �� ����. ����� �� ����.

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
	// ���⼭ stack �� ��� ����ص� �ɱ�? �̹� index�� -- �߱� ������ �ٽ� ����Ϸ��� ++ ����� ��.
}