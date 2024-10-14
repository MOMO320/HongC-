#include "file.h"

// Static 정적 멤버 변수

/*
	ㅁ static 정적 멤버 변수 사용 방법
	- static 멤버 변수는 initialize를 할 수 없다.
	- static const일 경우는 가능하다.
	- cpp파일에서 정의 해야 한다.
	- static 멤버 변수의 경우 고유한 값이기 때문에 다른 인스턴스를 만든다고 해도
	  하나의 변수만 존재하여 주소 값이 같다.
	
	ㅁ static 정적 멤버를 사용하는 경우
	- 상수 선언 하는 경우
	- 싱글턴(디자인 패턴)
*/

class Something10
{
public:
	// static 멤버 변수는 initialize를 할 수 없다.
	static int s_value;
	// static const의 경우 클래스 내에서 바로 init을 한다.
	static const int sc_value = 1;	
	static constexpr int se_value = 1;	// 컴파일 타임에 값이 있어야 합니다.
};

int generateID()
{
	static int s_id = 0;
	return ++s_id;
}

// static 멤버일 경우 define in cpp(header에 두면 컴파일 에러가 발생)
// header에 정의 할 경우 중복 정의 문제 발생
int Something10::s_value = 1;	

int main8_10()
{
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << generateID() << endl;

	// instance가 없어도 멤버 static 멤버 변수는 접근이 가능하다.
	cout << &Something10::s_value << " " << Something10::s_value << endl;
	
	Something10 st1;
	Something10 st2;

	//st1.m_value = 2;

	Something10::s_value = 1024;

	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;


	return 0;
}