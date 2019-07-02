#include <iostream>
#include <algorithm>
#include<memory>
#include<type_traits>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}
};

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, T value) : size(sz), capacity(sz)
	{
		// T�� ���  T[]�� ����Ϸ���  T�� Default�����ڰ� �־�� ��.103p ������ �̷��� ���� ����
		// buff = new T[sz]; 

		// solution : �޸� �Ҵ�� ������ ȣ���� �и���.
		// �޸� �Ҵ�
		buff = static_cast<T*>(operator new(sizeof(T)*size));

		// ������ ȣ��
		int cnt = 0;
		try
		{
			// buff ~ buff + 10 �� ������ �ִ� ��ü�� value�� ����ؼ� ���� ������ ȣ��
			// uninitialized_copy�Լ��� �� �ҽ������������ ���� ������ ȣ��� ��ŭ �Ҹ��ڸ� �ҷ� ��� ��.
			// cppreference.com ���� "uninitialized_fill_n" �˻�
			std::uninitialized_fill_n(buff, 10, value);
		}
		catch (...)
		{
			// �޸� ����
			operator delete(buff);
		}
	}
	~vector() {}
};

int main()
{
	//vector<Point> v(10); // default������ �ʿ���.

	Point p(0, 0);
	vector<Point> v(10, p);   //p�� �����ؼ� vector�� �Ѱ��ָ� �ʱ�ȭ �� ���� ���� �����ڸ� �̿��ؼ� 10�� �ʱ�ȭ �ϴµ� ���....
}