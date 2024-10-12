#include "file.h"

// this 포인터와 연쇄 호출

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		// this가 숨겨져 있다.
		this->setID(id);
		this->m_id;

		// this 키워드로 자기 자신의 주소를 알려준다.
		cout << "id : " << id << " / " << this << endl;
	}

	void	setID(int id) { m_id = id; }
	int		getID() { return m_id; }
};

int main8_7_1()
{
	// 각 인스턴스들이 포인터를 가지고 있고 this로 볼 수 있다.
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);

	cout << &s1 << " " << &s2 << " " << endl;

	// 개념상 아래와 같다.(보이지 않는 포인터가 안에 들어있다.)
	//Simple::setID(&s2, 4); == s2.setID(4);

	return 0;
}

//class Calc
//{
//private:
//	int m_value;
//
//public:
//	Calc(int init_value) : m_value(init_value)
//	{
//
//	}
//
//	// 아래와 같이 사용 할 수 있다.(아래와 같이 하면 연속적으로 함수를 호출 할 수 있다.)
//	Calc& add(int value) { m_value += value; return *this; }
//	Calc& sub(int value) { m_value -= value; return *this; }
//	Calc& mult(int value) { m_value *= value; return *this; }
//	//void add(int value) { m_value += value; }
//	//void sub(int value) { m_value -= value; }
//	//void mult(int value) { m_value *= value; }
//
//	void print()
//	{
//		cout << m_value << endl;
//	}
//};
//
//// 연쇄 호출 멤버 함수(chaining member function)
//int main8_7()
//{
//	Calc cal(10);
//	//cal.add(10);
//	//cal.sub(1);
//	//cal.mult(2);
//	//cal.print();
//
//	// 연쇄 호출 멤버 함수
//	cal.add(10).sub(1).mult(2).print();
//	
//	// 위 코드가 풀어서 아래와 같다.(c++ 입장에서 좀 불안하고 번거롭다.)
//	Calc& temp1 = cal.add(10);
//	Calc& temp2 = temp1.sub(1);
//	Calc& temp3 = temp2.mult(2);
//	temp3.print();
//
//	return 0;
//}