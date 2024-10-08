#include "file.h"

// 캡슐화, 접근 지정자, 접근 함수
// Encapsulation , Access Specifiers , Access Functions

// class는 접근 지정자를 지정 해주지 않으면 자동으로 private로 설정된다.
class Date
{
//비공개
private:
// 공개
private:	// access specifier
	int m_month;
	int m_day;
	int m_year;

public:
	// 접근 함수(Access Functions)
	// 외부에 접근 못하게 한 멤버 변수들을 접근 할 수 있게 공개용 함수를 만들어
	// 데이터 변경이 이루어지게 한다.
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

	// 같은 클래스는 다른 인스턴스 객체의 멤버 변수에 접근이 가능하다.
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

	//cout << today.m_day << endl;	// error 발생 private로 막혀 있으니깐
	cout << today.getDay() << endl;

	Date copy;
	copy.copyFrom(today);

	return 0;
}