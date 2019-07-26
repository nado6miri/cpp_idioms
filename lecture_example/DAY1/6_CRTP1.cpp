// 6_CRTP1 - 195 page
#include <iostream>


// libutils/include/utils/singleton.h


// MS�� ���¼ҽ��� WTL(Windows Template Library)
//  ���̺귯���� �̺�Ʈ�� ó���ϴ� ���.
template<typename T> class Window
{
public:
	void msgLoop()  // msgLoop(Window* this)
	{
		//Click(); // this->Click()
		static_cast<T*>(this)->Click();
	}
	void Click() { std::cout << "Window::Click" << std::endl; } // 1
};
class MyWindow : public Window<MyWindow>
{
public:
	void Click() { std::cout << "MyWindow::Click" << std::endl; } // 2
};
int main()
{
	MyWindow w;
	w.msgLoop(); // 1 ? 2
}


