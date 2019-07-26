// 11_is_abstract1
#include <iostream>
#include <type_traits>

class Shape
{
public:
	virtual void Draw() = 0;
};

template<typename T> short test(T(*arr)[1]);
template<typename T> char test(...);

template<typename T> struct is_abstract
{
	static constexpr bool value = (sizeof(test<T>(0)) == 1);
};
int main()
{
	bool b = is_abstract<Shape>::value;

	std::cout << b << std::endl;
}







