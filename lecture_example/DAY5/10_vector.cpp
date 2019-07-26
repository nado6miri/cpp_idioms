// 10_vector
#include <type_traits>
#include <cstdlib>
#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, T value = T()) : size(sz), capacity(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T)*size));
		try
		{
			std::uninitialized_fill_n(buff, 10, value);
		}
		catch (...)	{	operator delete(buff);		}
	}
	~vector()
	{
		for (int i = 0; i < size; i++)
			buff[i].~T();
		operator delete(buff);
	}

	void resize(size_t newSize, const T& value = T() )
	{
		if (capacity > newSize)
		{
			// �޸� ���Ҵ��� �ʿ� ����.
			if (newSize < size)  // size �� �پ�鶧
			{
				for (int i = size - 1; i >= newSize; i--)
					buff[i].~T();
			}
			else				// size �� ���� �Ҷ�
			{
				for (int i = size; i < newSize; i++)

					new ( &buff[i] ) T(value);  // ���� ������
			}
		}
		else
		{
			// �޸� ���Ҵ��� �ʿ��ϴ�. - ����.
			// 1. �޸𸮸� ���� �Ҵ�
			T* temp = static_cast<T*>(
				operator new(sizeof(T) * newSize));

			// 2. ���� ���۳��� ��������

			if ( std::is_trivially_copy_constructible_v<T> )
			{
				memcpy(temp, buff, sizeof(T) * size);
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					//temp[i] = buff[i]; // ���Կ�����
					//new (&temp[i]) T(buff[i]);// ���� ������

					//new (&temp[i]) T(std::move(buff([i]));// move ������

					new (&temp[i]) T(std::move_if_noexcept(buff[i]))  ;
				}
			}
			// ���� �߰��� ��Ҵ� ����Ʈ(�Ǵ� ���ڷι��� ��ü�� ���� ����)
			for (int i = size; i < newSize; i++)
			{
				new (&temp[i]) T(value);
			}

			// ���� ���� ����
			for (int i = 0; i < size; i++)
				buff[i].~T();
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
	//v.resize(7); // cap: 10, size : 7
	v.resize(13);  // �̼����� ������ ���ô�.
}

