#include "file.h"

// 생성자 Constructors
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
	
	// 아래와 같이 사용자 정의 생성자가 있으면 기본 생성자는 생성되지 않는다.
	// 주의 할 점은 default 값을 넣으면, 인자를 안넣어도 되기 때문에
	// 컴파일러가 기본 생성자와 구분 하지 못하여 에러가 발생한다.
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
	// 생성자에 파라미터가 하나도 없을 경우에만 ()를 빼야 한다.
	// 생성자가 없으면, 클래스를 처음 만들어 질때 자동으로 기본 생성자가 생성된다. 
	// 괄호를 붙여 주지 않으면은 자동으로 기본 생성자로 호출한다.
	Fraction frac;	// 주의해야 한다. 기본 생성자만 있으면 클래스를 만들때 ()를 붙이면 안된다.
	frac.print();

	/*
	  ㅁ 초기화 할때 중괄호와 대괄호의 차이점
	   - { } : 은 안에 값을 타입 변환을 하지 못하게 합니다. -> 좀 더 엄격하다
	   - ( ) : 은 안에 값의 타입을 변환은 할 수는 있다.
	
	*/
	Fraction one_thirds{ 1,3 };	
	Fraction one_thirds1(1, 3);


	one_thirds.print();	// 그렇기 때문에 값이 기본 값인 1 / 1 이 출력 된다.
	
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
	// 멤버 변수 먼저 초기화 하기 때문에 변수로 있는 클래스가 먼저 호출이 된다.
	Second sec;
public:
	First()
	{
		cout << "class First constructor()" << endl;
	}
};

int main8_3()
{

	// Second -> First 순서로 생성자 호출
	First fir;

	return 0;
}