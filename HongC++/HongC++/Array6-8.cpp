#include <iostream>
#include <cstddef>

using namespace std;

void DoSomething(double* ptr)
{
	// �Ѱ��ִ� �����Ϳ� �ٸ� �޸𸮸� ����Ͽ� ptr�� �ּҰ� �ٸ���.
	// ���ڷ� �Ѱ��ִ� ������ ���� �����Ͽ� ��� �ϴ°��̴�.

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

	// pointer�����Ͱ� �� ���Դ��� üũ�� nullptr�� �Ѵ�.
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

	nullptr_t nptr;	// nullptr�ۿ� �� �ִ´�.(nullptr_t)

	Check(d);
	cout << "address of reference variable in main" << &d << endl;

	cout << *ptr << endl;
	return 0;
}