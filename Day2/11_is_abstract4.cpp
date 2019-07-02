#include<iostream>
#include<type_traits>

// 143 page....

template<typename T> struct is_abstract
{
	typedef char YES[1];
	typedef short NO[2];

	template<typename T> static NO& test(T(*arr)[1]);// {}
	template<typename T> static YES& test(...);// { }
	static constexpr bool value = (sizeof(test<T>(0)) == sizeof(YES));
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


