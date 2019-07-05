// 9_GUI
// 상속받아 virtual로 처리한다. - 90년대 방식
// parents 에서 1000개 virtual 선언하고 2개만 재정의 했다 하더라도 가상 테이블은 1000개 생성됨. --> 여기서 가상 테이블을 직접 만들자.
// 구글에서 "wxWidget event table 을 검색해 보세요.. - virtual함수의 메모리 과다 소요 개선을 위해 나옴..
// 사용자에게는 실제 함수만 define하도록 함. 나머지는 감춤

#define USING_GUI
#include <iostream>
#include "cppmaster.h" 
using namespace cppmaster;
#include <map>


class Window;

struct MSG_ENTRY
{
	int message_num;
	void(Window::*handler)();
};

class Window
{
	int hwnd;
	static std::map<int, Window*> this_map;

public:
	void Create()
	{
		hwnd = ec_make_window(&handler);
		this_map[hwnd] = this;
	}


	// 아래 가상함수에서 처리할 메세지를 담은 배열을 반환해야 합니다.
	virtual MSG_ENTRY* GetMessageEntry() { return nullptr; }

	static int handler(int handle, int msg, int a, int b)
	{
		Window* self = this_map[handle];
		if (self == nullptr) return 0;

		MSG_ENTRY* arr = self->GetMessageEntry();
		if (arr == nullptr) return 0;

		while (arr->handler != nullptr)
		{
			if (arr->message_num == msg)
			{
				void(Window::*f)() = arr->handler;
				(self->*f)();
			}
			++arr;
		}
		return 0;
	}
};
std::map<int, Window*> Window::this_map;
//--------------------------------------------

#define DECLARE_EVENT_MAP()  \
	virtual MSG_ENTRY* GetMessageEntry() override;


// 함수 구현을 위한 매크로
#define BEGIN_EVENT_MAP(classname)	\
	MSG_ENTRY* classname::GetMessageEntry() 			\
	{													\
		using HANDLER = void(Window::*)();				\
		static MSG_ENTRY arr[] = {


#define ADD_EVENT(message, function) \
			{ message, static_cast<HANDLER>(function)},

#define END_EVENT_MAP()			\
			{ 0, 0 }			\
		};						\
		return arr;				\
	}


class MyWindow : public Window
{
public:
	DECLARE_EVENT_MAP()
	void LButtonDown() { std::cout << "MyWindow LButtonDown" << std::endl; }
	void foo() { std::cout << "foo" << std::endl; }
};
BEGIN_EVENT_MAP(MyWindow)
	ADD_EVENT(WM_LBUTTONDOWN, &MyWindow::LButtonDown)
END_EVENT_MAP()


int main()
{
	MyWindow w;
	w.Create();
	ec_process_message();
}


