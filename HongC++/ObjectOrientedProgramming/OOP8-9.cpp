#include <iostream>
#include <string>

using namespace std;


// 클래스와 const class
// const를 넣을 수 있는 함수는 넣는게 좋다. 그러면 실수 할 확률이 적다.

class SomethingX
{
public:
	string m_string ="default";
	int m_value = 0;

public:
	//함수 내에 매개변수로 값을 넣으면 값 복사가 일어나지만(초기화)
// 생성자는 한 번 밖에 호출 되지 않는다.
// 그 이유는 숨겨져 있는 복사 생성자가 호출 되기 때문에 또 한번 생성자가 호출 되지
// 않는것이다.(아래와 같은 복사 생성자가 숨겨져 있는 것이다.)
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

int main8_9_1()
{
	MyClass _class;
	_class.m_name;

	// 클래스에 const를 붙이면 const를 붙인 멤버 함수만 사용이 가능하다.
	// 그리고 멤버 변수를 변경하지 않는 함수여야만 가능하다.
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

class SomethingY
{
public:
	string m_value = "defualt";

	// const키워드로 오버로딩이 가능하다.
	// const 멤버 함수는 return 값도 const로 내보낸다.
	const string& getValue() const {
		cout << "const version" << endl;
		return m_value; }
	
	string& getValue() { 
		cout << "non-const version" << endl;
		return m_value; }
};


int main()
{
	SomethingY somethingY;
	somethingY.getValue();	// non-const reference를 return 한다.
	somethingY.getValue() = 10;	// value 변경 가능

	const SomethingY somethingY2;
	somethingY2.getValue();	// const reference를 return 한다.
	//somethingY2.getValue() = 100;	// const이기 때문에 값 변경 안된다.

	return 0;
}