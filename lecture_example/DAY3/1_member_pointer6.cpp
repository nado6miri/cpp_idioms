#include <iostream>

class Button
{
	//void(*handler)();
	void(Dialog::*handler)();
	Dialog* target;
public:
	void Click()
	{
		// Ŭ���� ����� �ܺο� �˸����� �մϴ�.
		handler();
	}
};
int main()
{
	Button btn;
	btn.Click(); // ����ڰ� ��ư�� ������ ���Լ��� ȣ��ȴٰ�
				 // ������ ���ô�.
}
