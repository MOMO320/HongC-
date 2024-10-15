#include <iostream>

using namespace std;

// 단항 연산자 오버로딩 하기(+,-,!)
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

	// ! -> bool 데이터형(조건은 각자 원하는 방향으로 작성하는것 이다.)
	// 아래 함수의 조건 : cents가 0일때 낫을 붙이면 true를 리턴하게 하고
	// 그 외의 경우에는 false를 리턴한다.
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