#include <iostream>
#include <memory>
using namespace std;

// 예외처리 위험성과 단점

class A
{
public:
	~A()
	{	// 소멸자에서는 예외를 못던지게 되어있다.
		// 소멸자는 정상적으로 예외를 던질 상태가 안된다.(사양)
		throw "error";
	}
};


int main14_6()
{
	try
	{
		int* i = new int[100000000];
		unique_ptr<int> up_i(i);
		//do something with i
		throw "error";

		// smart포인터를 사용하면 알아서 메모리를 날려준다.
		//delete[] i;

		A a;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}