#include "file.h"

// 친구 함수와 클래스 friend

// 전방선언
// : 전방 선언을 하면 클래스 선언 위치에 상관 없이 사용 할 수 있다.
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

	// friend 선언을 해주면 private안에 있는것을 사용 가능하게 한다.
	// friend member function
	friend void B::doSomething(A& a);
	
	//friend void doSomething(A& a , B& b);


	friend class B;
};

void B::doSomething(A& a)
{
	cout << a.m_value << endl;
}


// 연산자 overloading에서 많이 사용함(friend)
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