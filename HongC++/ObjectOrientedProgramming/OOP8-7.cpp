#include "file.h"

// this �����Ϳ� ���� ȣ��

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		// this�� ������ �ִ�.
		this->setID(id);
		this->m_id;

		// this Ű����� �ڱ� �ڽ��� �ּҸ� �˷��ش�.
		cout << "id : " << id << " / " << this << endl;
	}

	void	setID(int id) { m_id = id; }
	int		getID() { return m_id; }
};

int main8_7_1()
{
	// �� �ν��Ͻ����� �����͸� ������ �ְ� this�� �� �� �ִ�.
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);

	cout << &s1 << " " << &s2 << " " << endl;

	// ����� �Ʒ��� ����.(������ �ʴ� �����Ͱ� �ȿ� ����ִ�.)
	//Simple::setID(&s2, 4); == s2.setID(4);

	return 0;
}

//class Calc
//{
//private:
//	int m_value;
//
//public:
//	Calc(int init_value) : m_value(init_value)
//	{
//
//	}
//
//	// �Ʒ��� ���� ��� �� �� �ִ�.(�Ʒ��� ���� �ϸ� ���������� �Լ��� ȣ�� �� �� �ִ�.)
//	Calc& add(int value) { m_value += value; return *this; }
//	Calc& sub(int value) { m_value -= value; return *this; }
//	Calc& mult(int value) { m_value *= value; return *this; }
//	//void add(int value) { m_value += value; }
//	//void sub(int value) { m_value -= value; }
//	//void mult(int value) { m_value *= value; }
//
//	void print()
//	{
//		cout << m_value << endl;
//	}
//};
//
//// ���� ȣ�� ��� �Լ�(chaining member function)
//int main8_7()
//{
//	Calc cal(10);
//	//cal.add(10);
//	//cal.sub(1);
//	//cal.mult(2);
//	//cal.print();
//
//	// ���� ȣ�� ��� �Լ�
//	cal.add(10).sub(1).mult(2).print();
//	
//	// �� �ڵ尡 Ǯ� �Ʒ��� ����.(c++ ���忡�� �� �Ҿ��ϰ� ���ŷӴ�.)
//	Calc& temp1 = cal.add(10);
//	Calc& temp2 = temp1.sub(1);
//	Calc& temp3 = temp2.mult(2);
//	temp3.print();
//
//	return 0;
//}