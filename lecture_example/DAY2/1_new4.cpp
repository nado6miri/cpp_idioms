#include <iostream>
#include <memory>
// C++ Programming language : C++ â���� å( stroustrub)

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b){}
};
/*
template<typename T> class vector 
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, T value = T() ) : size(sz), capacity(sz)
	{
		//buff = new T[sz]; // 103 p. �̷��� ���� ����.!
						// �̰�� T���� �ݵ�� ����Ʈ �����ڰ� �ʿ��ϴ�

		// 1. �޸� ���� �Ҵ�
		buff = static_cast<T*>(operator new(sizeof(T)*size));

		// 2. ������ ȣ��
		int cnt = 0;
		try
		{
			for (; cnt < size; ++cnt)
			{
				//new(&buff[i]) T; // ����Ʈ ������ ȣ��
				new(&buff[cnt]) T(value); // ���� ������ ȣ��
			}
		}
		catch (...)
		{
			// ���� ������ ȣ���� ���ܰ� �߻��� ���.
			// ������ �Ϸ�� ��ü�� �Ҹ��� ȣ��
			for (int i = 0; i < cnt; i++)
				buff[i].~T();

			// �޸� ����
			operator delete(buff);

			// �߻��� ���ܸ� ������ ����
			throw;
		}
	}
};
*/
template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, T value = T()) : size(sz), capacity(sz)
	{
		//buff = new T[sz]; // 103 p. �̷��� ���� ����.!
						// �̰�� T���� �ݵ�� ����Ʈ �����ڰ� �ʿ��ϴ�

		// 1. �޸� ���� �Ҵ�
		buff = static_cast<T*>(operator new(sizeof(T)*size));

		// 2. ������ ȣ��
		try
		{
			// buff�� 10�� �� ������ �ִ� ��ü��
			// value�� ����ؼ� ���� ������ȣ��.
			// cppreference.com ���� "uninitialized_fill_n" �˻�
			std::uninitialized_fill_n(buff, 10, value);
		}
		catch (...)
		{
			operator delete(buff);
		}
	}
	~vector()
	{

	}
};
int main()
{
	Point p(0, 0);
	vector<Point> v(10, p);   // Point �����ؿ�����
}