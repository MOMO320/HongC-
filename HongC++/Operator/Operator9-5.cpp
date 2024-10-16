#include <iostream>

using namespace std;

// ++, -- 증감 연산자 오버로딩 하기

class Digit
{
private:
	int m_digit;
public:
	Digit(int digit = 0) : m_digit(digit) {}

	//prefix(전위형)
	Digit& operator ++()
	{
		++m_digit;

		// Digit의 인스턴스 주소의 디레퍼런스한 값 *this : 6
		cout <<  "*this : " << *this << endl;	
		
		// Digit의 인스턴스 주소 값  this : 0000007918B9F7A0
		cout << "this : " << this << endl;		
		return *this;//6
	}

	// post(후위형)일 경우 매개변수형을 넣어줘야 한다.(규칙)
	Digit operator ++(int)
	{
		Digit temp(m_digit);
		++(*this);

		return temp;
	}

	friend ostream& operator << (ostream & out, const Digit & d)
	{
		out << d.m_digit;
		return out;
	}
};

int main9_5()
{
	// 증감 연산자의 성질
	int a = 10;

	cout << ++a << endl;	// 11
	cout << a << endl;		// 11
	cout << a++ << endl;	// 11
	cout << a << endl;		// 12

	Digit d(5);
	cout << ++d << endl;
	cout << d << endl;
	cout << d++ << endl;
	cout << d << endl;

	return 0;
}