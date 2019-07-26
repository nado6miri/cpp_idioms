// 11_is_abstract1
#include <iostream>
#include <type_traits>
struct Point
{
//	int x;
	int y;
};
template<typename T, T> class check {};

// check<int, 0> 
// check<int*, 0>
// check<int Point::*, &Point::x>

template<typename T> struct has_member_x
{
	typedef char YES[1];
	typedef char NO[2];

	template<typename U>
	static YES&  test(check<int U::*, &U::x>* p);



	template<typename U> static NO& test(...);

	static constexpr bool value =
		(sizeof(test<T>(0)) == sizeof(YES));
};



int main()
{
	bool b = has_member_x<Point>::value;

	std::cout << b << std::endl;
}







