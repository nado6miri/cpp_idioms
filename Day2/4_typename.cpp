// 4_typename
class AAA
{
public:
	enum { value = 10 };
	typedef int DWORD;
};

int p = 0;

template<typename T> void foo(T a)
{
	// �����Ϸ��� �Ʒ� ������ ��� �ؼ��ұ��?
	// (1) DWORD�� ��(static ���� �Ǵ� enum ���)�̴�.
	// (2) DWORD�� T�ȿ� ������ Ÿ���̴�.
	//T::DWORD *p; // DWORD�� ������ ���� ���ϱ� p�ϴ� �ڵ���  :: �ڿ��� ���� ������ ����
	typename T::DWORD *p; // DWORD�� type���� �ؼ��� �޶��� �ǹ���. �����ͷ� ������.

	// �ٽ� : ���ø� ����(T)�� ������ Ÿ���� ����Ҷ� �ݵ�� �տ� typename�� �ٿ��� �Ѵ�.!!!
	typename AAA::DWORD *p2; //  typename�� �ʿ����.  T�� �ƴ϶� ��Ȥ�� �̸�(AAA) �� ����߱� ������....
}

int main()
{
	AAA aaa;
	foo(aaa);
}