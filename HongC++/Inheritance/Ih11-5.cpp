#include <iostream>

using namespace std;

// 상속과 접근 지정자
class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;

};

class Derived : public Base
{
public:
	Derived()
	{
		m_public = 123;
		m_protected = 1234;
		//m_private = 1111;
	}
	
};

class Derived2 : protected Base
{
public:
	Derived2()
	{
		m_public = 111;
		m_protected = 222;
		//m_private = 333;
	}
};

class Derived3 : private Base
{
public:
	Derived3()
	{
		m_public = 10000;
		m_protected = 20000;
		//m_private = 30000;
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{						
		Derived::m_public = 1;
		Derived::m_protected = 10;
		//Derived::m_private = 2;	private니깐 접근이 안됨
	}
};

class GrandChild2 : public Derived2
{
public:
	GrandChild2()
	{
		Derived2::m_protected = 3000;	// protected는 손자도 접근 가능
		Derived2::m_public = 1000;
	}
};

class GrandChild3 : public Derived3
{
public:
	GrandChild3()
	{
		// 손자에게는 안됨
		// private처럼 되서 접근이 안됨
		//Derived2::m_protected = 3000;	// 어떤것도 접근 안됨
		//Derived2::m_public = 1000;
	}
};

int main11_5()
{
	Base base;
	base.m_public = 123;

	Derived der;
	der.m_public = 1024;	// only public만 접근 됨
	//der.m_protected;	 외부에서 접근 안됨
	//der.m_private;

	Derived2 der2;
	//der2.m_public = 1000;
	//der2.m_protected = 20000;

	GrandChild gr1;
	GrandChild2 gr2;
	GrandChild3 gr3;
	
	gr1.m_public = 1000;	// 손자여도 public은 접근 ㄱ가능
	//gr2.m_public = 200;		// public접근 안됨
	//gr2.m_protected = 300;	// protected도 접근 안됨
	//gr3.					어떤것도 안나옴


	return 0;
}