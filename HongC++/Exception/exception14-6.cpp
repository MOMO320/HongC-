#include <iostream>
#include <memory>
using namespace std;

// ����ó�� ���輺�� ����

class A
{
public:
	~A()
	{	// �Ҹ��ڿ����� ���ܸ� �������� �Ǿ��ִ�.
		// �Ҹ��ڴ� ���������� ���ܸ� ���� ���°� �ȵȴ�.(���)
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

		// smart�����͸� ����ϸ� �˾Ƽ� �޸𸮸� �����ش�.
		//delete[] i;

		A a;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}