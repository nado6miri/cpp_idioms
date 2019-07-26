// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;
#include <map>
// 핵심 2. this를 자료구조에 보관하는 기술
template<typename T> class Window
{
	int hwnd;
	static std::map<int, Window*> this_map;
public:
	void Create()
	{
		hwnd = ec_make_window(&handler);
		this_map[hwnd] = this;
	}

	static int handler(int handle, int msg, int a, int b)
	{
		T* self = static_cast<T*>(this_map[handle]);

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
template<typename T> 
std::map<int, Window<T>*> Window<T>::this_map;

//--------------------------------------------
class MyWindow : public Window<MyWindow>
{
public:
	void LButtonDown()	{	std::cout << "MyWindow LButtonDown" << std::endl;	}
};

int main()
{
	MyWindow w;
	w.Create();
	ec_process_message();
}


