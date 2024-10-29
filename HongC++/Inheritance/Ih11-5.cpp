#include <iostream>

using namespace std;

// ��Ӱ� ���� ������
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
		//Derived::m_private = 2;	private�ϱ� ������ �ȵ�
	}
};

class GrandChild2 : public Derived2
{
public:
	GrandChild2()
	{
		Derived2::m_protected = 3000;	// protected�� ���ڵ� ���� ����
		Derived2::m_public = 1000;
	}
};

class GrandChild3 : public Derived3
{
public:
	GrandChild3()
	{
		// ���ڿ��Դ� �ȵ�
		// privateó�� �Ǽ� ������ �ȵ�
		//Derived2::m_protected = 3000;	// ��͵� ���� �ȵ�
		//Derived2::m_public = 1000;
	}
};

int main11_5()
{
	Base base;
	base.m_public = 123;

	Derived der;
	der.m_public = 1024;	// only public�� ���� ��
	//der.m_protected;	 �ܺο��� ���� �ȵ�
	//der.m_private;

	Derived2 der2;
	//der2.m_public = 1000;
	//der2.m_protected = 20000;

	GrandChild gr1;
	GrandChild2 gr2;
	GrandChild3 gr3;
	
	gr1.m_public = 1000;	// ���ڿ��� public�� ���� ������
	//gr2.m_public = 200;		// public���� �ȵ�
	//gr2.m_protected = 300;	// protected�� ���� �ȵ�
	//gr3.					��͵� �ȳ���


	return 0;
}