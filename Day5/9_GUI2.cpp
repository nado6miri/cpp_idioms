// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // ī��(cafe.naver.com/cppmaster)�� �ֽ��ϴ�.
using namespace cppmaster;

// �Ʒ� c�ڵ带 c++�� �����ؼ� �پ��ϰ� event�� ó���� ����.
// handler ���忡�� window�� �����ؾ� ��.
/*
int handler(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
	case WM_KEYDOWN:  	 std::cout << "KEYDOWN" << hwnd << std::endl; break;
	}
	return 0;
}


int main()
{
	int h1 = ec_make_window(&handler);
	int h2 = ec_make_window(&handler);
	ec_process_message();
}
*/

class Window
{
	int hwnd;
public:
	void Create()
	{
		ec_make_window(&handler); // error�� - �Լ��� �Ķ����� �Լ��� ������. ��ü ���� ���̵� ȣ�� �����ϵ��� static ó��??
	}

	// �ٽ� 1. �Ʒ� �Լ��� �ݵ�� static ��� �Լ��� �Ǿ�� �մϴ�.
	static int handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
			case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
			case WM_KEYDOWN:  	 std::cout << "KEYDOWN" << hwnd << std::endl; break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.Create();  // �� ���� window�� �����Ǿ�� �մϴ�.
	ec_process_message();
}

