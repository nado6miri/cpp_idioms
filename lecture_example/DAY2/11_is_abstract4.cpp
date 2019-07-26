// 11_is_abstract1
#include <iostream>
#include <type_traits>

class Shape
{
public:
	virtual void Draw() = 0;
};





template<typename T> struct is_abstract 
{
	typedef char YES[1];   // 143 page ArrayOne
	typedef char NO[2];

	template<typename U> static NO&  test(U(*arr)[1]);
	template<typename U> static YES& test(...);

	static constexpr bool value = 
		(sizeof(test<T>(0)) == sizeof(YES));
};



int main()
{
	bool b = is_abstract<Shape>::value;

	std::cout << b << std::endl;
}







