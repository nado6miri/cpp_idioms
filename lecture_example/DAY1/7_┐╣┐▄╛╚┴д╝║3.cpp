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
	// ���� ����� ������ ���� ������
	String& operator=(const String& s)
	{
		// �ڽŰ� ������ ���(s1 = s1)
		if (&s == this) return *this;

		// �ڽ� ���� ����
		delete[] buff;

		// ���ο� ���� �Ҵ��� ���� ����
		buff = new char[strlen(s.buff) + 1]; // �޸� ������ ���ܹ߻�
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
		// �ڽŰ� ������ ���(s1 = s1)
		if (&s == this) return *this;

		//char* p = �޸� �Ҵ�;
		// 59 page �ҽ�
		// s�� ���� ���� �����. (copy)
		String temp(s); // RAII

		// s�� ���ۿ� �ڽ��� ���۸� ��ü �Ѵ�. swap
		temp.swap(*this);


		return *this;
	}
};

// SFINAE, int2type, enable_if,...



int main()
{
	String s1 = "hello";
	String s2 = "AAA";

	s1 = s2; // �� ���� ������ ���ô�.
}