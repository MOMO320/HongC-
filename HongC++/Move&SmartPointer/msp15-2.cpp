#include <iostream>

using namespace std;

// 오른쪽-값 참조
// R-value References
// move semantics를 사용할 수 있는지 판별

int getResult()
{
	return 100 * 100;
}

// 오버로딩이 L-value와 R-value가 다르게 기능할 수 있도록 인정해 준다.
void doSomething(int& lref)
{
	cout << "L-value ref" << endl;
}

void doSomething(int&& ref)
{
	cout << "R-value ref" << endl;
}

int main15_2()
{
	// x는 메모리를 가지고 있는 것이고
	// 5는 문장이 끝나면 사라질 운명
	// : 곧 사라질 r-value를 왼쪽에 l-value, 
	// 메모리를 차지하고 있는 변수에 복사해 넣어서 그 값을 계속
	// 이후에 사용하겠다라는 의미
	int x = 5;	
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	// L-value references
	{
		int& lr1 = x;		// Modifiable l-values
		
		// 컴파일 안됨
		//int& lr2 = cx;	// Non-Modifiable l-values
		//int& lr3 = 5;		// R-values(R-value에는 references를 가질 수 있다.)

		const int& lr4 = x;		// Modifiable l-values
		const int& lr5 = cx;	// Non-Modifiable l-values
		const int& lr6 = 5;		// R-values(const는 가능하다.)
	}

	// R-value references (R-value는 &가 두개다 -> &&) -> Rvalue만 밖을 수 있다.
	{ // 나 아니면 진짜 접근할 수 없어, 그리고 나만 값을 바꾸거나 나만 사용할 수 있어라는 의미

		// 컴파일 안됨
		//int&& rr1 = x;		// Modifiable l-values
		//int&& rr2 = cx;		// Non-modifiable l-values
		int&& rr3 = 5;			// R-values (곧 사라지는 애들만 담을 수 있다.)
		int&& rrr = getResult();
		
		cout << rr3 << endl;
		rr3 = 10;
		cout << rr3 << endl;

		// 컴파일 안됨
		//const int&& rr4 = x;	// Modifiable l-values
		//const int&& rr5 = cx;	// Non-modifiable l-values
		const int&& rr6 = 5;	// R-values
	}

	// L/R-value reference parameters
	doSomething(x);
	//doSomething(cx);
	doSomething(5);
	doSomething(getResult());

	return 0;
}