// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;
#include <map>


class Window;

struct MSG_ENTRY
{
	int message_num;
	void(Window::*handler)();
};

// 상속받아 virtual로 처리한다. - 90년대 방식
// parents 에서 1000개 virtual 선언하고 2개만 재정의 했다 하더라도 가상 테이블은 1000개 생성됨. --> 여기서 가상 테이블을 직접 만들자.
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


	// 아래 가상함수에서 처리할 메세지를 담은 배열을 반환해야 합니다.
	virtual MSG_ENTRY* GetMessageEntry()
	{
		return nullptr;
	}

	static int handler(int handle, int msg, int a, int b)
	{
		// 현재 윈도우 번호를 가지고 this를 얻어온다.
		Window* self = this_map[handle];
		if(self == nullptr) return 0;

		MSG_ENTRY* arr = self->GetMessageEntry();
		if (arr == nullptr) return 0;

		while (arr->handler != nullptr)
		{
			if (arr->message_num == msg)
			{
				void(Window::*f)() = arr->handler;
				(self->*f)(); // 멤버 함수를 함수 포인터로 호출하는 방법
			}
			++arr;
		}

		return 0;
	}
};

std::map<int, Window*> Window::this_map;

//--------------------------------------------

class MyWindow : public Window
{
public:
	virtual MSG_ENTRY* GetMessageEntry() override
	{
		using HANDLER = void(Window::*)();
		// 직접 만든 가상 테이블 - 소멸되지 않도록 static으로 생성함
		static MSG_ENTRY arr[] = {
			{ WM_LBUTTONDOWN, static_cast<HANDLER>(&MyWindow::LButtonDown) },
			{ WM_KEYDOWN, static_cast<HANDLER>(&MyWindow::foo) },
			{ 0, 0 }
		};
		return arr;
	}

	void LButtonDown()
	{
		std::cout << "MyWindow LButtonDown" << std::endl;
	}

	void foo()
	{
		std::cout << "MyWindow foo" << std::endl;
	}

};


int main()
{
	MyWindow w;
	w.Create();
	ec_process_message();
}


