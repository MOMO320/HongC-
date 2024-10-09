#include "file.h"

// ������ Constructors
class Fraction
{
	

private:
	int m_numberator;
	int m_denominator;

public:
	Fraction()
	{
		cout << "Fraction( ) constructor" << endl;
		m_numberator = 1;
		m_denominator = 1;
	}
	
	// �Ʒ��� ���� ����� ���� �����ڰ� ������ �⺻ �����ڴ� �������� �ʴ´�.
	// ���� �� ���� default ���� ������, ���ڸ� �ȳ־ �Ǳ� ������
	// �����Ϸ��� �⺻ �����ڿ� ���� ���� ���Ͽ� ������ �߻��Ѵ�.
	Fraction(const int& num_in, const int& den_in = 20)
	{
		m_numberator = num_in;
		m_denominator = den_in;

		cout << m_numberator << " / " << m_denominator << endl;
	}
	~Fraction() {}
	void print()
	{
		cout << m_numberator << " / " << m_denominator << endl;
	}

};
int main8_3_1()
{
	// �����ڿ� �Ķ���Ͱ� �ϳ��� ���� ��쿡�� ()�� ���� �Ѵ�.
	// �����ڰ� ������, Ŭ������ ó�� ����� ���� �ڵ����� �⺻ �����ڰ� �����ȴ�. 
	// ��ȣ�� �ٿ� ���� �������� �ڵ����� �⺻ �����ڷ� ȣ���Ѵ�.
	Fraction frac;	// �����ؾ� �Ѵ�. �⺻ �����ڸ� ������ Ŭ������ ���鶧 ()�� ���̸� �ȵȴ�.
	frac.print();

	/*
	  �� �ʱ�ȭ �Ҷ� �߰�ȣ�� ���ȣ�� ������
	   - { } : �� �ȿ� ���� Ÿ�� ��ȯ�� ���� ���ϰ� �մϴ�. -> �� �� �����ϴ�
	   - ( ) : �� �ȿ� ���� Ÿ���� ��ȯ�� �� ���� �ִ�.
	
	*/
	Fraction one_thirds{ 1,3 };	
	Fraction one_thirds1(1, 3);


	one_thirds.print();	// �׷��� ������ ���� �⺻ ���� 1 / 1 �� ��� �ȴ�.
	
	return 0;
}

class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};

class First
{
	// ��� ���� ���� �ʱ�ȭ �ϱ� ������ ������ �ִ� Ŭ������ ���� ȣ���� �ȴ�.
	Second sec;
public:
	First()
	{
		cout << "class First constructor()" << endl;
	}
};

int main8_3()
{

	// Second -> First ������ ������ ȣ��
	First fir;

	return 0;
}