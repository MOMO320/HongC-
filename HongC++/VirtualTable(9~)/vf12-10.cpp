#include <iostream>
#include <string>

using namespace std;

// 동적 형변환(Dynamic Casting)
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

	// Derived1의 주소를 가지고 있는 base를 다른 데이터형으로
	// 형변환 하면 에러가 발생한다.(당연한 얘기)
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);		// 동적 형변환
	auto* base_to_d1_static = static_cast<Derived1*>(base);	// 정적 형변환
	// static_cast의 경우 최대한 형변환을 해준다.
	// 다만 런타임에서 에러체크를 해주지 않는다.
	auto* base_to_d2_static = static_cast<Derived2*>(base);	// 정적 형변환

	if (base_to_d1 != nullptr)
		base_to_d1->print();
	else
		cout << "fail" << endl;

	if (base_to_d1_static != nullptr)
		base_to_d1_static->print();
	else
		cout << "fail static" << endl;

	if (base_to_d2_static != nullptr)
		base_to_d2_static->print();	// 정상적으로 출력 됨 (i'm derived)
	else
		cout << "fail d2 static" << endl;


	//base_to_d1->m_j = 3000;
	
	cout << d1.m_j << endl;

	// Dynamic_cast 주의할점
	/*
		데이터형이 맞지 않는 형변환은 에러가 발생한다.
		dynamic_cast는 nullptr 체크해서 문제점을 확인해 준다.

		static_cast의 경우 최대한에 형변환을 해준다.
		문제는 런타임에서 에러 체크를 해주지 않는다.
	*/
	 

	return 0;
}