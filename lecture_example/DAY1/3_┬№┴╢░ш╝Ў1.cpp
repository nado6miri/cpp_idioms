// 3_참조계수1.cpp
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

	// 더이상 p가 필요 없습니다. delete 해도될까요 ?
	//delete p;
}
int main()
{
	foo();
}

