#pragma once
#include "file.h"

// 8-8 클래스 코드와 헤더 파일
// 헤더 파일에서 using name space 같은 걸 써버리면 include 하는것들이
// 모두 영향을 받음

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		:m_value(init_value)
	{

	}
	// 함수 선언만 만금
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