#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<int> sp1(new int);
	std::shared_ptr<int[]> sp2(new int[10]);

	std::unique_ptr<int>    p1(new int);
	std::unique_ptr<int[]>  p2(new int[10]); 

	//p1[0] = 10; // error
	*p1   = 10; // ok
	p2[0] = 10; // ok
	//*p2   = 10; // error

}



