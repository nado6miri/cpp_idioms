// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // ī��(cafe.naver.com/cppmaster)�� �ֽ��ϴ�.
using namespace cppmaster;

class Window
{
	int hwnd;
public:
	void Create()
	{
		hwnd = ec_make_window(&handler);
	}
	// �ٽ� 1. �Ʒ� �Լ��� �ݵ�� static ��� �Լ��� �Ǿ�� �մϴ�.
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
	w.Create();    // �̼��� �����찡 �����Ǿ�� �մϴ�
	ec_process_message();
}


