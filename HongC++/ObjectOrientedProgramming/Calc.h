#pragma once
#include "file.h"

// 8-8 Ŭ���� �ڵ�� ��� ����
// ��� ���Ͽ��� using name space ���� �� ������� include �ϴ°͵���
// ��� ������ ����

// ��� ���Ͽ� �ظ��ϸ� ���Ǹ� ���ش�.
class Calc
{
private:
	int m_value;

public:
	Calc(int init_value);
	// �Լ� ���� ����
	Calc& add(int value);

	// Ŭ���� �ȿ� ��� �Լ��� ���� �� ���� �س��� ���
	// ���Ǹ� �Ҷ� �ζ��� �Լ���� �ν��ϰ� cpp ���Ϸ� �ű涧��
	// �ζ����� �ٿ��ݴϴ�.
	Calc& sub(int value);

	Calc& mult(int value);

	void print();

};