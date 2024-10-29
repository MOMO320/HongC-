#include <iostream>
using namespace std;

// ��� ���� �Լ��� ���߱�
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

	// using�� ����ϸ� publicó�� �ǹ���(���� ���� - proteced)
	using Base::m_i;

private:	// ���� �����ڿ� using�� �̿��Ͽ� ������ ������
	using Base::print;	
	void print() = delete;	// �θ𿡼��� ���� ���������� �ڽ� ��ü������ ���� �ȵǰ���
};

int main11_8()
{
	Base base(4);
	base.print();

	Derived derived(10);
	derived.m_i = 100;
	//derived.print();	// ������ �ȵ�
	//derived.print();	using�� �̿��Ͽ� ������ ���ϰ� ��

	return 0;
}