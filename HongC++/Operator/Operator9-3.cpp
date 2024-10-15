#include <iostream>

using namespace std;

// ���� ������ �����ε� �ϱ�(+,-,!)
class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0):m_cents(cents) { }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// -
	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	// ! -> bool ��������(������ ���� ���ϴ� �������� �ۼ��ϴ°� �̴�.)
	// �Ʒ� �Լ��� ���� : cents�� 0�϶� ���� ���̸� true�� �����ϰ� �ϰ�
	// �� ���� ��쿡�� false�� �����Ѵ�.
	bool operator !() const	 // not operator
	{
		return (this->m_cents == 0) ? true : false;
		// !Cents(...)
	}

	friend std::ostream& operator << (std::ostream& out, Cents cents)
	{
		cout << cents.m_cents << endl;
		return out;
	}
};
int main9_3()
{

	Cents cents1(6);
	Cents cents2(0);

	cout << cents1 << endl;
	cout << -cents1 << endl;
	cout << -Cents(-10) << endl;

	auto temp = !cents1;
	cout << !cents1 << endl;	// false;
	cout << !cents2 << endl;	// true;

	if (!cents1) cout << "cents1 is true" << endl;
	else if (!cents2) cout << "cents2 is true" << endl;


	//int a = 3;
	//cout << -a << endl;	// +, -, !
	//cout << !a << endl;


	return 0;
}