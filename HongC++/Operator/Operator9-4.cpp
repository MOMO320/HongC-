#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �� ������ �����ε� �ϱ� ==, !=, > , >=

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) :m_cents(cents) { }
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

	// ��� �Լ� ������ �����ε�
	bool operator == (const Cents & c)
	{
		return this->m_cents == c.m_cents;
	}

	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	bool operator > (const Cents& cents)
	{
		return this->m_cents > cents.m_cents;
	}

	friend bool operator > (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents > c2.m_cents;
	}

	bool operator < (const Cents& cents)
	{
		return this->m_cents < cents.m_cents;
	}

	friend std::ostream& operator << (std::ostream& out,const  Cents &cents)
	{
		out << cents.m_cents;
		return out;
	}
};


int main9_4_1()
{
	int a = 3, b = 3;
	if (a == b)
		cout << "Equal" << endl;

	Cents cents1(100), cents2(100);


	if (cents1 == cents2)
	{
		cout << "Cents�� ���� �����ϴ�." << endl;
	}
	else
	{
		cout << "Cents�� ���� �ٸ��ϴ�." << endl;
	}

	return 0;
}

int main9_4_2()
{
	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; ++i)
		arr[i].getCents() = i;

	std::random_shuffle(begin(arr), end(arr));

	for (auto& ele : arr)
		cout << ele << " ";
	cout << endl;

	sort(begin(arr), end(arr));

	for (auto& ele : arr)
		cout << ele << " ";
	cout << endl;

	return 0;
}