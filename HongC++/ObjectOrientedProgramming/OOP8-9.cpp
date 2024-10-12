#include <iostream>
#include <string>

using namespace std;


// Ŭ������ const class
// const�� ���� �� �ִ� �Լ��� �ִ°� ����. �׷��� �Ǽ� �� Ȯ���� ����.

class SomethingX
{
public:
	string m_string ="hhh";
	int m_value = 0;

public:
	//�Լ� ���� �Ű������� ���� ������ �� ���簡 �Ͼ����(�ʱ�ȭ)
// �����ڴ� �� �� �ۿ� ȣ�� ���� �ʴ´�.
// �� ������ ������ �ִ� ���� �����ڰ� ȣ�� �Ǳ� ������ �� �ѹ� �����ڰ� ȣ�� ����
// �ʴ°��̴�.(�Ʒ��� ���� ���� �����ڰ� ������ �ִ� ���̴�.)
	SomethingX(const SomethingX& st_in)
	{
		m_value = st_in.m_value;
		cout << "Copy Constructor" << endl;
	}
	SomethingX()
	{
		cout << "Constructor" << endl;
	}
	//Something(int _int, string _string) {
	//	m_value = _int;
	//	m_string = _string;
	//}

	void setValue(int value) { m_value = value; }
	void setString(string _name) { m_string = _name; }
	int getValue() { return m_value; }
};

class MyClass
{
public:
	std::string m_name = "HJakc";
public:
	//MyClass(string _name) : m_name(_name) {}

};


void print(SomethingX st)
{
	cout << "print in : " << &st << endl;
	cout << st.m_value << endl;
	cout << st.m_string << endl;
}

int main()
{
	MyClass _class;
	_class.m_name;

	// Ŭ������ const�� ���̸� const�� ���� ��� �Լ��� ����� �����ϴ�.
	// �׸��� ��� ������ ���ܾ����� �ʴ� �Լ����߸� �����ϴ�.
	//Something something(10,"hello");
	SomethingX something;
	cout << "main in : " << &something << endl;
	print(something);
	//something.getValue();
	//something.setString("s");
	//something.setValue(3);

	//cout << something.getValue() << endl;

	return 0;
}