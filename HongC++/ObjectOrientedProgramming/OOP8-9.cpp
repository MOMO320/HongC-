#include <iostream>
#include <string>

using namespace std;


// Ŭ������ const class
// const�� ���� �� �ִ� �Լ��� �ִ°� ����. �׷��� �Ǽ� �� Ȯ���� ����.

class Something
{
public:
	int m_value = 0;
	std::string m_string;
	void setValue(int value) { m_value = value; }
	void setString(string _name) { m_string = _name; }
	int getValue() const { return m_value; }
};

class MyClass
{
public:
	std::string m_name = "HJakc";
public:
	MyClass(string _name) : m_name(_name) {}

};

void print(Something st)
{
	cout << st.m_value << endl;
	cout << st.m_string << endl;
}

int main()
{
	// Ŭ������ const�� ���̸� const�� ���� ��� �Լ��� ����� �����ϴ�.
	// �׸��� ��� ������ ���ܾ����� �ʴ� �Լ����߸� �����ϴ�.
	Something something;
	print(something);
	//something.getValue();
	//something.setString("s");
	//something.setValue(3);

	//cout << something.getValue() << endl;

	return 0;
}