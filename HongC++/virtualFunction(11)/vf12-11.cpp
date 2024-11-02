#include <iostream>

using namespace std;

// 유도 클래스에서 출력 연산자 사용하기
// 멤버로 만들 수가 없는 함수를 오버라이딩 하는 방법
class Base
{
public:
	Base() {}

	// 멤버가 아니라서 overriding을 할 수 없다.
	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main12_11()
{
	Base b;
	cout << b << '\n';	//Base

	Derived d;
	cout << d << '\n';	//Derived

	Base& bref = d;
	cout << bref << '\n';	//Derived

	return 0;
}