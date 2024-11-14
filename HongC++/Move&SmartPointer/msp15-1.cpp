#include <iostream>
#include "AutoPtr.h"
#include "Resource.h"
using namespace std;

// Move semantics
// '�̵�'�� �ǹ̿� ����Ʈ ������ �Ұ�(SmartPointer)

// RAII : newŰ����� �޸� �Ҵ��� ���� delete Ű���带 ����ؾ��Ѵ�.(�޸� ����)
// RAII : resource acquisition is initialization


// autoPointer�� �Ѱ��� 
// : �ٸ����� �����Ǿ� ������ �Լ��� ���� �Ǹ鼭 �Ҹ��ڷ� ���� ��ü �Ҹ�Ǿ� �ٸ�������
// ����� �� �� ���� ������ �ִ�.



void doSomething()
{
	try
	{
		// �������� �޸� �Ҵ� �� ���� ���ִ°� ��û�� ������(dullPointer)��� �θ��ϴ�.
		Resource* resA = new Resource;
		AutoPtr<Resource> res = new Resource;	// smart pointer

		return;
		// work with res
		if (true)
		{
			throw - 1; // exception
		}

		//delete res;
	}
	catch (...)
	{

	}

	return;
}

int main15_1()
{
	//doSomething();

	{
		AutoPtr<Resource> res1(new Resource); // int i; int *ptr1(&i); int *ptr2 = nullptr; 
		AutoPtr<Resource> res2;

		cout << std::boolalpha;
		
		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
		
		// ���Կ������� ���� ���� ���簡 �̷�����.
		// ���� ����� ���� �Ҹ��ڰ� �ι� �ҷ��� �ָ鼭 ������ �߻��Ѵ�.
		//res2 = res1;	

		//res2 = res1; // �������� �����ϴ°��� = move semantics

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}

	// syntax vs. semantics
	// syntax = ���� �˻�(������ �Ǵ°ų� �ȵǴ°ų��� ����)
	// semantics = ������ �Ǵ°Ŵ� �� �Ȱ����� ������ �������� �ǹ̰� ���� Ȯ��
	int x = 1, y = 1;
	x + y;

	std::string str1("Hello"), str2("World");
	str1 + str2;	// append

	// value semantics (copy semantics)
	// reference semantics (pointer)
	// move semantics (move)

	return 0;
}