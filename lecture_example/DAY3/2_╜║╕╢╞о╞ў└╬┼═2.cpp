// 2_����Ʈ������2
#include <iostream>
#include <memory>

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};
// �޸� �Ҵ翡 ���Ǵ� operator new() �Լ��� ������ �Ҽ� �ֽ��ϴ�.
void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

int main()
{
	// �Ʒ� �ڵ�� ���� �޸� �Ҵ��� ����ϰ� �ɱ�� ?
	//std::shared_ptr<Point> sp(new Point);

	// sizeof(Point) + sizeof(������ü)�� �ѹ��� �޸� �Ҵ�.
	std::shared_ptr<Point> sp = std::make_shared<Point>(1,2);					
}

// make_shared�� ����
template<typename T, typename ... Types> 
shared_ptr<T> make_shared(Types&& ... args)
{
	// 1. �޸� �Ҵ� 
	void* p = operator new(sizeof(T) + sizeof(12)); 
					// ������ü�� ũ�⸦ 12��� ����.

	// 2. �޸� ���ʿ� ���� ��ü�� ���ؼ� ������ ȣ��
	new(p) T(std::forward<Types>(args)...); // C++11 �Ϻ�������

	// 3. ���� ��ü �ʱ�ȭ

	// 4. shared_ptr�� ���� ��ȯ

	char* p2 = static_cast<char*>(p);

	std::shared_ptr<T> sp;
	sp._reset(static_cast<T*>(p2),  // ��ü �ּ�
				p2 + sizeof(T));   // ������ü �ּ�

	return sp;
	
}





