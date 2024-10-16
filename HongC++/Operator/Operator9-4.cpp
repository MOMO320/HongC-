#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 비교 연산자 오버로딩 하기 ==, !=, > , >=

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

	// ! -> bool 데이터형(조건은 각자 원하는 방향으로 작성하는것 이다.)
	// 아래 함수의 조건 : cents가 0일때 낫을 붙이면 true를 리턴하게 하고
	// 그 외의 경우에는 false를 리턴한다.
	bool operator !() const	 // not operator
	{
		return (this->m_cents == 0) ? true : false;
		// !Cents(...)
	}

	// 멤버 함수 연산자 오버로딩
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
		cout << "Cents의 값이 같습니다." << endl;
	}
	else
	{
		cout << "Cents의 값이 다릅니다." << endl;
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