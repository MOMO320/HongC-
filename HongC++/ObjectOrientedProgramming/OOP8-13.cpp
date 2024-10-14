#include "file.h"

// 익명 객체(anonymous object)

class AObj
{
public:
	int m_value;

	AObj(const int &value) : m_value(value)
	{
		cout << this << endl;
		cout << "Constructor" << endl;
	}
	~AObj()
	{
		cout << "DesConstructor" << endl;
	}
	void print()
	{
		cout <<  m_value << endl;
	}
};

int main8_13_1()
{
	AObj a(1);
	a.print();

	// 아래와 같이 인스턴스 객체를 만들고 사용하는 것이 아닌
	// 익명 객체를 이용해 함수를 부를 경우 생성자와 소멸자가 다 불러진다.
	// 그리고 매번 다른 주소를 가진 익명 객체로 불린다.
	AObj(10).print();
	AObj(20).print();

	return 0;
}

class Cents
{
private:
	int m_cents;
public:
	Cents(int cents) { m_cents = cents; }

	int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	cout << add(Cents(6), Cents(8)).getCents() << endl;
	cout << int(6) + int(8) << endl;

	return 0;
}