#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

int main()
{
//	std::vector<int> v = { 1,2,3,4,5 };
	std::list<int> v = { 1,2,3,4,5 };

	auto p = v.begin();

	// p를 3칸 전진하고 싶습니다. 가장 좋은 코드는 뭘까요 ?
	//p = p + 3; //vector는 되지만 list 는 안됨
	std::advance(p, 3);
}





