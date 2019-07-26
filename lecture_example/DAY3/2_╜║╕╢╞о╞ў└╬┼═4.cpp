#include <iostream>
#include <memory>

int main()
{
	int* rp = nullptr; // raw pointer 는 객체가 파괴된 사실을
					   // 알수 없다.
	std::weak_ptr<int> wp; // 참조계수가 증가하지 않는 스마트포인터
	{
		std::shared_ptr<int> sp1(new int);
		std::shared_ptr<int> sp2 = sp1; // 참조계수 증가

		rp = sp1.get();  // 진짜 포인터 꺼내기
		wp = sp1;

		std::cout << sp1.use_count() << std::endl;
	}
	// android/  libutils/refbase.h 열어 보세요.


	if (wp.expired())
	{
		std::cout << "wp : 객체가 파괴됨" << std::endl;
	}

	if (rp != nullptr)
	{
		std::cout << "객체사용" << std::endl;
	}
}

