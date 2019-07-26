// 3_�������1.cpp
#include <iostream>
#include <vector>

class RefCountedBase
{
	int m_refCount = 0; 
public:
	void ref() { ++m_refCount; }

	void deref()   // void deref( RefCountedBase* this )
	{ 
		if (--m_refCount == 0)
			delete this;
	}

protected:
	// �ٽ� : ��� Ŭ���� �����ͷ� delete �ϸ� ��� Ŭ������ �Ҹ��ڸ�
	//       ȣ��ȴ�. �Ļ�Ŭ���� �Ҹ��ڸ� ȣ��ǰ� �Ϸ���
	//		"�Ҹ��ڸ� �����Լ���" �ؾ� �Ѵ�. - C++ �⺻ ����.
	virtual ~RefCountedBase() {  }
};




class Car : public RefCountedBase
{
public:
	~Car() {  std::cout << "~Car" << std::endl;  }
};

int main()
{
	Car* p1 = new Car;
	p1->ref();   

	Car* p2 = p1;
	p2->ref();  

	p2->deref(); 
	p1->deref();
}

