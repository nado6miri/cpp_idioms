#include <iostream>
#include <memory>

// android/libutils/refbase.h 를 열어 보세요.
// platform_system_core / libutils / RefBase.cpp - 149 라인...
int main()
{
	// raw pointer는 수명에 관여하지 않지만(참조계수 증가 안함)- 문제점은 객체가 파괴된 사실을 알 수 없다. 그래서 weak_ptr을 사용한다.
	// weak_ptr은 참조계수 증가하지 않지만 객체가 파괴되었는지 알 수 있다.
	// weak_ptr은 자원의 주소 뿐만 아니라 관리객체 주소도 가지고 있다. (관리객체는 weak_ptr이 사용하고 있음
	// 관리객체 파괴 시점은 strong counter / weak counter 모두 0이 될때 사라짐.
	// 수명 counter / 자원 ptr / weak count /  삭제자
	// make_shared를 사용하게 되면 객체랑 관리객체가 하나로 구성되기 때문에 객체가 소멸되더라도(소멸자 호출) 관리 객체는 일정기간 유지해야 하기 때문에
	// 메모리 측면에서 손해를 본다. 나중에 관리객체 해제시 같이 해제함.
	int* rp = nullptr; 
	std::weak_ptr<int> wp; // 참조계수가 증가하지 않는 스마트 포인터
	{
		std::shared_ptr<int> sp1(new int);
		std::shared_ptr<int> sp2 = sp1; // 참조계수 증가

		rp = sp1.get(); // 진짜 포인터 꺼내기..

		std::cout << sp1.use_count() << std::endl;
	}

	if (rp != nullptr)
	{
		std::cout << "객체사용" << std::endl;
	}

	if (wp.expired())
	{
		std::cout << "wp 객체 파괴됨" << std::endl;
	}

}