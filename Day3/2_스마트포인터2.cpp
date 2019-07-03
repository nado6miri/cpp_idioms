#include <iostream>
#include <memory>

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

// �޸� �Ҵ翡 ���Ǵ� operator new()�Լ��� ������ �ؼ� Ȯ�ΰ���
void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}


int main()
{
	// �Ʒ� �ڵ�� ���� �޸� �Ҵ��� ����ϰ� �ɱ��? 2�� �ϰ� �ִ�. ��ü / ��ü ������ - burdden �躸�� ����� ŭ - �޸� ����ȭ �� �̽� ���ɼ�
	//std::shared_ptr<Point> sp(new Point);

	// sizeof(Point) + sizeof(������ü)�� �ѹ��� �޸𸮿� �Ҵ���. - �޸� ����ȭ�� ���� �� ����.
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);

	
}

// make_shared�� ����
template<typename T, typename ... Types> shared_ptr<T> make_shared(Types&& ... args)
{
	// 1. �޸� �Ҵ�
	void* p = operator new(sizeof(T) + sizeof(12)); // ������ü�� 12��� ������.

	// 2. �޸� ���ʿ� ���� ��ü�� ���� ������ ȣ��
	new(p) T(std::forward<Types>(args)...);  // c++11 �Ϻ��� ���� (perfect foward) && 

	// 3. ���� ��ü �ʱ�ȭ

	// 4. shared_ptr�� ���� ��ȯ
	char* p2 = static_cast<char*>(p);
	std::shared_ptr<T> sp;
	sp.reset(static_cast<T*>(p2), // ��ü �ּ�
		p2 + sizeof(T));			// ������ü �ּ�
	return p2;

}