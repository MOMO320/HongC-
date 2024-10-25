#include <iostream>

using namespace std;

// 상속의 기본(Inheritance / is-a relationship)
// 상속을 하면 재사용이 용이하다.

class Mother
{
protected:
	int m_i;

public:	
	Mother() :m_i(0)
	{
		// default constructor
	}
	Mother(const int& i_in)
		: m_i(i_in)
	{
		cout << "Mother constructor( )" << endl;
	}

	void setValue(const int& int_in)
	{
		cout << "Mother::setValue()" << endl;
		m_i = int_in;
	}
	
	int getValue()
	{
		cout << "Mother::getValue()" << endl;
		return m_i;
	}
};
//derived class -> 상속 받은 클래스를 이렇게 부르기도 함
class Child : public Mother	
{
private:
	double m_d;
public:	// 메모리가 할당될때 실행하는 함수(constructor)
	Child(const int& i_in, const double& d_in) : Mother(i_in), m_d(d_in)
	{
		cout << "Child Constructor( )" << endl;
	}
	void setValue(const int & i_in, const double& d_in)
	{
		cout << "Child::setValue()" << endl;
		Mother::setValue(i_in);
		m_d = d_in;
	}

	double getValue()
	{
		cout << "Child::getValue()" << endl;
		return m_d;
	}

	friend std::ostream& operator<<(std::ostream& out, const Child& child)
	{
		out << "mother m_i : " << child.m_i << "/ child m_d : " << child.m_d;
		return out;
	}
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main11_1()
{
	//Mother mother(1025);
	//mother.setValue(1024);
	//cout << mother.getValue() << endl;

	//child.Mother::setValue(1024);
	//child.setValue(1,123);
	//cout << child.Mother::getValue() << endl;
	//cout << child.getValue() << endl;

	Child child(1024, 125);
	cout << child << endl;
	return 0;
}