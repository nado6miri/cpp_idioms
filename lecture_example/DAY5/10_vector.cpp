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
			// 메모리 재할당이 필요 없다.
			if (newSize < size)  // size 가 줄어들때
			{
				for (int i = size - 1; i >= newSize; i--)
					buff[i].~T();
			}
			else				// size 가 증가 할때
			{
				for (int i = size; i < newSize; i++)

					new ( &buff[i] ) T(value);  // 복사 생성자
			}
		}
		else
		{
			// 메모리 재할당이 필요하다. - 증가.
			// 1. 메모리만 먼저 할당
			T* temp = static_cast<T*>(
				operator new(sizeof(T) * newSize));

			// 2. 기존 버퍼내용 가져오기

			if ( std::is_trivially_copy_constructible_v<T> )
			{
				memcpy(temp, buff, sizeof(T) * size);
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					//temp[i] = buff[i]; // 대입연산자
					//new (&temp[i]) T(buff[i]);// 복사 생성자

					//new (&temp[i]) T(std::move(buff([i]));// move 생성자

					new (&temp[i]) T(std::move_if_noexcept(buff[i]))  ;
				}
			}
			// 새로 추가된 요소는 디폴트(또는 인자로받은 객체로 복사 생성)
			for (int i = size; i < newSize; i++)
			{
				new (&temp[i]) T(value);
			}

			// 기존 버퍼 제거
			for (int i = 0; i < size; i++)
				buff[i].~T();
			operator delete(buff);

			// 새로운 메모리를 버퍼에 연결
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
	v.resize(13);  // 이순간을 생각해 봅시다.
}

