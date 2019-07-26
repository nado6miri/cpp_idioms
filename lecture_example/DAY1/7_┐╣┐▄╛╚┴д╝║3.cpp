#include <iostream>

class String
{
	char* buff;
public:
	String(const char* s) 
	{
		buff = new char[strlen(s) + 1];
		strcpy(buff, s);
	}
	~String() { delete[] buff; }

	/*
	// 깊은 복사로 구현한 대입 연산자
	String& operator=(const String& s)
	{
		// 자신과 대입일 경우(s1 = s1)
		if (&s == this) return *this;

		// 자신 버퍼 제거
		delete[] buff;

		// 새로운 버퍼 할당후 깊은 복사
		buff = new char[strlen(s.buff) + 1]; // 메모리 부족시 예외발생
		strcpy(buff, s.buff);		

		return *this;
	}
*/
	String(const String& s)
	{
		buff = new char[strlen(s.buff) + 1];
		strcpy(buff, s.buff);
	}
	void swap(String& s)
	{
		char* temp = s.buff;
		s.buff = buff;
		buff = temp;
	}

	String& operator=(const String& s)
	{
		// 자신과 대입일 경우(s1 = s1)
		if (&s == this) return *this;

		//char* p = 메모리 할당;
		// 59 page 소스
		// s의 복사 본을 만든다. (copy)
		String temp(s); // RAII

		// s의 버퍼와 자신의 버퍼를 교체 한다. swap
		temp.swap(*this);


		return *this;
	}
};

// SFINAE, int2type, enable_if,...



int main()
{
	String s1 = "hello";
	String s2 = "AAA";

	s1 = s2; // 이 때를 생각해 봅시다.
}