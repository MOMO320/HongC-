#include <iostream>

using namespace std;

// ��ӹ��� �Լ��� �������̵� �ϱ�(Overrding)

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value(value)
	{

	}

	void print()
	{
		cout << "I'm base " << endl;
	}

	friend std::ostream& operator<< (std::ostream& out, const Base& b)
	{
		out << "This is base output" << endl;
		return out;
	}

	void Something()
	{
		cout << "Base Something " << endl;
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

	void print()
	{
		Base::print();
		cout << "I'm derived " << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Derived& d)
	{
		// ���� ����ȯ�� ���� Base�� output operator �����ε��� �ϰ� ���ش�.
		cout << static_cast<Base>(d);	// Derived���� Base�� �����͸� �˱� ������ ����ȯ�� �����ϴ�.
		out << "This is Derived output" << endl;
		return out;
	}

};

int main11_7()
{
	Base base(5);
	//base.print();
	cout << base;


	Derived derived(8);
	//derived.print();
	cout << derived;

	return 0;
}