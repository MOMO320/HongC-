#include <iostream>

using namespace std;

// 6-15.  참조와 const

// const와 &를 붙이면 상수 값을 그냥 넣을 수 있다.(원래 레퍼런스는 초기화된 변수만 가능했다.)
void doSomething(const int& x)
{
	cout << "doSomething address : " << &x << "/ value : " << x << endl;
}

int main()
{
	int x = 5;
	const int &ref_x = x;	// 값 변경 불가능

	const int& ref_2 = ref_x;

	// 리터럴(상수)로는 초기화가 되지 않으나 const를 붙이면 가능하다.
	// 상수를 넣으면 임의로 주소를 할당하여 넣는것 같다.
	const int& ref_v = 3 + 4;	
	cout << "in main address ref_v : " << &ref_v << endl;

	cout << "in main address x : " << &x << endl;
	doSomething(1);
	doSomething(x + 3);
	doSomething(3 * 4);

	return 0;
}