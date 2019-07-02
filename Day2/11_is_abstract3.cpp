#include<iostream>
#include<type_traits>

// 143 page....

template<typename T> short test(T(*arr)[1]);// {}
template<typename T> char test(...);// { }

template<typename T> struct is_abstract
{
	static constexpr bool value = (sizeof(test<T>(0)) == 1);
};

class Shape
{
public:
	virtual void Draw() = 0;
};


int main()
{
	bool b = is_abstract<Shape>::value;
	std::cout << b << std::endl;
}


