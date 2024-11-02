#include <iostream>

using namespace std;

// ���� Ŭ�������� ��� ������ ����ϱ�
// ����� ���� ���� ���� �Լ��� �������̵� �ϴ� ���
class Base
{
public:
	Base() {}

	// ����� �ƴ϶� overriding�� �� �� ����.
	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main12_11()
{
	Base b;
	cout << b << '\n';	//Base

	Derived d;
	cout << d << '\n';	//Derived

	Base& bref = d;
	cout << bref << '\n';	//Derived

	return 0;
}