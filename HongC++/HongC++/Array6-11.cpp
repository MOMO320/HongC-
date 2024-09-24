#include <iostream>

using namespace std;

// 6-11. �޸� ���� �Ҵ� new �� delete

int main6_11()
{
	// <- error!�߻� �޸� ������ �����ؼ� , stack�� �޸� ������ �����ϴ�.
	//int array[1000000000];	

	
	//int var;					// stack ������ ���� ����	
	int *ptr = new int;			// heap ������ ���� ����(�������� �޸� �Ҵ�)
	int* ptr_ = new (std::nothrow)int{ 7 };	// �̷��� �ʱ�ȭ ����

	// std::nothrow -> new Ű����� �޸� �Ҵ��� ���� �ʴ´ٸ� 
	// nullptr�� ������ ������ �߻��������� �ʰ� �ϴ� ���� ���

	*ptr = 7;

	if (ptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}
	else 
	{
		cout << "Could not allocate memory" << endl; 
	}
	

	delete ptr;					// heap������ �Ҵ�� �޸𸮸� �����ִ� Ű���� -> delete
	ptr = nullptr;
							
	cout << "After delete" << endl;
	if (ptr != nullptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}

	int* ptr2 = ptr;
	
	delete ptr;
	ptr = nullptr;
	ptr2 = nullptr;


	return 0;
}
 

int main6_11_2()
{
	// memory leak(�޸� ����) : �Ҵ� �� �޸𸮸� ������ ���� ������ �߻�
	while (true)
	{
		int* ptr = new int;
		delete ptr;			// delete�� ���� ������ memeory ��뷮�� ��� �þ
	}

	return 0;
}