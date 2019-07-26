// 3_참조계수1.cpp
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
	// 핵심 : 기반 클래스 포인터로 delete 하면 기반 클래스의 소멸자만
	//       호출된다. 파생클래스 소멸자를 호출되게 하려면
	//		"소멸자를 가상함수로" 해야 한다. - C++ 기본 문법.
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

