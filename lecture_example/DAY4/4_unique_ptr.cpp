// 4_unique_ptr
#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Car Go" << std::endl; }
	~Car()    { std::cout << "~Car"   << std::endl; }
};
// ����Ʈ�����͸� ����� ���ô�.
// �ٽ� : -> �� * �� �������ؼ� ������ ó�� ���̰� �ϴ� ��.
// ���� : raw pointer �� �ƴ϶� ��ü�̹Ƿ� �Ҹ��ڵ��� Ȱ���ؼ�
//		 �ڵ����� ����� ������ �ִ�.

class unique_ptr
{
	Car* obj;
public:
	unique_ptr(Car* p = 0) : obj(p) {}
	~unique_ptr() { delete obj; }
	Car* operator->() { return obj; }
	Car& operator*()  { return *obj; }
};

int main()
{
	unique_ptr p1(new Car);
	p1->Go(); // (p1.operator->())Go()
			  // (p1.operator->())->Go()
	(*p1).Go(); // p1.operator*
}

