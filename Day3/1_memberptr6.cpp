#include <iostream>

class Button
{
	void(*handler)();
	void(Dialog::*handler)();
	Dialog* target;

public :
	void Click()
	{
		// 클릭된 사실을 외부에 알리려고 한다.
		handler();
	}
};

int main()
{
	Button btn;
	btn.Click(); // 사용자가 버튼을 누르면 이 함수가 호출된다고 생각해 봅시다.
}

// 1. 일반함수 포인터
// 2. 멤버함수 포인터
