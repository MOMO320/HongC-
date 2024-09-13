#include <iostream>
using namespace std;

// C언어 스타일의 배열 문자열

int main6_6_1()
{
	char myString[] = "string";	// null character가 포함되어 +1 되어 있다.

	cout << sizeof(myString) / sizeof(myString[0]) << endl;

	for (int i = 0; i < 7; ++i)
	{
		cout << (int)myString[i] << endl; // 문자열 마지막이라는 '\0'가 있다.
	}

	char cinString[255];

	//cin >> cinString;

//	cinString[4] = '\0';

	//cout << cinString << endl; // cout는 null character가 나오면 출력을 중단한다.

	// 공백이 있어도 다 출력되게 하는 함수
	cin.getline(cinString,255);

	//cout << cinString;
#pragma region null character만나면 글을 읽는걸 종료되게 처리 하라(내 코드)
	/*int index = 0;
	while (cinString[index] != '\0')
	{
		cout << cinString[index] << " " << (int)myString[index] << " ";
		++index;
	}*/
#pragma endregion

#pragma region null character만나면 글을 읽는걸 종료되게 처리 하라(강의 코드)
	int ix = 0;

	while (true)
	{
		if (cinString[ix] == '\0') break;

		cout << cinString[ix] << " " << (int)cinString[ix] << endl;
		++ix;
	}

#pragma endregion

	return 0;
}

int main6_6_2()
{

	char source[] = "Copy this!";
	char dest[50];

	cout << (int)dest << endl;
	// 아래의 코드는 에러가 발생한다.(error!!!)
	// char형 배열은 대입 연산시 컴파일 단계에서 에러가 발생 합니다.
	// 대입 연산자 왼쪽에 사용한 배열명이 컴파일 과정에서 배열이 할당된
	// 메모리의 주소값으로 바뀌기 때문입니다.
	// 100은 상수로 대입 연산자의 왼쪽에 올 수 없으므로 컴파일 과정에서 에러가
	// 발생합니다. 
	// 다만 strcpy 함수를 사용할 수 있는것은strcpy 함수가 그 위치로 이동하여
	// 메모리 공간을 사용하도록 구현되어 있기 때문입니다.

	/*
		예를 들어 str배열이 메모리 100번째부터 할당되엇다면 다음과 같이 대입하는것과 같습니다.

		[test code]
		char str[80];	// 배열선언
		str = "apple";	// 배열에 문자열 대입
		(str -> 100번째 주소에 할당되어 있음)

		100번지 = "apple" <- 이것과 같음
		
	*/
	//dest = "hello man!"   ----> Error!!
	// 쉽게 정리해서 배열은 포인터이기 때문에 주소를 가르켜 그곳에 직접적으로 대입해 넣을 수 없는것이다.

	strcpy_s(dest,50, source);	// char 배열형 복사 하는 함수

	//cout << source << endl;
	//cout << dest << endl;

	// strcat() : 문자 합하는 함수
	// strcmp() : 두 문자열이 동일한지 비교하는 함수

	return 0;
}
