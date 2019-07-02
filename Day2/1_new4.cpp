#include <iostream>
#include <algorithm>
#include<memory>
#include<type_traits>

// C++ Programming language : C++â���� å (stroustrub)
// vector ����� ��
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
			for (; cnt < size; ++cnt)
			{
				//new(&buff[cnt]) T; // �̰͵� default�����ڰ� �ʿ� ��.
				new(&buff[cnt]) T(value); // ���� ������ ȣ��.
				std::cout << "i = " << cnt << std::endl;
			}
		}
		catch (...)
		{
			// ���� ������ ȣ�� �� ���ܰ� �߻��� ��� ������ �Ϸ�� ��ü�� �Ҹ��� ȣ��
			for (int i = 0; i < cnt; i++)
			{
				buff[i].~T();
			}

			// �޸� ����
			operator delete(buff);

			// �߻��� ���ܸ� ������ ����
			throw;
		}
	}
};

int main()
{
	//vector<Point> v(10); // default������ �ʿ���.

	Point p(0, 0);
	vector<Point> v(10, p);   //p�� �����ؼ� vector�� �Ѱ��ָ� �ʱ�ȭ �� ���� ���� �����ڸ� �̿��ؼ� 10�� �ʱ�ȭ �ϴµ� ���....
}