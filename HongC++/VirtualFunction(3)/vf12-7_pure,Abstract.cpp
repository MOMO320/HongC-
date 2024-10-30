#include <iostream>
#include <string>
using namespace std;

// 순수 가상 함수, 추상 기본 클래스, 인터페이스 클래스
// Pure	, Abstact, Interface

/*
 - 순수 가상 함수 : 

 - 추상 기본 클래스 :

 - 인터페이스 클래스 : 
*/

class Animal
{
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name)
	{}
public:
	string getName() { return m_name; }

	// 자식 클래스에서 반드시 구현하라
	virtual void speak() const = 0;	// = 0 -> pure virtual function

	//virtual void speak() const
	//{
	//	cout << m_name << "???" << endl;
	//}
};

// 구현해봤자 호출 할 수 없다.
void Animal::speak() const	// the body of the pure virtual function
{
	cout << m_name << "???" << endl;
}

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name)
	{

	}

	void speak()const
	{
		cout << m_name << "meow~~" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name)
	{}

	void speak() const
	{
		cout << m_name << "wooof~~" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow(string name) : Animal(name)
	{}

	virtual void speak() const
	{
		cout << m_name << " mooo~" << endl;
	}
};

int main12_7_pureFunction()
{
	// Abstract 추상 클래스는 인스턴스를 만들 수 없다.
	//Animal ani("Hi");	// error!!

	// 순수 가상함수를 재정의 하지 않았다는 에러가 발생
	Cow cow("hello");

	return 0;
}