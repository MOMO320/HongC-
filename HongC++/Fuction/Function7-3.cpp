#include <iostream>
#include <cmath> // sin(), cos()
#include <vector>

using namespace std;

// 참조에 의한 인수 전달(Call By Reference)
// 값에 의한 인수 전달 보다 참조의 경우 메모리를 덜 소모한다.

// 참조에 의한 호출은 변수 자체를 넘기기 때문에 인자의 주소가 같고
// 복사가 이루어지지 않습니다.
void addOne(int& y)
{
	// &y == &x 주소가 같다.
	cout << y << " " << &y << endl;
	y = y + 1;
}

int main7_3_1()
{
	int x = 5;

	cout << x << " " << &x << endl; // x = 5

	addOne(x);

	cout << x << " " << &x << endl; // x = 6

	return 0;
}

// const 키워드를 넣으면 리터럴을 넣어도 된다.
// 다만 함수내에서 변경을 할 수 없다.
void foo(const int& x)
{
	cout << x << endl;
}

void getSinCos(const double degree, double& sin_out, double& cos_out)
{
	static const double pi = 3.141592 / 180.0;

	double radians = degree * pi;
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

int main7_3_2()
{
	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);

	cout << sin << " " << cos << endl;
	
	foo(6);		// call by reference이기 때문에 리터럴을 넣어주면 안된다.
				// (const 키워드를 넣으면 가능하다.)

	return 0;
}


// pointer를 call by reference로 받는 방법
void  foo(int*& ptr)
{
	cout <<"In foo : " << ptr << " " << &ptr << endl;
}

typedef int* pint;
// 헷갈리지 않게 typedef로 int* 타입을 지정해 선언하면 편하다.
//void foo(pint& ptr)
//{
//	cout << ptr << " " << &ptr << endl;
//}

int main7_3_3()
{
	int x = 5;
	int* ptr = &x;
	pint ptrP = &x;

	cout << "In main x: " << &x << endl;

	cout <<"In main : " << ptr << " " << &ptr << endl;
	foo(ptr);

	return 0;
}

// 정적 배열이기 때문에 element의 갯수가 반드시 들어가야 합니다.
// 정적 배열 call by reference 인자 넣는 방법
void printElement(int (&arr)[4])
{

}

// 동적 배열 call by reference 인자 넣는 방법
void printVecElement(const vector<int>& arr)
{

}

int main7_3_4()
{
	int arr[]{ 1,2,3,4 };
	vector<int> arrV{ 1,2,3,4 };

	printElement(arr);


	return 0;
}