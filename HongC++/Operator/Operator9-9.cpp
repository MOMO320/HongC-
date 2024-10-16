#include <iostream>
#include <cassert>

using namespace std;

// 복사 생선자, 복사 초기화 반환값 최적화

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

	// 복사 생성자 : 자기하고 똑같은 인스턴스가 들어오는게 복사 생성자이다.
	Fraction(const Fraction& fraction)	// copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		// 복사 생성자가 얼마나 자주 호출 하는지 확인 하기 위해 출력 내용 넣음
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

	// -> 이렇게 초기화 할 경우 복사 생성자가 호출 되지 않는다.
	// Fraction fr_copy2(3, 10); -> 이렇게 인식 되어 버린다.
	Fraction fr_copy2(Fraction(3, 10));	//Basic Constructor Called
	//	Fraction fr_copy = frac; 

	cout << frac << fr_copy << endl;	// 3 / 5, 3/ 5

	// 주소가 같으니깐 복사 생성자가 아닌 일반 생성자가 호출된다.
	Fraction result = doSomething();	// 반환값 최적화

	cout << &result << endl;
	cout << result << endl;

	return 0;
}
