#include <iostream>
#include <cstddef>

using namespace std;

void DoSomething(double* ptr)
{
	// 넘겨주는 데이터와 다른 메모리를 사용하여 ptr의 주소가 다르다.
	// 인자로 넘겨주는 변수는 따로 선언하여 사용 하는것이다.

	if (ptr != nullptr)
	{
		cout << *ptr << endl;
	}
	else
	{
		cout << "Null ptr , do nothing" << endl;
	}

	cout << "address of pointer varaible in DoSomething() " << &ptr << endl;

}

void Check(double d)
{
	cout << "address of reference variable in Check()" << &d << endl;
}

int main6_8()
{
	double* ptr = nullptr;	// modern c++

	// pointer데이터가 잘 들어왔는지 체크를 nullptr로 한다.
	if (ptr != nullptr)
	{
		// do something useful
	}
	else
	{
		// do something with ptr
	}

	DoSomething(ptr);
	DoSomething(nullptr);

	double d = 123.4;

	ptr = &d;
	
	DoSomething(&d);
	DoSomething(ptr);

	cout << "address of pointer varaible in main() "<< &ptr << endl;

	nullptr_t nptr;	// nullptr밖에 못 넣는다.(nullptr_t)

	Check(d);
	cout << "address of reference variable in main" << &d << endl;

	cout << *ptr << endl;
	return 0;
}