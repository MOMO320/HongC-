#include <iostream>

using namespace std;

// 상속받은 함수를 오버라이딩 하기(Overrding)

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
		// 정적 형변환을 통해 Base의 output operator 오버로딩을 하게 해준다.
		cout << static_cast<Base>(d);	// Derived에서 Base의 데이터를 알기 때문에 형변환이 가능하다.
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