// 4_typename
class AAA
{
public:
	enum { value = 10};
	typedef int DWORD;
};
int p = 0;

template<typename T> void foo(T a)
{
	// �����Ϸ��� �Ʒ� ������ ��� �ؼ��ؾ� �ұ�� ?
	// (1) DWORD �� ��(static ���� �Ǵ� enum ���)�̴�.
	// (2) DWORD �� T�ȿ� ������ Ÿ���̴�.
	T::value * p; // ok.. value �� ������ ���� �ǹǷ�
	//T::DWORD * p; // DWORD�� ������ ���� ���ϱ� p�ϴ� �ڵ�

	typename T::DWORD * p; // DWORD�� Ÿ������ �ؼ��ش޶�� �ǹ�.

	// �ٽ� : ���ø� ����(T)�� ������ Ÿ���� ����Ҷ��� �ݵ��
	//       �տ� typename�� �ٿ��� �Ѵ�!!!

	typename AAA::DWORD *p2; // typename�� �ʿ����.!!!
							 // T�� �ƴ϶� ��Ȯ�� �̸�(AAA)���!

}
int main()
{
	AAA aaa;
	foo(aaa);
}
