#include <iostream>

using namespace std;

// ���� �Լ� ���̺�(Virtual Tables)

class Base
{
public:
	Base() 
	{
		cout << "Base" << endl;
	};
	// FunctionPointer *_vptr;
	virtual void fun1() {};
	virtual void something() {};
	void fun2() {};
};

class Der : public Base
{
public:
	Der()
	{
		cout << "Der" << endl;
	};
	// FunctionPointer *_vptr;
	void fun1() {};
	void fun3() {};
};

int main12_6()
{
	cout << sizeof(Base) << endl;
	cout << sizeof(Der) << endl;

	Base * my_base = new Base();
	Der * my_der = new Der();


	return 0;
}