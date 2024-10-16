#include <iostream>
#include <cassert>

using namespace std;

// ��ȯ ������ (Converting constructor) , explicit, delete

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(char) = delete;

	explicit Fraction(int num = 0, int den = 1) : m_numerator(num), m_denominator(den)
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

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(7);
	//Fraction frac2('c');	// ������ �Լ���� ���� error�� �߻� ��
	// �͸� ��ü �����̶�� ���� �ϸ� �˴ϴ�.
	// ������ó�� ���� ������ ȣ�� ��(�Ͻ�������)
	// doSomething(7);	-> �����
	

	// �����ڿ� explicit Ű���带 ������ ��������� ó�� �϶��
	//doSomething(7); -> error �߻�


	return 0;
}