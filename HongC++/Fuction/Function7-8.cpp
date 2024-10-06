#include <iostream>
#include <string>
using namespace std;

// 매개변수의 기본 값

// default parameter
//void print(int x = 1024)
//{
//	cout << x << endl;
//}

// 함수 오버로딩시 같은 데이터 타입의 매개 변수를 default parameter를
// 넣으면 컴파일러가 어떤 함수를 사용해야 하는지 헷갈려 합니다.
// 그렇기 때문에 같이 데이터 타입의 함수 오버로딩을 할 때 default parameter를 
// 사용하는 것을 조심해야 한다.

// 함수 선언과 정의를 따로 한다면 한군데에서만 default parameter를 초기화 해야 한다.
void print(int x = 10, int y = 20, int z = 30);	// in header


void print(int x , int y , int z  )
{
	// default parameter를 할때 마지막 매개 변수에만 초기화를 안해주면 error가 발생한다.
	cout << x << " " << y << " " << z << endl;
}

void print(std::string str) {}
void print(char ch = ' ') {}

int main()
{
	print(10);	// 10 , 20 , 30
	//print();	// 10, 20, 30
	print(100, 200); // 100, 200, 30
	print(100, 200, 300);	// 100, 200, 300


	return 0;
}