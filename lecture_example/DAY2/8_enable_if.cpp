// 8_enable_if   77 page
template<bool b, typename T = void> struct enable_if
{
	typedef T type;
};
// �κ� Ư��ȭ�ÿ��� ����Ʈ���� ǥ�� ���� �ʽ��ϴ�.
template<typename T> struct enable_if<false, T>
{
};

int main()
{
	// �Ʒ� �ڵ忡�� �� ������ Ÿ���� ���� ������
	enable_if<true, int>::type    n1; // int
	enable_if<true, double>::type n2; // double
	enable_if<true>::type n3;	// void, �������� �ȵǹǷ� error

	// 1��° ���ڰ� false�� ��� type�� �����ϴ�.
	enable_if<false, int>::type    n4; // error
	enable_if<false, double>::type n5; // error
	enable_if<false>::type n6;			// error

}