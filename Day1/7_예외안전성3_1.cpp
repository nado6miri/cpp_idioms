#include<iostream>

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
		// 자신과 대입일 경우 (s1 = s1)
		if (&s == this) return *this;

		// 자신 버퍼 제거
		delete[] buff;

		// 새로운 버퍼 할당
		buff = new char[strlen(s.buff) + 1];  // 메모리 부족시 예외 발생함  - 예외 발생시 위에서 자신의 버퍼를 제거해 버렸기 때문에 문제 있음...
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
		char *temp = s.buff;
		s.buff = buff;
		buff = temp;
	}

	// 깊은 복사로 구현한 대입 연산자 - 
	String& operator=(const String& s)
	{
		// 자신과 대입일 경우 (s1 = s1)
		if (&s == this) return *this;

		// s 의 복사본을 만든다. RAII 기법  - COPY
		String temp(s);

		// s의 버퍼와 자신의 버퍼를 교체한다. - SWAP -------- COPY AND SWAP
		temp.swap(*this);

		return *this;
	}
}

int main()
{
	String s1 = "hello";
	String s2 = "AAA";
	s1 = s2; // 이때를 생각해 봅시다.
}