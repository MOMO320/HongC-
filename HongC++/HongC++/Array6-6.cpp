#include <iostream>
using namespace std;

// C��� ��Ÿ���� �迭 ���ڿ�

int main6_6_1()
{
	char myString[] = "string";	// null character�� ���ԵǾ� +1 �Ǿ� �ִ�.

	cout << sizeof(myString) / sizeof(myString[0]) << endl;

	for (int i = 0; i < 7; ++i)
	{
		cout << (int)myString[i] << endl; // ���ڿ� �������̶�� '\0'�� �ִ�.
	}

	char cinString[255];

	//cin >> cinString;

//	cinString[4] = '\0';

	//cout << cinString << endl; // cout�� null character�� ������ ����� �ߴ��Ѵ�.

	// ������ �־ �� ��µǰ� �ϴ� �Լ�
	cin.getline(cinString,255);

	//cout << cinString;
#pragma region null character������ ���� �д°� ����ǰ� ó�� �϶�(�� �ڵ�)
	/*int index = 0;
	while (cinString[index] != '\0')
	{
		cout << cinString[index] << " " << (int)myString[index] << " ";
		++index;
	}*/
#pragma endregion

#pragma region null character������ ���� �д°� ����ǰ� ó�� �϶�(���� �ڵ�)
	int ix = 0;

	while (true)
	{
		if (cinString[ix] == '\0') break;

		cout << cinString[ix] << " " << (int)cinString[ix] << endl;
		++ix;
	}

#pragma endregion

	return 0;
}

int main6_6_2()
{

	char source[] = "Copy this!";
	char dest[50];

	cout << (int)dest << endl;
	// �Ʒ��� �ڵ�� ������ �߻��Ѵ�.(error!!!)
	// char�� �迭�� ���� ����� ������ �ܰ迡�� ������ �߻� �մϴ�.
	// ���� ������ ���ʿ� ����� �迭���� ������ �������� �迭�� �Ҵ��
	// �޸��� �ּҰ����� �ٲ�� �����Դϴ�.
	// 100�� ����� ���� �������� ���ʿ� �� �� �����Ƿ� ������ �������� ������
	// �߻��մϴ�. 
	// �ٸ� strcpy �Լ��� ����� �� �ִ°���strcpy �Լ��� �� ��ġ�� �̵��Ͽ�
	// �޸� ������ ����ϵ��� �����Ǿ� �ֱ� �����Դϴ�.

	/*
		���� ��� str�迭�� �޸� 100��°���� �Ҵ�Ǿ��ٸ� ������ ���� �����ϴ°Ͱ� �����ϴ�.

		[test code]
		char str[80];	// �迭����
		str = "apple";	// �迭�� ���ڿ� ����
		(str -> 100��° �ּҿ� �Ҵ�Ǿ� ����)

		100���� = "apple" <- �̰Ͱ� ����
		
	*/
	//dest = "hello man!"   ----> Error!!
	// ���� �����ؼ� �迭�� �������̱� ������ �ּҸ� ������ �װ��� ���������� ������ ���� �� ���°��̴�.

	strcpy_s(dest,50, source);	// char �迭�� ���� �ϴ� �Լ�

	//cout << source << endl;
	//cout << dest << endl;

	// strcat() : ���� ���ϴ� �Լ�
	// strcmp() : �� ���ڿ��� �������� ���ϴ� �Լ�

	return 0;
}
