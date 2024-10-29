#include <iostream>
// ������ Ŭ�������� ���� ����
class Mother
{
public:
	int m_i;

	Mother(const int & i_in = 0)
		:m_i(i_in)
	{
		std::cout << "Mother construction" << std::endl;
	}

};

class Child : public Mother
{
public:
	double m_d;

public:	// ���� �θ� Ŭ������ �����ڸ� �ҷ��� �ʱ�ȭ ���� �� �ִ�.
		// �����Ϸ��� Mother �������� ��ġ�� ��ǿ� ���� ȣ���� �ش�.
	Child()			// �ʱ�ȭ�� �̷��� �ȵǴ� ������ MotherŬ�������� 
		:  m_d(1.0),Mother(1024) //, m_i(10) -> �ʱ�ȭ�� �ȵǾ��� �����̴�.
	{
		std::cout << "Child Construction" << std::endl;
		//this->m_i = 10;
		//Mother::m_i = 1024;
		//this->Mother::m_i = 1025;
	}
};

int main11_3_1()
{
	// Mother�� �ִ°� �� �ʱ�ȭ �ϰ� Child�� �ʱ�ȭ ���ش�.
	// Mother -> Child
	Child child1;

	return 0;
}

class A
{
public:
	A()
	{
		std::cout << "A Constructor" << std::endl;
	}

};

class B : public A
{
public:
	B()
	{
		std::cout << "B Constructor" << std::endl;
	}
};

class C : public B
{
public:
	C()
	{
		std::cout << "C Constructor" << std::endl;
	}
};

int main11_3_2()
{
	C c1;	// A -> B -> C

	B b1;	// A -> B

	A a1;   // A
	return 0;
}