#include <iostream>
#include <string>

using namespace std;

// ���� ����ȯ(Dynamic Casting)
class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	void something()
	{
		cout << "something Derived1" << endl;
	}

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr.Two";

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

int main12_10()
{
	Derived1 d1;
	Base* base = &d1;
	d1.m_j = 1024;

	// Derived1�� �ּҸ� ������ �ִ� base�� �ٸ� ������������
	// ����ȯ �ϸ� ������ �߻��Ѵ�.(�翬�� ���)
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);		// ���� ����ȯ
	auto* base_to_d1_static = static_cast<Derived1*>(base);	// ���� ����ȯ
	// static_cast�� ��� �ִ��� ����ȯ�� ���ش�.
	// �ٸ� ��Ÿ�ӿ��� ����üũ�� ������ �ʴ´�.
	auto* base_to_d2_static = static_cast<Derived2*>(base);	// ���� ����ȯ

	if (base_to_d1 != nullptr)
		base_to_d1->print();
	else
		cout << "fail" << endl;

	if (base_to_d1_static != nullptr)
		base_to_d1_static->print();
	else
		cout << "fail static" << endl;

	if (base_to_d2_static != nullptr)
		base_to_d2_static->print();	// ���������� ��� �� (i'm derived)
	else
		cout << "fail d2 static" << endl;


	//base_to_d1->m_j = 3000;
	
	cout << d1.m_j << endl;

	// Dynamic_cast ��������
	/*
		���������� ���� �ʴ� ����ȯ�� ������ �߻��Ѵ�.
		dynamic_cast�� nullptr üũ�ؼ� �������� Ȯ���� �ش�.

		static_cast�� ��� �ִ��ѿ� ����ȯ�� ���ش�.
		������ ��Ÿ�ӿ��� ���� üũ�� ������ �ʴ´�.
	*/
	 

	return 0;
}