// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;
#include <map>

// 가상함수를 쓰지말고 CRTP 사용하여 class를 template으로 하고 typecasting 해서 호출 
template<typename T> class Window
{
	int hwnd;
	static std::map<int, Window*> this_map;

public:
	void Create()
	{
		hwnd = ec_make_window(&handler);

		// 윈도우 번호를 키값으로 this 보관
		this_map[hwnd] = this;
	}

	static int handler(int handle, int msg, int a, int b)
	{
		// 현재 윈도우 번호를 가지고 this를 얻어온다.
		Window* self = static_cast<T*>(this_map[handle]);

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->LButtonDown();
			break;
		case WM_KEYDOWN:
			self->KeyDown();
			break;
		}
		return 0;
	}
	void LButtonDown() {}
	void KeyDown() {}
};

template<typename T> std::map<int, Window<T>*> Window<T>::this_map;
//--------------------------------------------
class MyWindow : public Window<MyWindow>
{
public:
	void LButtonDown()
	{
		std::cout << "MyWindow LButtonDown" << std::endl;
	}
};

class MyWindow2 : public Window<MyWindow2>
{
public:
	void LButtonDown()
	{
		std::cout << "MyWindow2 LButtonDown" << std::endl;
	}
};

int main()
{
	MyWindow w;
	w.Create();
	ec_process_message();
}


