// 3_�������1.cpp
#include <iostream>
#include <vector>

class Car
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};

std::vector<Car*> v;

void foo()
{
	Car* p = new Car;
	v.push_back(p);

	// ���̻� p�� �ʿ� �����ϴ�. delete �ص��ɱ�� ?
	//delete p;
}
int main()
{
	foo();
}

