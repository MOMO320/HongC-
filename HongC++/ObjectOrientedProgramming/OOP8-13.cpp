#include "file.h"

// �͸� ��ü(anonymous object)

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

	// �Ʒ��� ���� �ν��Ͻ� ��ü�� ����� ����ϴ� ���� �ƴ�
	// �͸� ��ü�� �̿��� �Լ��� �θ� ��� �����ڿ� �Ҹ��ڰ� �� �ҷ�����.
	// �׸��� �Ź� �ٸ� �ּҸ� ���� �͸� ��ü�� �Ҹ���.
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