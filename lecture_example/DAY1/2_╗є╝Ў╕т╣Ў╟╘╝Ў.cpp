// 2_�������Լ�

class Rect
{
	int x = 0, y = 0, w = 10, h = 10; // C++11 ���� �ʱ�ȭ����
public:
	int getArea() const // ��� ��� �Լ�
	{
		//x = 10; // error. ��� ����Լ� �ȿ����� ����� ����ȵ�
		return w * h;
	}

	void setX(int a) { x = a; }
};
//void foo(Rect r) 
void foo(const  Rect& r)
{
	int n = r.getArea();
}

int main()
{
	//const Rect r; // �����ڷ� �ʱ�ȭ�ߴٰ� �����ϰ�..
				// ��� ��ü

	Rect r;
	foo(r);
	r.setX(100); // error

	int n = r.getArea();
			// �ٽ� : ��� ��ü�� ��� �Լ��� ȣ�Ⱑ���մϴ�.
			//       "��ü�� ���¸� �������� �ʴ� 
			//			��� ����Լ�(getter)�� �ݵ�� 
			//			��� ��� �Լ��� �Ǿ�� �մϴ�."
}

