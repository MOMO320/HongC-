#include <iostream>

using namespace std;

// ���� �Լ��� ������(Virtual Functions Polymorphism
// : virtual�� ����Ҷ� �ʹ� ���� ȣ�� �ϰų� ���� for���ȿ� �ִ� �Լ���
// ����ϸ� ������ ��������.

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