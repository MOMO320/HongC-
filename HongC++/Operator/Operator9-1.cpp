#include <iostream>

using namespace std;

// 산술 연산자 오버로딩 하기
// 위험한 연산자 오버로딩은 하지 않는게 좋다. 
/*
  - 연산자 오버로딩 안되는 목록
	
	?:	(조건 연산자)	
	::  (스코프 연산자)
	sizeof	
	.	(멤버 셀렉션)
	.*  (멤버 포인터 셀렉션)
	 
*/
class Cents
{
private: 
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// 연산자 오버로딩을 멤버 함수로 하면 this를 통해서 자기 자신의 값을 넣어줘야 한다.
	Cents operator+(const Cents& c2)
	{
		return Cents(this->m_cents + c2.getCents());
	}

	//friend Cents operator+(const Cents& c1, const Cents& c2)
	//{
	//	return Cents(c1.getCents() + c2.getCents());
	//}

	// 멤버 함수로만 연산자 오버로딩 해야 하는 것들
	// = , [], (), -> (멤버 함수로만 오버로딩이 가능하다)
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

	// Cents operator+ 함수 사용
	cout << (cents1 + cents2 + Cents(6)+Cents(10)+Cents(20)).getCents() << endl;

	return 0;
}