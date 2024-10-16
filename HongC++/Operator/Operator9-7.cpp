#include <iostream>

using namespace std;

// 괄호 연산자 오버로딩과 함수 객체 Function object(Functor)

class Accumulator
{
private:
	int m_counter = 0;

public:
	// 
	Accumulator(int _value) : m_counter(_value) {}
	int operator()(int i) { return (m_counter += i); }
};

int main9_7()
{
	Accumulator acc(20);
	cout << acc(10) << endl;
	cout << acc(20) << endl;


	return 0;
}