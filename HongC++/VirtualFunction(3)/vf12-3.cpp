#include <iostream>

using namespace std;

// override, final, 공변 반환형 Covariant
// 함수 파라미터가 틀리면 overriding이 되지 않는다.

// override 키워드 : override 한다는걸 컴파일러에게 알려주는 
// 키워드(다를경우 에러를 뱉어준다.)

class A
{
public:
	 void print(int x) { cout << "A" << endl; }
	virtual void something() { cout << "A something..." << endl; }
	virtual A* getThis() 
	{
		cout << "A::getThis()" << endl;
		return this; }
};

class B : public A
{
public:
	void print(int x)  { cout << "B" << endl; }
	virtual void something() final { cout << "B something..." << endl; }
	virtual B* getThis() override 
	{
		cout << "B::getThis()" << endl;
		return this;
	}
};

class C : public B
{
	// 상속 받은 함수에서 final 키워드가 붙은 virtual 함수의 경우
	// 더 이상 override를 할 수 없어진다.
	//virtual void something() { cout << "C something..." << endl; }
	 void print() {cout << "C" << endl; }
};

int main12_3()
{
	A a;
	B b;

	A& ref = b;
	//ref.print(1);
	b.getThis()->print(10);	// B
	ref.getThis()->print(10);	// A

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;

	return 0;
}