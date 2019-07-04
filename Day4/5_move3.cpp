#include <iostream>


class People
{
	char* name;
	int age;
public:
	People(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~People() { delete[] name; }

	// 깊은 복사로 구현한 복사 생성자
	People(const People& p) : age(p.age)
	{
		// 포인터 변수는 메모리 자체를 복사
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}

	// 임시객체(rvalue)인 경우 얕은 복사 - 자원을 복사한 것이 아니라 move 이동 생성자임.
	People(const People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr; // 자원 포기하도록 설정하면 됨.
		p.age = 0; //  해도그만 안해도 그만
	}

};

People foo()
{
	People p("lee", 30);
	return p;
}

int main()
{
	People p1("kim", 10);
	People p2 = p1;  // 복사 생성자 호출
	People p3 = foo(); // move 생성자 호출
	People p4 = static_cast<People&&>(p1); // move 생성자 호출 
	People p5 = std::move(p1); // 위처럼 casting하는 함수임. - 시험문제임

}