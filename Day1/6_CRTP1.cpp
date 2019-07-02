// 6_CRTP1 - 195 Page - 71page??
#include<iostream>

// MS의 오픈소스인 WTL(Window Template Library) - 라이브러리가 이벤트를 처리하는 방식..
// 가상함수 없이 내 윈도우의 click()함수를 호출하기 위한 방법임 - 90년대 유행..
// libutils/include/utils/singleton.h

template <typename T> class Window
{
public :
	void msgLoop()
	{
		//Click(); // this->Click() 의 의미임 - 여기서 this msgLoop(Window* this)
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
	w.msgLoop(); // 1 or 2 ?? - 1번 호출됨 2번을 부르게 하려면 Window class의  Click()을 virtual로 하면 되나 가상테이블이 만들어 져서 다르게 접근 필요
}
