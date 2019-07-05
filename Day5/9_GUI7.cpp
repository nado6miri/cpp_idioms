// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // ī��(cafe.naver.com/cppmaster)�� �ֽ��ϴ�.
using namespace cppmaster;
#include <map>

// �����Լ��� �������� CRTP ����Ͽ� class�� template���� �ϰ� typecasting �ؼ� ȣ�� 
template<typename T> class Window
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

	static int handler(int handle, int msg, int a, int b)
	{
		// ���� ������ ��ȣ�� ������ this�� ���´�.
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


