#include <iostream>
// 유도된 클래스들의 생성 순서
class Mother
{
public:
	int m_i;

	Mother(const int & i_in = 0)
		:m_i(i_in)
	{
		std::cout << "Mother construction" << std::endl;
	}

};

class Child : public Mother
{
public:
	double m_d;

public:	// 직접 부모 클래스의 생성자를 불러서 초기화 해줄 수 있다.
		// 컴파일러는 Mother 생성자의 위치가 어떻건에 먼저 호출해 준다.
	Child()			// 초기화가 이렇게 안되는 이유는 Mother클래스에서 
		:  m_d(1.0),Mother(1024) //, m_i(10) -> 초기화가 안되었기 때문이다.
	{
		std::cout << "Child Construction" << std::endl;
		//this->m_i = 10;
		//Mother::m_i = 1024;
		//this->Mother::m_i = 1025;
	}
};

int main11_3_1()
{
	// Mother에 있는거 다 초기화 하고 Child를 초기화 해준다.
	// Mother -> Child
	Child child1;

	return 0;
}

class A
{
public:
	A()
	{
		std::cout << "A Constructor" << std::endl;
	}

};

class B : public A
{
public:
	B()
	{
		std::cout << "B Constructor" << std::endl;
	}
};

class C : public B
{
public:
	C()
	{
		std::cout << "C Constructor" << std::endl;
	}
};

int main11_3_2()
{
	C c1;	// A -> B -> C

	B b1;	// A -> B

	A a1;   // A
	return 0;
}