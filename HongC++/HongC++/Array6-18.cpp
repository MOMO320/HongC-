#include<iostream>

using namespace std;

// 6.18 void pointer , generic pointer(���������� ��� �����Ͽ� ���׸� �����Ͷ�� �Ҹ���.)

int main6_18_1()
{
	int i = 5;
	float f = 3.0f;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	// char���� �ּҸ� ����Ϸ��� �ϴϱ� �����Ϸ��� ���ڿ����� �˰� 
	// null character�� ���������� ���ڿ��� ��� �Ϸ��� �Ѵ�. 
	//cout << &c << " " << ptr << endl;
	cout << &f << " " << ptr << endl;
	//cout << *ptr << endl;	//� ������������ ���� ������ �߻� �մϴ�.
	// �׷��� ������ � ������������ �˷��ֱ� ���� ĳ������ ����� �Ѵ�.
	cout << *static_cast<float*>(ptr) << endl; // �������� �� 3.0�� ����

	int* ptr_i = &i;

	// �Ϲ����� �����ʹ� ������ ������ �����ϴ�.
	//cout << ptr_i << endl;
	//cout << ptr_i + 1 << endl;

	// ������ ���̵� �������� ��� ������ ������ �� ���� ����.(�ֳ��ϸ� �������� ũ�⸦ �� �� ���� �����̴�.)
	//cout << ptr + 1 << endl;


	return 0;
}

enum Type
{
	INT,
	FLOAT,
	CHAR
};

// Ÿ�Ժ� ĳ���� ���ִ� ���
// void �����͸� ����ϱ� ���� �´� ������������ ĳ���� �Ͽ� �����͸� ����� �ݴϴ�.
int main6_18_2()
{
	int i = 5;
	float f = 3.0f;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;

	Type type = FLOAT;

	if (type == FLOAT)
		cout << *static_cast<float*>(ptr) << endl;
	else if (type == INT)
		cout << *static_cast<int*>(ptr) << endl;

	return 0;
}