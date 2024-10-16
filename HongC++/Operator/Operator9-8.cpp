#include <iostream>
#include <string>

using namespace std;

// ����ȯ�� �����ε� �ϱ�(���� �� �� ���� ����)

class Cents
{
private:
	int m_cents;
	string m_name;

public:
	Cents(int cents = 0 , string name = "")
	{
		m_cents = cents;
		m_name = name;
	}

	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	// int������ ����ȯ �ϴ� ���� �����ε� �ϴ� ��
	operator int()
	{
		cout << "cast int" << endl;
		return m_cents;
	}

	operator string()
	{
		cout << "cast string" << endl;
		return m_name;
	}
};

class Dollar
{
private:
	int m_dollars = 0;

public:
	Dollar(const int& input) : m_dollars(input)
	{

	}

	// Cents�� ����ȯ
	operator Cents()
	{
		cout << "Dollar casting" << endl;
		return Cents(m_dollars * 100);
	}
};

void printInt(const int& value)
{
	cout << value << endl;
}

int main9_8()
{
	Cents cents(7, "hello");
	int value = cents;
	value = (int)cents;
	value = int(cents);
	value = static_cast<int>(cents);

	printInt(cents);	// cast int , 7 �� ����

	string name = cents;

	cout << name << endl;

	cout << "--------------------------------------" << endl;

	Dollar dol(2);
	Cents cents2 = dol;

	printInt(cents2);

	return 0;
}