#include <iostream>
#include <cassert>

using namespace std;

// 변환 생성자 (Converting constructor) , explicit, delete

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

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(7);
	//Fraction frac2('c');	// 삭제된 함수라고 떠서 error가 발생 됨
	// 익명 객체 생성이라고 생각 하면 됩니다.
	// 생성자처럼 보고 생성자 호출 됨(암시적으로)
	// doSomething(7);	-> 실행됨
	

	// 생성자에 explicit 키워드를 넣으면 명시적으로 처리 하라고
	//doSomething(7); -> error 발생


	return 0;
}