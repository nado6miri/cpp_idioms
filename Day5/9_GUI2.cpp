// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;

// 아래 c코드를 c++로 변경해서 다양하게 event를 처리해 보자.
// handler 입장에서 window를 구분해야 함.
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
		ec_make_window(&handler); // error남 - 함수의 파람으로 함수를 전달함. 객체 생성 없이도 호출 가능하도록 static 처리??
	}

	// 핵심 1. 아래 함수는 반드시 static 멤버 함수가 되어야 합니다.
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
	w.Create();  // 이 순간 window가 생성되어야 합니다.
	ec_process_message();
}

