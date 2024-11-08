#include<iostream>
using namespace std;

// 멤버 함수를 한번 더 템플릿화하기 Templatize(이중 템플릿)

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

	// doSomething 함수에서 또 템플릿을 함
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

	// 매개변수에 값을 넣어서 데이터형이 구분이 되면 굳이 <데이터형> 할 필요 없다.
	a_int.doSomething<char>('a');	// 이렇게 할 필요 없음
	a_int.doSomething('a');
	a_int.doSomething(123.4);

	A<char> a_char('A');
	a_char.print();

	a_char.doSomething(int());
	a_char.doSomething(char());

	return 0;
}
