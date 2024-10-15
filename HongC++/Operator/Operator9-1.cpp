#include <iostream>

using namespace std;

// ��� ������ �����ε� �ϱ�
// ������ ������ �����ε��� ���� �ʴ°� ����. 
/*
  - ������ �����ε� �ȵǴ� ���
	
	?:	(���� ������)	
	::  (������ ������)
	sizeof	
	.	(��� ������)
	.*  (��� ������ ������)
	 
*/
class Cents
{
private: 
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// ������ �����ε��� ��� �Լ��� �ϸ� this�� ���ؼ� �ڱ� �ڽ��� ���� �־���� �Ѵ�.
	Cents operator+(const Cents& c2)
	{
		return Cents(this->m_cents + c2.getCents());
	}

	//friend Cents operator+(const Cents& c1, const Cents& c2)
	//{
	//	return Cents(c1.getCents() + c2.getCents());
	//}

	// ��� �Լ��θ� ������ �����ε� �ؾ� �ϴ� �͵�
	// = , [], (), -> (��� �Լ��θ� �����ε��� �����ϴ�)
};

//void add(const Cents& c1, const Cents& c2, Cents& c_out)
//{
//	c_out.getCents() = c1.getCents() + c2.getCents();
//}

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

//Cents operator+(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.getCents() + c2.getCents());
//}

int main9_1()
{
	Cents cents1(6);
	Cents cents2(8);

	//Cents sum;
	//sum = add(cents1, cents2);   

	cout << add(cents1, cents2).getCents() << endl;
	//int i = 6, j = 8;
	//cout << i + j << endl;
	
	//cout << sum.getCents() << endl;

	// Cents operator+ �Լ� ���
	cout << (cents1 + cents2 + Cents(6)+Cents(10)+Cents(20)).getCents() << endl;

	return 0;
}