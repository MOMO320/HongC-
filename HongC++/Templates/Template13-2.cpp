#include"MyArray.h"

using namespace std;

// 클래스 템플릿
// 

/*
	- 클래스 템플릿 주의 사항
	: 클래스 템플릿은 header에 선언 및 정의를 다 해야한다.

	- 이유 
	: 사용하는 곳에서 헤더 파일만 include하기 때문에 .cpp에 있는 내용을
	모급니다.
	그렇기 때문에 선언과 정의를 다 header에 해줘야 컴파일러가 파악하고 
	데이터형 변환을 하여 사용할 수 있다.

	explicit instantiation을 이용하면 cpp에 템플릿 정의해줘도 컴파일이 알 수 있다.

*/



int main13_2()
{
	MyArray<char> my_array(10);

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();

	return 0;
}