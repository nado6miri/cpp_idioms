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
	People p2 = p1;  

	// 임시 객체가 넘어오면 깊은 복사하고 임시객체는 사라짐
	// 따라서 임시객체 죽이지 말고 바로 가져가도록 하면 효율성이 있음.
	// 임시객체일때(rvalue)를 대비하여 하나 더 만든다.
	People p3 = foo();
}