// 10_trivial1

#include <iostream>

// trivial : ������, ���� ������, �Ҹ��ڵ��� �ϴ����� ���°�� trivial�ϴ� ��� �մϴ�.
// 1. �����Լ��� ����
// 2. ��ü�� ����� ���ų� ����� �����ڰ� trivial�ϰ�
// 3. ��� Ŭ������ ���ų� ��� Ŭ������ �����ڰ� trivial�ϰ�
// 4. ����ڰ� ���� �����ڰ� ������
// �����ڴ� trivial�ϴ� ��� �մϴ�.

class A {};

class B : public A
{
	//A a;
public:
	virtual void foo() { std::cout << "foo" << std::endl; }
};

int main()
{
	// B�� �����ڰ� trivial �ұ��?
	// B�� �����ڰ� trivial�ϸ� ������ ȣ���� ���� �ʾƵ� ��밡�� �ؾ� �մϴ�.
	B* p = static_cast<B*>(operator new(sizeof(B)));
	new(p) B;  // ������ ȣ���� ���� ������ �״´�. ���� trivial���� �ʴ�. �����ڴ� �����Լ��� �ʱ�ȭ �� �ִ� ������ ��.
	p->foo();
}