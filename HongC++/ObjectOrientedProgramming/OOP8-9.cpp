#include <iostream>
#include <string>

using namespace std;


// 클래스와 const class
// const를 넣을 수 있는 함수는 넣는게 좋다. 그러면 실수 할 확률이 적다.

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
	// 클래스에 const를 붙이면 const를 붙인 멤버 함수만 사용이 가능하다.
	// 그리고 멤버 변수를 변겨아하지 않는 함수여야만 가능하다.
	Something something;
	print(something);
	//something.getValue();
	//something.setString("s");
	//something.setValue(3);

	//cout << something.getValue() << endl;

	return 0;
}