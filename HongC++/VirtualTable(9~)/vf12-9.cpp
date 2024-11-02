#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

// ��ü �߸��� reference_wrapper (Object slicing)

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

// ���簡 �Ͼ �������� ���� �ʴ´�.
//void doSomething(Base b)
//{
//	b.print();
//}

int main12_9_1()
{
	Derived d;
	Base &b = d;	// �ʱ�ȭ �ϸ� ���� ������

	/*
		Base &b = d; -> �̷��� ���� �� ��� Derived�� �ν��Ͻ��� d�� �ּҰ�
		Base& �ν��Ͻ��� b�� �ּҸ� �����ϸ鼭
		���� �ּҸ� ����Ű�� �˴ϴ�.
		�׷��� �Ǹ� Object Slice�� �Ͼ�� �ʰ� �˴ϴ�.

		������ sizeof�� �� �ν��Ͻ��� �޸� ����� ���� ���̰� ���ϴ�.

		sizeof(d) = 24
		sizeof(b) = 16 
	
		b�� �ּ� : 0000005BD47BF788
		d�� �ּ� : 0000005BD47BF7B8

		���� Base& b = d; �̷��� �ʱ�ȭ �� ���
		
		b�� d�� �ּҰ� ��������.
	*/


	cout << sizeof(d) << endl;
	cout << sizeof(b) << endl;

	cout << &d << endl;
	cout << &b << endl;

	//���⼱ ������ �Ű������� �ޱ� ������ ���������� ��
	doSomething(d);	// I'm Derived ���
	b.print();	// I'm Base ���
	return 0;
}

int main12_9_2()
{
	Base b;
	Derived d;

	std::vector<Base> my_vec;

	my_vec.push_back(b); //I'm Base�� ���ɴϴ�.
	// Derived�� �ν��Ͻ��� �־����� ��ü�� �ִ� �������� �����̽��� �Ǿ�
	my_vec.push_back(d); //I'm Base�� ���ɴϴ�.

	for (auto& ele : my_vec)
		ele.print();

	cout << "---------------------------------------" << endl;

	std::vector<Base*> my_vec2;
	my_vec2.push_back(&b); //I'm Base�� ���ɴϴ�.
	my_vec2.push_back(&d); //I'm Derived��  ���ɴϴ�.


	for (auto& ele : my_vec2)
		ele->print();

	cout << "---------------------------------------" << endl;
	//std::vector<Base&> my_vec_ref; -> �Ʒ��� ����.
	std::vector<std::reference_wrapper<Base>> my_vec_ref;
	my_vec_ref.push_back(b);
	my_vec_ref.push_back(d);

	for (auto& ele : my_vec_ref)
		ele.get().print();
	

	return 0;
}