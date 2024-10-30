#include <iostream>
#include <string>
using namespace std;

// ���� ���� �Լ�, �߻� �⺻ Ŭ����, �������̽� Ŭ����
// Pure	, Abstact, Interface

/*
 - ���� ���� �Լ� : 

 - �߻� �⺻ Ŭ���� :

 - �������̽� Ŭ���� : 
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

	// �ڽ� Ŭ�������� �ݵ�� �����϶�
	virtual void speak() const = 0;	// = 0 -> pure virtual function

	//virtual void speak() const
	//{
	//	cout << m_name << "???" << endl;
	//}
};

// �����غ��� ȣ�� �� �� ����.
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
	// Abstract �߻� Ŭ������ �ν��Ͻ��� ���� �� ����.
	//Animal ani("Hi");	// error!!

	// ���� �����Լ��� ������ ���� �ʾҴٴ� ������ �߻�
	Cow cow("hello");

	return 0;
}