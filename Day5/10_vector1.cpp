// new4 에서 vector 생성자만 만들었는데 resize / 소멸자를 추가해 보자.

#include <iostream>
#include <algorithm>
#include<memory>
#include<type_traits>

// C++ Programming language : C++창시자 책 (stroustrub)
// vector 만드는 법
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
		// T의 경우  T[]를 사용하려면  T에 Default생성자가 있어야 함.103p 에서는 이렇게 쓰지 말라
		// buff = new T[sz]; 

		// solution : 메모리 할당과 생성자 호출을 분리함.
		// 메모리 할당
		buff = static_cast<T*>(operator new(sizeof(T)*size));

		// 생성자 호출
		int cnt = 0;
		try
		{
			for (; cnt < size; ++cnt)
			{
				//new(&buff[cnt]) T; // 이것도 default생성자가 필요 함.
				new(&buff[cnt]) T(value); // 복사 생성자 호출.
				std::cout << "i = " << cnt << std::endl;
			}
		}
		catch (...)
		{
			// 복사 생성자 호출 중 예외가 발생한 경우 생성이 완료된 객체는 소멸자 호출
			for (int i = 0; i < cnt; i++)
			{
				buff[i].~T();
			}

			// 메모리 해지
			operator delete(buff);

			// 발생된 예외를 밖으로 전달
			throw;
		}
	}

	~vector()
	{
		for (int i = 0; i < size; i++)
		{
			buff[i].~T(); // 소멸자 호출
		}
		operator delete(buff); // 메모리 해제
	}

	void resize(size_t newSize, const T& value = T())
	{
		if (capacity > newSize) 
		{
			// 메모리 재 할당이 필요 없을때
			if (newSize < size) // size가 줄어들때
			{
				// 소멸자만 호출함.
				for (int i = size - 1; i >= newSize; i--)
				{
					buff[i].~T();
				}
			}
			else // size가 커질때
			{
				for (int i = size; i < newSize; i++)
				{
					new(&buff[i]) T; // default 생성자가 있어야 함...복사가 더 낫다. 따라서 resize에 param 추가 필요 const T& value = T()
					new(&buff[i]) T(value) ; // 복사가 더 낫다. 따라서 resize에 param 추가 필요 const T& value = T() - 복사 생성 컨테이너를 만들시 절대 default 생성자가 아닌 복사 생성자를 사용하라.
				}
			}
		}
		else
		{
			// 메모리 재 할당이 필요 할때 - 증가
			// 1. 메모리만 먼저 할당
			T* temp = static_cast<T*>(operator new(T) *newSize);

			// 2. 기존 버퍼내용 가져오기 
			if (std::is_trivially_constructible_v<T>) // 생성자가 필요 없다는 그냥  memcopy한다.??
			{
				memcpy(temp, buff, sizeof(T) * size);
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					//temp[i] = buff[i]; // 대입연산자 - 만들어 져 있을경우, 지금의 경우는 메모리만 할당되어 있고 객체는 안만들어 져서 사용하면 안됨.
					//new (&temp[i]) T(buff[i]); // 복사 생성자 - 성능문제로... move를 사용하자...
					//new (&temp[i]) T(std::move(buff[i])); // move 생성자를 호출하자. --- 하지만 옮기다 exception 발생하면 ?? -- 따라서 아래 코드 사용
					new (&temp[i]) T(std::move_if_noexcept(buff[i]));
				}
			}
			// 새로 추가된 요소들은 default 생성(새로 전달받은 인자로 객체에 복사 생성)
			for (int i = size; i < newSize; i++)
			{
				new (&temp[i]) T(value);
			}

			// 기존 버퍼 제거
			for (int i = 0; i < size; i++)
			{
				buff[i].~T();
			}
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
	v.resize(7); // capacity : 10, size : 7
	v.resize(5); // 7 -> 5 : 소멸자 호출 필요
	v.resize(8); // 5 -> 8 : 생성자 호출 필요 (컨테이너에서는 default가 아닌 복사 생성자)
	v.resize(13); // 8 -> 13 : 
}