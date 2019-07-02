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
		// T의 경우  T[]를 사용하려면  T에 Default생성자가 있어야 함.103p 에서는 이렇게 쓰지 말라
		// buff = new T[sz]; 

		// solution : 메모리 할당과 생성자 호출을 분리함.
		// 메모리 할당
		buff = static_cast<T*>(operator new(sizeof(T)*size));

		// 생성자 호출
		int cnt = 0;
		try
		{
			// buff ~ buff + 10 의 공간에 있는 객체에 value를 사용해서 복사 생성자 호출
			// uninitialized_copy함수는 전 소스에서만들었던 기존 생성자 호출된 만큼 소멸자를 불러 줘야 함.
			// cppreference.com 에서 "uninitialized_fill_n" 검색
			std::uninitialized_fill_n(buff, 10, value);
		}
		catch (...)
		{
			// 메모리 해지
			operator delete(buff);
		}
	}
	~vector() {}
};

int main()
{
	//vector<Point> v(10); // default생성자 필요함.

	Point p(0, 0);
	vector<Point> v(10, p);   //p를 생성해서 vector로 넘겨주면 초기화 된 값을 복사 생성자를 이용해서 10개 초기화 하는데 써라....
}