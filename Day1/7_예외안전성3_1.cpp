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
	// ���� ����� ������ ���� ������
	String& operator=(const String& s)
	{
		// �ڽŰ� ������ ��� (s1 = s1)
		if (&s == this) return *this;

		// �ڽ� ���� ����
		delete[] buff;

		// ���ο� ���� �Ҵ�
		buff = new char[strlen(s.buff) + 1];  // �޸� ������ ���� �߻���  - ���� �߻��� ������ �ڽ��� ���۸� ������ ���ȱ� ������ ���� ����...
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

	// ���� ����� ������ ���� ������ - 
	String& operator=(const String& s)
	{
		// �ڽŰ� ������ ��� (s1 = s1)
		if (&s == this) return *this;

		// s �� ���纻�� �����. RAII ���  - COPY
		String temp(s);

		// s�� ���ۿ� �ڽ��� ���۸� ��ü�Ѵ�. - SWAP -------- COPY AND SWAP
		temp.swap(*this);

		return *this;
	}
}

int main()
{
	String s1 = "hello";
	String s2 = "AAA";
	s1 = s2; // �̶��� ������ ���ô�.
}