#include <iostream>

using namespace std;

// override, final, ���� ��ȯ�� Covariant
// �Լ� �Ķ���Ͱ� Ʋ���� overriding�� ���� �ʴ´�.

// override Ű���� : override �Ѵٴ°� �����Ϸ����� �˷��ִ� 
// Ű����(�ٸ���� ������ ����ش�.)

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
	// ��� ���� �Լ����� final Ű���尡 ���� virtual �Լ��� ���
	// �� �̻� override�� �� �� ��������.
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