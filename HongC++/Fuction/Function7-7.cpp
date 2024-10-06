#include <iostream>

using namespace std;

// 함수 오버로딩
// 주의 사항 : 매개 변수가 다르면 다른 함수라고 생각 한다.


int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

// return 타입이 다르지만 매개변수가 같기 때문에 함수 오버로딩이 되지 않는다.
//int add(double x, double y)
//{
//	return x + y;
//}

// return 값이 아닌 매개변수로 값을 돌려 받는 형식으로 
// 함수 오버로딩을 사용한다.
void getRandomValue(int &x) {}
void getRandomValue(double &x) {}

int main7_7_1()
{
	// 컴파일 시점에 어떤 함수를 사용 할 지 결정이 되어야 한다.
	add(1, 2);
	add(3.0, 4.0);

	// error 발생! : void 형식으로 변수를 초기화 할 수 없다.
	//int x = getRandomValue(x);
	int x;
	getRandomValue(x);

	return 0;
}


typedef int my_int;

//void print(int x) {}		// my_int와 같다.
//void print(my_int x) {}		// my_int와 같다.(typedef를 쓰더라도 컴파일에겐 같다.)

//void print(const char* vale) {}
//void print(int value) {}
void print(unsigned int value) {}
void print(float value) {}

int main7_7_2()
{
	//print(0);

	// char형이지만 int 타입으로 인식 하고 있어 문제가 발생
	// const 키워드를 넣어주면 char형 함수로 인식 한다.
	//print("a"); 
				
	//print("a");	// 문자로 넣어주면 함수를 찾지 못한다.(const 없이는)

	// 모호성으로 인해 컴파일이 어떤 함수를 써야 할 지 몰라함
	//print(3.14159);		-> error 발생
	// f기호를 통해 double과 float형에서 모호해 하지 않고 float형으로 처리함
	print(3.14159f);	

	print((unsigned int)'a');	// 캐스팅을 통해 함수 오버로딩의 모호성을 제거 함

	return 0;
}

