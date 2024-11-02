#include <iostream>

using namespace std;

// 가상 소멸자

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}
	~Derived() override
	{
		cout << "~Derived" << endl;
		delete[] m_array;
 	}
};

int main12_4()
{
	//Derived derived(5);

	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;

	return 0;
}