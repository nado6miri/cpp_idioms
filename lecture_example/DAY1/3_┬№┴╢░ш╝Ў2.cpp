// 3_�������1.cpp
#include <iostream>
#include <vector>

class Car
{
	//....
	int m_refCount = 0; // ���� ����� ���� ����
					// C++11 ���� member field �ʱ�ȭ ����
public:
	void ref()   { ++m_refCount; }
	void deref() { if (--m_refCount == 0) delete this; }

	// protected �Ҹ��� : ��ü�� ���ÿ� ����� ���� �Ѵ�.
	//                    195 page �Ʒ��� �ڵ�.
protected:
	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
	//Car c;

	Car* p1 = new Car;
	p1->ref();   // ��Ģ 1. ��ü ������ ���� ��� ����
	
	Car* p2 = p1;
	p2->ref();   // ��Ģ 2. ������ ����� ������� ����

	p2->deref(); // ��Ģ 3. ���̻� �ʿ������ ���� ��� ����
	p1->deref();
}
  
   