// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;

class Window
{
	int hwnd;
public:
	void Create()
	{
		hwnd = ec_make_window(&handler);
	}
	// 핵심 1. 아래 함수는 반드시 static 멤버 함수가 되어야 합니다.
	static int handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON" << std::endl; break;
		case WM_KEYDOWN:  	 std::cout << "KEYDOWN" << std::endl; break;
		}
		return 0;
	}
};
int main()
{
	Window w;
	w.Create();    // 이순간 윈도우가 생성되어야 합니다
	ec_process_message();
}


