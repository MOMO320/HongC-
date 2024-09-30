#include<iostream>

using namespace std;

// 6.18 void pointer , generic pointer(포괄적으로 사용 가능하여 제네릭 포인터라고도 불린다.)

int main6_18_1()
{
	int i = 5;
	float f = 3.0f;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	// char형의 주소를 출력하려고 하니깐 컴파일러가 문자열인줄 알고 
	// null character를 만날때까지 문자열을 출력 하려고 한다. 
	//cout << &c << " " << ptr << endl;
	cout << &f << " " << ptr << endl;
	//cout << *ptr << endl;	//어떤 데이터형인지 몰라 에러가 발생 합니다.
	// 그렇기 때문에 어떤 데이터형인지 알려주기 위해 캐스팅을 해줘야 한다.
	cout << *static_cast<float*>(ptr) << endl; // 정상적인 값 3.0이 나옴

	int* ptr_i = &i;

	// 일반적인 포인터는 포인터 연산이 가능하다.
	//cout << ptr_i << endl;
	//cout << ptr_i + 1 << endl;

	// 하지만 보이드 포인터의 경우 포인터 연산을 할 수가 없다.(왜냐하면 데이터의 크기를 알 수 없기 때문이다.)
	//cout << ptr + 1 << endl;


	return 0;
}

enum Type
{
	INT,
	FLOAT,
	CHAR
};

// 타입별 캐스팅 해주는 방법
// void 포인터를 사용하기 위해 맞는 데이터형으로 캐스팅 하여 데이터를 사용해 줍니다.
int main6_18_2()
{
	int i = 5;
	float f = 3.0f;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;

	Type type = FLOAT;

	if (type == FLOAT)
		cout << *static_cast<float*>(ptr) << endl;
	else if (type == INT)
		cout << *static_cast<int*>(ptr) << endl;

	return 0;
}