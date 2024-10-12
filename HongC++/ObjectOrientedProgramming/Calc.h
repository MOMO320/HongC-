#pragma once
#include "file.h"

// 8-8 Ŭ���� �ڵ�� ��� ����
// ��� ���Ͽ��� using name space ���� �� ������� include �ϴ°͵���
// ��� ������ ����

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		:m_value(init_value)
	{

	}
	// �Լ� ���� ����
	Calc& add(int value);

	Calc& sub(int value)
	{
		m_value -= value;
		return *this;
	}

	Calc& mult(int value)
	{
		m_value *= value;
		return *this;
	}

	void print()
	{
		cout << m_value << endl;
	}

};