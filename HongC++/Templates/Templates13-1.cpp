#include<iostream>

using namespace std;

// 함수 템플릿
// 
// 템플릿은 데이터형 타입에 대한 인스턴스를 만들어냄
// 
// typename 자리에 class 키워드가 들어올 수 도 있다.
// class가 들어오면 어떤 클래스가 타입이 될 수 있다고 생각하면 된다.
// 크게 다른점은 없다고 생각하면 됩니다.

// 질문 1 : 템플릿은 컴파일러 실행 되야 데이터형에 맞춰 코드 복사가 이뤄지는 건가?
// 아님 작성만해도 바로 컴파일러가 실시간으로 처리해 주는건가?

// 질문 2 : '템플릿 인스턴스', '인스턴시에이션' 용어에 대해 정리 필요

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents): m_cents(cents) 
	{

	}
	
	bool operator>(const Cents& other)
	{
		return (this->m_cents > other.m_cents);
	}
	
	// friend를 사용한 방법
	//friend bool operator>(const Cents& c1, const Cents& c2)
	//{
	//	return (c1.m_cents > c2.m_cents);
	//}

	friend ostream& operator<<(ostream& os, const Cents& c)
	{
		os << c.m_cents << " cents";
		return os;
	}

};

//template<typename T>
//T getMax(T x, T y)
//{
//	return (x > y) ? x : y;
//}

//int getMax(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//double getMax(double x, double y)
//{
//	return (x > y) ? x : y;
//}
//
//float getMax(float x, float y)
//{
//	return (x > y) ? x : y;
//}

int main13_1()
{
	// 컴파일러가 내부적으로 다 만들어주고 있다.]
	// function overloading 처럼해서 컴파일러가 바꿔서 해주고 있다.

	// 
	//cout << getMax(1, 2) << endl;
	//cout << getMax(3.14, 1.58) << endl;
	//cout << getMax(1.0f, 3.4f) << endl;
	//cout << getMax('a', 'c') << endl;
	//cout << getMax("strd", "srr") << endl;

	//cout << getMax(Cents(5), Cents(9)) << endl;	// 9 cents

	return 0;
}
