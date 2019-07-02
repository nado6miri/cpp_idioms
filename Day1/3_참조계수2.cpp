// 3_�������2.cpp

#include<iostream>
#include<vector>

class Car
{
	int m_refCount = 0; //���� ����� ���� ���� c++11���� member field �ʱ�ȭ ������.
public:
	void ref() { ++m_refCount;  }
	void deref() { if (--m_refCount == 0) delete this; } // delete�� heap�� �ִ� ���� ������. stack�� �ƴ�.

	//  protected �Ҹ��� - ��ü�� stack �� ���� �� ���� ����.... - page 195 �Ʒ��� �ڵ���.
protected:
	~Car()
	{
		std::cout << "~Car" << std::endl;
	}

};

void main()
{
	//Car c;	// stack �� ������. error
	Car* p1 = new Car;
	p1->ref(); // rule1 : ��ü ������ ���� ��� ����

	Car* p2 = p1;
	p2->ref();	// ��Ģ 2 . ������ ����ÿ� ������� ����

	p2->deref(); // ��Ģ3 . ���̻� �ʿ� ������ ������� ���� 
	p1->deref(); 
}