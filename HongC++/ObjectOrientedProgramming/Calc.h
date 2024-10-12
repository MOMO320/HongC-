#pragma once
#include "file.h"

// 8-8 클래스 코드와 헤더 파일
// 헤더 파일에서 using name space 같은 걸 써버리면 include 하는것들이
// 모두 영향을 받음

// 헤더 파일에 왠만하면 정의만 해준다.
class Calc
{
private:
	int m_value;

public:
	Calc(int init_value);
	// 함수 선언만 만금
	Calc& add(int value);

	// 클래스 안에 멤버 함수를 집적 다 정의 해놓을 경우
	// 정의를 할때 인라인 함수라고 인식하고 cpp 파일로 옮길때는
	// 인라인을 붙여줍니다.
	Calc& sub(int value);

	Calc& mult(int value);

	void print();

};