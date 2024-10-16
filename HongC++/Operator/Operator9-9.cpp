#include <iostream>
#include <cassert>

using namespace std;

// ���� ������, ���� �ʱ�ȭ ��ȯ�� ����ȭ

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int num = 0, int den = 1) : m_numerator(num), m_denominator(den)
	{
		cout << "Basic Constructor Called" << endl;
		assert(den != 0);
	}

	// ���� ������ : �ڱ��ϰ� �Ȱ��� �ν��Ͻ��� �����°� ���� �������̴�.
	Fraction(const Fraction& fraction)	// copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		// ���� �����ڰ� �󸶳� ���� ȣ�� �ϴ��� Ȯ�� �ϱ� ���� ��� ���� ����
		cout << "Copy Constructor Called" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		cout << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}

int main9_9()
{
	Fraction frac(3, 5);	//Basic Constructor Called

	Fraction fr_copy(frac); //Copy Constructor Called

	// -> �̷��� �ʱ�ȭ �� ��� ���� �����ڰ� ȣ�� ���� �ʴ´�.
	// Fraction fr_copy2(3, 10); -> �̷��� �ν� �Ǿ� ������.
	Fraction fr_copy2(Fraction(3, 10));	//Basic Constructor Called
	//	Fraction fr_copy = frac; 

	cout << frac << fr_copy << endl;	// 3 / 5, 3/ 5

	// �ּҰ� �����ϱ� ���� �����ڰ� �ƴ� �Ϲ� �����ڰ� ȣ��ȴ�.
	Fraction result = doSomething();	// ��ȯ�� ����ȭ

	cout << &result << endl;
	cout << result << endl;

	return 0;
}
