#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;
};

/*
template<typename T>copy_type(T* d, T* s, size_t n)
{
	if (std::is_trivially_copy_constructible<T>::value)
	{
		memcpy(d, s, sizeof(T)*n);
	}
	else
	{
		// 복사 생성자가 하는 일이 있으면 각 요소에 대해서 복사 생성자 호출
		while (n--)
		{
			//new T; // 메모리 할당 + 생성자 호출
			//new T(*s); // 메모리 할당 + 복사 생성자 호출
			//new(d) T;	// d 메모리에 default생성자 호출
			new(d) T(*s); // d 메모리에 복사 생성자 호출
			++d, ++s;
		}
	}
}
*/

// 두개의 동일 템플릿이 존재하니 if_enable이용해서 분기 치면 됨.
template<typename T>
typename std::enable_if<std::is_trivially_copy_constructible<T>::value>::type
copy_type(T* d, T* s, size_t n)
{
	memcpy(d, s, sizeof(T)*n);
}

template<typename T>
typename std::enable_if<!std::is_trivially_copy_constructible<T>::value>::type
copy_type(T* d, T* s, size_t n)
{
	// 복사 생성자가 하는 일이 있으면 각 요소에 대해서 복사 생성자 호출
	while (n--)
	{
		//new T; // 메모리 할당 + 생성자 호출
		//new T(*s); // 메모리 할당 + 복사 생성자 호출
		//new(d) T;	// d 메모리에 default생성자 호출
		new(d) T(*s); // d 메모리에 복사 생성자 호출
		++d, ++s;
	}
}


int main()
{
	char s1[10] = "hello";
	char s2[10];

	strcpy(s2, s1); // 메모리 할당없고, 기존 메모리 복사

	// 위 함수는 char밖에 copy하지 못하니 C++철학에 맞게 모든 type을 복사하는 함수를 만들어 보자
	copy_type(s2, s1, 10); 
}