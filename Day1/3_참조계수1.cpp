// 3_참조계수1.cpp

#include<iostream>
#include<vector>

class Car
{
public :
	~Car()
	{
		std::cout << "~Car" << std::endl;
	}

};

std::vector<Car*> v;

void foo()
{
	Car *p = new Car;
	v.push_back(p);
	// 더이상 p가 필요 없습니다. delete해도 될까요? - vector에 넣어놓은 포인터가 dangling ptr이 되어버림. 따라서 ref counter관리 필요.
	delete p;
}

void main()
{
	foo();
}