#include <iostream>

using namespace std;

// 가상 함수 테이블(Virtual Tables)

class Base
{
public:
	// FunctionPointer *_vptr;
	virtual void fun1() {};
	void fun2() {};
};

class Der : public Base
{
public:
	// FunctionPointer *_vptr;
	void fun1() {};
	void fun3() {};
};

int main12_6()
{
	cout << sizeof(Base) << endl;
	cout << sizeof(Der) << endl;


	return 0;
}