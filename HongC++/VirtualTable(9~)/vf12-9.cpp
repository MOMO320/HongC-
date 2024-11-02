#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

// 객체 잘림과 reference_wrapper (Object slicing)

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print()
	{
		cout << "I'm Derived" << endl;
	}
};


void doSomething(Base& b)
{
	b.print();
}

// 복사가 일어나 다형성이 되지 않는다.
//void doSomething(Base b)
//{
//	b.print();
//}

int main12_9_1()
{
	Derived d;
	Base &b = d;	// 초기화 하며 복사 대입함

	/*
		Base &b = d; -> 이렇게 대입 할 경우 Derived의 인스턴스인 d의 주소가
		Base& 인스턴스인 b에 주소를 대입하면서
		같은 주소를 가르키게 됩니다.
		그렇게 되면 Object Slice가 일어나지 않게 됩니다.

		실젭로 sizeof로 각 인스턴스의 메모리 사이즈를 보니 차이가 납니다.

		sizeof(d) = 24
		sizeof(b) = 16 
	
		b의 주소 : 0000005BD47BF788
		d의 주소 : 0000005BD47BF7B8

		만약 Base& b = d; 이렇게 초기화 할 경우
		
		b와 d의 주소가 같아진다.
	*/


	cout << sizeof(d) << endl;
	cout << sizeof(b) << endl;

	cout << &d << endl;
	cout << &b << endl;

	//여기선 참조로 매개변수를 받기 때문에 다형성으로 됨
	doSomething(d);	// I'm Derived 출력
	b.print();	// I'm Base 출력
	return 0;
}

int main12_9_2()
{
	Base b;
	Derived d;

	std::vector<Base> my_vec;

	my_vec.push_back(b); //I'm Base가 나옵니다.
	// Derived의 인스턴스를 넣었지만 객체를 넣는 과정에서 슬라이스가 되어
	my_vec.push_back(d); //I'm Base가 나옵니다.

	for (auto& ele : my_vec)
		ele.print();

	cout << "---------------------------------------" << endl;

	std::vector<Base*> my_vec2;
	my_vec2.push_back(&b); //I'm Base가 나옵니다.
	my_vec2.push_back(&d); //I'm Derived가  나옵니다.


	for (auto& ele : my_vec2)
		ele->print();

	cout << "---------------------------------------" << endl;
	//std::vector<Base&> my_vec_ref; -> 아래와 같다.
	std::vector<std::reference_wrapper<Base>> my_vec_ref;
	my_vec_ref.push_back(b);
	my_vec_ref.push_back(d);

	for (auto& ele : my_vec_ref)
		ele.get().print();
	

	return 0;
}