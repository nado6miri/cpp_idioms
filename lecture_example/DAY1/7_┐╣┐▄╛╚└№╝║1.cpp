// 7_���ܾ�����1 - 59 page ���� �̾߱�
#include <exception>
#include <iostream>


// ���� ������( exception safety)
// 1. ���� ���� : ���ܰ� ����.   ex) int n = 0   int* p = nullptr

// 2. ���� ���� : ���ܰ� ������ ��Ƽ� ó���ϸ�
//			     ��ü�� ���´� ���� �߻� ���� ���°� �ȴ�.
//				 ��� ��밡���ϴ�.

// 3. �⺻ ���� : ���ܰ� �߻��ص� ������ �ڿ� ������ ����.
//			     ��, ��ü�� ���´� �˼� ����. ����Ҽ� ����.





template<typename T> class Stack
{
	T buff[10];
	int idx = 0;
public:
	void push(const T& a) { buff[idx++] = a; }
	T    pop()
	{
		--idx;

		if (idx < 0)
			throw  std::out_of_range("stack empty");

		return buff[idx];
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
	// ���⼭ s�� ��� ����ص� �ɱ� ?
}


