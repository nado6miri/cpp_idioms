// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // ī��(cafe.naver.com/cppmaster)�� �ֽ��ϴ�.
using namespace cppmaster;
#include <map>


class Window;

struct MSG_ENTRY
{
	int message_num;
	void(Window::*handler)();
};

// ��ӹ޾� virtual�� ó���Ѵ�. - 90��� ���
// parents ���� 1000�� virtual �����ϰ� 2���� ������ �ߴ� �ϴ��� ���� ���̺��� 1000�� ������. --> ���⼭ ���� ���̺��� ���� ������.
class Window
{
	int hwnd;
	static std::map<int, Window*> this_map;

public:
	void Create()
	{
		hwnd = ec_make_window(&handler);

		// ������ ��ȣ�� Ű������ this ����
		this_map[hwnd] = this;
	}


	// �Ʒ� �����Լ����� ó���� �޼����� ���� �迭�� ��ȯ�ؾ� �մϴ�.
	virtual MSG_ENTRY* GetMessageEntry()
	{
		return nullptr;
	}

	static int handler(int handle, int msg, int a, int b)
	{
		// ���� ������ ��ȣ�� ������ this�� ���´�.
		Window* self = this_map[handle];
		if(self == nullptr) return 0;

		MSG_ENTRY* arr = self->GetMessageEntry();
		if (arr == nullptr) return 0;

		while (arr->handler != nullptr)
		{
			if (arr->message_num == msg)
			{
				void(Window::*f)() = arr->handler;
				(self->*f)(); // ��� �Լ��� �Լ� �����ͷ� ȣ���ϴ� ���
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
		// ���� ���� ���� ���̺� - �Ҹ���� �ʵ��� static���� ������
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


