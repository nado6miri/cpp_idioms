#include <iostream>
#include <memory>
// C++ Programming language : C++ 창시자 책( stroustrub)

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
		//buff = new T[sz]; // 103 p. 이렇게 하지 말라.!
						// 이경우 T에는 반드시 디폴트 생성자가 필요하다

		// 1. 메모리 먼저 할당
		buff = static_cast<T*>(operator new(sizeof(T)*size));

		// 2. 생성자 호출
		int cnt = 0;
		try
		{
			for (; cnt < size; ++cnt)
			{
				//new(&buff[i]) T; // 디폴트 생성자 호출
				new(&buff[cnt]) T(value); // 복사 생성자 호출
			}
		}
		catch (...)
		{
			// 복사 생성자 호출중 예외가 발생한 경우.
			// 생성이 완료된 객체는 소멸자 호출
			for (int i = 0; i < cnt; i++)
				buff[i].~T();

			// 메모리 해지
			operator delete(buff);

			// 발생된 예외를 밖으로 전달
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
		//buff = new T[sz]; // 103 p. 이렇게 하지 말라.!
						// 이경우 T에는 반드시 디폴트 생성자가 필요하다

		// 1. 메모리 먼저 할당
		buff = static_cast<T*>(operator new(sizeof(T)*size));

		// 2. 생성자 호출
		try
		{
			// buff의 10개 의 공간에 있는 객체에
			// value를 사용해서 복사 생성자호출.
			// cppreference.com 에서 "uninitialized_fill_n" 검색
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
	vector<Point> v(10, p);   // Point 복사해오세요
}