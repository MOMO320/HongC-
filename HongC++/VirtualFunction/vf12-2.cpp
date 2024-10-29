#include <iostream>

using namespace std;

// 가상 함수와 다형성(Virtual Functions Polymorphism
// : virtual을 사용할때 너무 자주 호출 하거나 다중 for문안에 있는 함수로
// 사용하면 현저히 느려진다.

class A
{
public:
	int m_a;
public:
	virtual  void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	int m_b;
public:
	virtual void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	int m_c;

public:
	virtual void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	int m_d;
public:
	virtual void print() 
	{ 
		cout << "D" << endl; 
	}
};

int main12_2()
{
	A a;
	a.print();
	
	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();

	A& ref1 = c;
	ref1.print();

	C& ref2 = d;
	ref2.print();

	return 0;
}