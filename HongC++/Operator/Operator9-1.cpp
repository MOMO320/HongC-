#include <iostream>

using namespace std;

// 산술 연산자 오버로딩 하기
class Cents
{
private: 
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

};

void add(const Cents& c1, const Cents& c2, Cents& c_out)
{
	c_out.getCents() = c1.getCents() + c2.getCents();
}


int main()
{
	Cents cents1(6);
	Cents cents2(8);

	Cents sum;
	add(cents1, cents2, sum);

	//int i = 6, j = 8;
	//cout << i + j << endl;
	
	cout << sum.getCents() << endl;


	return 0;
}