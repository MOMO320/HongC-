#include "file.h"

// 정적 멤버 함수

/*
	ㅁ 정적 멤버 함수 접근시 주의 할 점
	- this를 써서 멤버 변수에 접근 할 수 없다. (this->)
	- static 멤버 변수만 사용 가능하다.
*/

class SomethingST
{
public:
	// inner class
	class _init
	{
	public:
		_init()
		{	
			// 간접적으로 멤버 변수를 초기화 해줄 수 있다.(방법/굳이??)
			// inner class내에서 static 멤버 변수를 초기화 해줄 수 있다.
			s_value = 9876;
		}
	};

private:
	static int s_value;
	int m_value;
	
	static _init s_initializer;

public:
	// static 멤버 변수는 생성자에서 초기화를 할 수가 없다.
	SomethingST() : m_value(123)/*, s_value(1024)*/ {}
	static int getValue()
	{
		// this를 써서 멤버 변수에 접근 할 수 없다.
		// return this->s_value;
		// return m_value;		// static 변수만 사용 가능하다.
		return s_value;
	}

	void setValue(int value)
	{
		m_value = value;
	}

	int temp()
	{
		return this->m_value;
	}
};


int main8_11()
{
	// 인스턴스가 아니어도 접근 가능
	// private라서 변수에 접근 불가
	//cout << SomethingST::s_value << endl;
	cout << SomethingST::getValue() << endl;

	SomethingST s1, s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;

	// 멤버 함수 포인터 사용 방법
	// 멤버 함수의 경우 인스턴스를 여러개 만든다 해도 함수의 주소는
	// 결국 하나이기 때문에 인스턴스 함수의 주소를 넣어 주면 안됩니다.
	//int (SomethingST:: * fptr1)() = &s1.temp;	-> 인스턴스의 함수 주소 넣으면 에러남

	// 그렇기 때문에 아래와 같이 클래스에 직접 접근해 함수의 주소를 불러와야 합니다.
	int (SomethingST:: * fptr1)() = &SomethingST::temp;
	
	// 하지만 멤버 함수를 사용 할 때에는 인스턴스 객체를 지정해 
	// 지정된 인스턴스 객체의 변수 값을 이용 하도록 해줍니다.

	s1.setValue(20);
	s2.setValue(400);

	cout << (s1.*fptr1)() << endl;	// 출력 값 20
	cout << (s2.*fptr1)() << endl;	// 출력 값 400

	// static 멤버 함수의 경우 클래스에 접근하여 선언 하지 않아도 된다.
	int (* fptr2)() = &SomethingST::getValue;
	// static 멤버 함수는 인스턴스 객체를 불러서 실행시킬 필요가 없다.
	cout << fptr2() << endl;

	return 0;
}

int SomethingST::s_value = 10;
// 아래와 같이 SomethingSt클래스 내에 _init을 초기화 해주면 생성자를 불러와
// s_value의 값이 초기화 된다.
SomethingST::_init SomethingST::s_initializer;