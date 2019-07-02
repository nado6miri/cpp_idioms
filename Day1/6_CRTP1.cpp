// 6_CRTP1 - 195 Page - 71page??
#include<iostream>

// MS�� ���¼ҽ��� WTL(Window Template Library) - ���̺귯���� �̺�Ʈ�� ó���ϴ� ���..
// �����Լ� ���� �� �������� click()�Լ��� ȣ���ϱ� ���� ����� - 90��� ����..
// libutils/include/utils/singleton.h

template <typename T> class Window
{
public :
	void msgLoop()
	{
		//Click(); // this->Click() �� �ǹ��� - ���⼭ this msgLoop(Window* this)
		static_cast<T*>(this)->Click(); 
	}

	void Click() { std::cout << "Window::Click" << std::endl; } // 1
};

class MyWindow : public Window<MyWindow>
{
public :
	void Click() { std::cout << "MyWindow::Click" << std::endl; } // 2
};

int main()
{
	MyWindow w;
	w.msgLoop(); // 1 or 2 ?? - 1�� ȣ��� 2���� �θ��� �Ϸ��� Window class��  Click()�� virtual�� �ϸ� �ǳ� �������̺��� ����� ���� �ٸ��� ���� �ʿ�
}
