#include <iostream>

class Button
{
	//void(*handler)();
	void(Dialog::*handler)();
	Dialog* target;
public:
	void Click()
	{
		// 클릭된 사실을 외부에 알리려고 합니다.
		handler();
	}
};
int main()
{
	Button btn;
	btn.Click(); // 사용자가 버튼을 누르면 이함수가 호출된다고
				 // 가정해 봅시다.
}
