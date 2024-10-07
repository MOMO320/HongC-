#include <iostream>
#include <vector>

using namespace std;

// vector�� ����ó�� ����ϱ�

int main7_11_1()
{
	// ���� �迭
	// int *v = new int[3]{1,2,3}; �Ʒ��� �ڵ�� ���� �ڵ�� ����.
	vector<int> v{ 10,20,30 };
	
	//v.resize(2);
	v.reserve(1024);	// �޸� �뷮 ����,
	
	/* -size->capacity�ȿ��� ���߿� �� ���� ����Ѵٰ� ���� �ϸ� �ȴ�.
	
	   - capacity(�뷮) -> �����δ� capacity ��ŭ �޸𸮸� ��� �ְ�
	  
	   - reserve�� �޸��� �뷮�� �̸� Ȯ�� �س��� �ְڴ�.
	   �̸� �뷮�� Ȯ���ϸ� new, delete�� ȣ���ϴ� Ƚ���� �پ� �ӵ��� ��������.
	*/

	// size�� ���缭 for-each���� ���ư���.
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// for�� ����
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	cout << v.size() << " / "  << v.capacity() <<  endl;
	

#pragma region ������ size������ ��� ������ �������� ���

	// vector�� ���� ������� resize�� ��� size�� ���̰� �뷮�� ������ �ʰ� ������ �ִ�.
	// delete�� ������ �������� ������ �뷮�� �ٷ� ������ �ʴ´�.

	// ���� ������ �ڵ�
	int* my_ptr = &v[0];
	cout << *(my_ptr + 2) << endl;

	// ������ �ڵ�
	int* ptr = v.data();
	cout << ptr[2] << endl;

#pragma endregion


	return 0;
}

void printStack(const vector<int>& stack)
{
	for (auto& e : stack)
		cout << e << " ";

	cout << "/ size : " << stack.size() << endl;
	cout << endl;
}

int main7_11_2()
{
	std::vector<int> stack;

	stack.push_back(3);
	printStack(stack);
	stack.push_back(5);
	printStack(stack);
	stack.push_back(7);
	printStack(stack);
	stack.pop_back();
	printStack(stack);
	stack.pop_back();
	printStack(stack);
	stack.pop_back();


	return 0;
}