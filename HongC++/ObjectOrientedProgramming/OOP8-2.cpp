#include "file.h"

// ĸ��ȭ, ���� ������, ���� �Լ�
// Encapsulation , Access Specifiers , Access Functions

// class�� ���� �����ڸ� ���� ������ ������ �ڵ����� private�� �����ȴ�.
class Date
{
//�����
private:
// ����
private:	// access specifier
	int m_month;
	int m_day;
	int m_year;

public:
	// ���� �Լ�(Access Functions)
	// �ܺο� ���� ���ϰ� �� ��� �������� ���� �� �� �ְ� ������ �Լ��� �����
	// ������ ������ �̷������ �Ѵ�.
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day	= day_input;
		m_year	= year_input;
	}
	
	void setMonth(const int& month_input)
	{
		m_month = month_input;
	}

	// setter, getter
	const int& getDay()
	{
		return m_day;
	}

	const int& getMonth()
	{
		return m_month;
	}

	const int& getYear()
	{
		return m_year;
	}

	// ���� Ŭ������ �ٸ� �ν��Ͻ� ��ü�� ��� ������ ������ �����ϴ�.
	void copyFrom(const Date& original)
	{
		m_month = original.m_month;
		m_day	= original.m_day;
		m_year	= original.m_year;
	}
};

int main8_2()
{
	Date today;//{ 8,4,2025 };
	today.setDate(8, 4, 2025);
	today.setMonth(10);

	//cout << today.m_day << endl;	// error �߻� private�� ���� �����ϱ�
	cout << today.getDay() << endl;

	Date copy;
	copy.copyFrom(today);

	return 0;
}