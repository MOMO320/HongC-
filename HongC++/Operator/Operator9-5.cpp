#include <iostream>

using namespace std;

// ++, -- ���� ������ �����ε� �ϱ�

class Digit
{
private:
	int m_digit;
public:
	Digit(int digit = 0) : m_digit(digit) {}

	//prefix(������)
	Digit& operator ++()
	{
		++m_digit;

		// Digit�� �ν��Ͻ� �ּ��� ���۷����� �� *this : 6
		cout <<  "*this : " << *this << endl;	
		
		// Digit�� �ν��Ͻ� �ּ� ��  this : 0000007918B9F7A0
		cout << "this : " << this << endl;		
		return *this;//6
	}

	// post(������)�� ��� �Ű��������� �־���� �Ѵ�.(��Ģ)
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
	// ���� �������� ����
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