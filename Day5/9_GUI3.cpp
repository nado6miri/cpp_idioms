// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;

#include <map>

// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;
#include <map>


// 상속받아 virtual로 처리한다. - 90년대 방식
// parents 에서 1000개 virtual 선언하고 2개만 재정의 했다 하더라도 가상 테이블은 1000개 생성됨. --> gui4 에서 가상 테이블을 직접 만들자.
class Window
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
		Window* self = this_map[handle];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->LButtonDown();   // this->LButtonDown()
			break;
		case WM_KEYDOWN:
			self->KeyDown();
			break;
		}
		return 0;
	}
	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};
std::map<int, Window*> Window::this_map;
//--------------------------------------------
class MyWindow : public Window
{
public:
	virtual void LButtonDown() override
	{
		std::cout << "MyWindow LButtonDown" << std::endl;
	}
};
int main()
{
	MyWindow w;
	w.Create();
	ec_process_message();
}


