#include "file.h"

// ģ�� �Լ��� Ŭ���� friend

// ���漱��
// : ���� ������ �ϸ� Ŭ���� ���� ��ġ�� ��� ���� ��� �� �� �ִ�.
class A;

class B
{
public:
	int m_value = 2;

	//friend void doSomething(A& a, B& b);
	void doSomething(A& a);
};

class A
{
private:
	int m_value = 1;

	// friend ������ ���ָ� private�ȿ� �ִ°��� ��� �����ϰ� �Ѵ�.
	// friend member function
	friend void B::doSomething(A& a);
	
	//friend void doSomething(A& a , B& b);


	friend class B;
};

void B::doSomething(A& a)
{
	cout << a.m_value << endl;
}


// ������ overloading���� ���� �����(friend)
//void doSomething(A& a , B& b)
//{
//	cout << a.m_value << b.m_value << endl;
//}

int main8_12()
{
	A a;
	B b;
	//doSomething(a, b);

	b.doSomething(a);

	return 0;
}