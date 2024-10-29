#include <iostream>
using namespace std;

// 상속 받은 함수를 감추기
class Base
{
protected:
	int m_i;

public:
	Base(int value)
		: m_i(value)
	{

	}

	void print()
	{
		cout << "I'm base " << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;
public:
	Derived(int int_in)
		:Base(int_in)
	{

	}

	// using을 사용하면 public처럼 되버림(접근 제어 - proteced)
	using Base::m_i;

private:	// 접근 제한자에 using을 이용하여 접근을 제어함
	using Base::print;	
	void print() = delete;	// 부모에서는 접근 가능하지만 자식 객체에서는 접근 안되게함
};

int main11_8()
{
	Base base(4);
	base.print();

	Derived derived(10);
	derived.m_i = 100;
	//derived.print();	// 접근이 안됨
	//derived.print();	using을 이용하여 접근을 못하게 함

	return 0;
}