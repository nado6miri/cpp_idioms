// new4 ���� vector �����ڸ� ������µ� resize / �Ҹ��ڸ� �߰��� ����.

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

	~vector()
	{
		for (int i = 0; i < size; i++)
		{
			buff[i].~T(); // �Ҹ��� ȣ��
		}
		operator delete(buff); // �޸� ����
	}

	void resize(size_t newSize, const T& value = T())
	{
		if (capacity > newSize) 
		{
			// �޸� �� �Ҵ��� �ʿ� ������
			if (newSize < size) // size�� �پ�鶧
			{
				// �Ҹ��ڸ� ȣ����.
				for (int i = size - 1; i >= newSize; i--)
				{
					buff[i].~T();
				}
			}
			else // size�� Ŀ����
			{
				for (int i = size; i < newSize; i++)
				{
					new(&buff[i]) T; // default �����ڰ� �־�� ��...���簡 �� ����. ���� resize�� param �߰� �ʿ� const T& value = T()
					new(&buff[i]) T(value) ; // ���簡 �� ����. ���� resize�� param �߰� �ʿ� const T& value = T() - ���� ���� �����̳ʸ� ����� ���� default �����ڰ� �ƴ� ���� �����ڸ� ����϶�.
				}
			}
		}
		else
		{
			// �޸� �� �Ҵ��� �ʿ� �Ҷ� - ����
			// 1. �޸𸮸� ���� �Ҵ�
			T* temp = static_cast<T*>(operator new(T) *newSize);

			// 2. ���� ���۳��� �������� 
			if (std::is_trivially_constructible_v<T>) // �����ڰ� �ʿ� ���ٴ� �׳�  memcopy�Ѵ�.??
			{
				memcpy(temp, buff, sizeof(T) * size);
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					//temp[i] = buff[i]; // ���Կ����� - ����� �� �������, ������ ���� �޸𸮸� �Ҵ�Ǿ� �ְ� ��ü�� �ȸ���� ���� ����ϸ� �ȵ�.
					//new (&temp[i]) T(buff[i]); // ���� ������ - ���ɹ�����... move�� �������...
					//new (&temp[i]) T(std::move(buff[i])); // move �����ڸ� ȣ������. --- ������ �ű�� exception �߻��ϸ� ?? -- ���� �Ʒ� �ڵ� ���
					new (&temp[i]) T(std::move_if_noexcept(buff[i]));
				}
			}
			// ���� �߰��� ��ҵ��� default ����(���� ���޹��� ���ڷ� ��ü�� ���� ����)
			for (int i = size; i < newSize; i++)
			{
				new (&temp[i]) T(value);
			}

			// ���� ���� ����
			for (int i = 0; i < size; i++)
			{
				buff[i].~T();
			}
			operator delete(buff);

			// ���ο� �޸𸮸� ���ۿ� ����
			buff = temp;
			size = newSize;
			capacity = newSize;
		}
	}
};

int main()
{
	vector<int> v(10);
	v.resize(7); // capacity : 10, size : 7
	v.resize(5); // 7 -> 5 : �Ҹ��� ȣ�� �ʿ�
	v.resize(8); // 5 -> 8 : ������ ȣ�� �ʿ� (�����̳ʿ����� default�� �ƴ� ���� ������)
	v.resize(13); // 8 -> 13 : 
}