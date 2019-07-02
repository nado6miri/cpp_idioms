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
};

int main()
{
	//vector<Point> v(10); // default생성자 필요함.

	Point p(0, 0);
	vector<Point> v(10, p);   //p를 생성해서 vector로 넘겨주면 초기화 된 값을 복사 생성자를 이용해서 10개 초기화 하는데 써라....
}