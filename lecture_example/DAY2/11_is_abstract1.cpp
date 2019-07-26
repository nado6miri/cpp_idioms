// 11_is_abstract1
#include <iostream>
#include <type_traits>
// 143page..

class Shape
{
public:
	virtual void Draw() = 0;
};
int main()
{
	std::cout << std::is_abstract<Shape>::value << std::endl;
}

