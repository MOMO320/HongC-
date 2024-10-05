#include <iostream>

using namespace std;

// 값에 의한 인수 전달
// Call By Value

// Call By Value는 외부에 영향을 주지 않는다.

// 함수 인자로 값 전달 할 경우(call by value)
// 매개 인자 변수가 선언되면서 넘겨준 값으로 초기화 하게 된다.
// 그러면서 값 복사가 일어나게 되는것 이다.
void doSomething(int y)	
{
	// doSomething의 함수가 실행되면서 int y 가 선언되면서
	cout << " In func " << y << " " << &y << endl;
}

int main7_2()
{
	// y의 변수 메모리에 값 5로 초기화가 된다.
	doSomething(5);

	int x = 6;	

	cout << " In main " << x << " " << &x << endl;

	// 실제로 변수'x'가 넘어가는 것이 아닌 값을 넘겨주는것
	doSomething(x);	
	doSomething(x + 1);

	return 0;
}