#include<iostream>
using namespace std;

// ��� �Լ��� �ѹ� �� ���ø�ȭ�ϱ� Templatize(���� ���ø�)

template<class T>
class A
{
private:
	T m_value;
public:
	A(const T input)
		:m_value(input)
	{

	}

	// doSomething �Լ����� �� ���ø��� ��
	template<typename TT>
	void doSomething(const TT& input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	void print()
	{
		cout << "class A::m_value : " << m_value << endl;
	}
};

class B
{
private:
	int m_value;
public:
	B(const int& input) : m_value(input)
	{}

	void print()
	{
		cout << "class B::m_value : " << m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	B b_int(123);
	a_int.print();
	b_int.print();

	// �Ű������� ���� �־ ���������� ������ �Ǹ� ���� <��������> �� �ʿ� ����.
	a_int.doSomething<char>('a');	// �̷��� �� �ʿ� ����
	a_int.doSomething('a');
	a_int.doSomething(123.4);

	A<char> a_char('A');
	a_char.print();

	a_char.doSomething(int());
	a_char.doSomething(char());

	return 0;
}
