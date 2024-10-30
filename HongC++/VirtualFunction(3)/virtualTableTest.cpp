#include <iostream>

using namespace std;

class Parents
{
public:
	virtual void Func1()
	{
		cout << "void A::Func1" << endl;
	}

	virtual void Something()
	{
		cout << "void A::Something" << endl;

	}
	void Func2()
	{
		cout << "void A::Func2" << endl;
	}

};

class Child : public Parents
{
public:
	void Func1() override
	{
		cout << "void B::Func1" << endl;
	}

	virtual void Func3()
	{
		cout << "void B::Func3" << endl;
	}
};


int mainTest() 
{
	Parents* parents = new Child();
	Parents* parents2 = new Parents();
	Child* child = new Child();

	parents2->Func1();
	parents->Func1();
	parents->Func2();
	child->Func3();
	child->Something();


	return 0;
}