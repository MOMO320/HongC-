#include <iostream>

using namespace std;

// 6-13.�����Ϳ� const
/*
	int value = 5;
	const int *ptr1 = &value;
	int *const ptr2 = &value;
	const int *const ptr3 = &value;
	
	
	*/


int main()
{

/// case 1
	const int value = 5;
	const int* ptr = &value;
	
	// const Ű���带 ����ϸ� de-reference �� �� ����.
	//*ptr = 6;  // value = 6;
	cout << *ptr << endl;

/// case 2
	int value2 = 10;
	const int* ptr2 = &value; // ���⼭ 'const'�� �ǹ̴� ptr2 �ּҿ� �ִ� ���� �������� �ʴ´ٴ� ��
	//*ptr2 = 20;	// error! �߻� , �׷��� ������ ptr2�� �ִ� ���� �����ϴ°��� ������ �ʴ´�.
	value2 = 30;	// ������ ���������� value2�� ���� �ٲٴ°� ����� �ȴ�.

/// case 3
	int value3 = 5;
	const int* ptr3 = &value3;	// �ּҾȿ� �ִ� ���� �������� �ʴ´ٴ� �ǹ��� 'const'

	int value4 = 6;
	ptr3 = &value4;				// �׷��� ������ ptr3�� �����ϴ� �ּҰ��� �����ϴ°��� �����մϴ�.

/// case 4
	int value5 = 5;
	int* const ptr4 = &value5;	// ���⼭ 'const'�� pointer�� �ּ� ��ü�� ��������� �����ϰ� ��.

	*ptr4 = 10;					// �׷��� ������ �ּҿ� �ִ� ���� ������ ����������
	cout << *ptr << endl;

	int value6 = 12;
//	ptr4 = value6;				// error! , �ּ� ��ü�� �����ϴ°��� �Ұ� �ϴ�.
	
/// case 5
	int value6 = 60;

	// ���⼭ 'const'�� 'pointer'�� �ּҿ� �ּҾȿ� �ִ� �� �Ѵ� ����� �Ͽ� ������ �Ұ���
	const int* const ptr6 = &value6;	

	//*ptr6 = 10;		// error! �ּҾȿ� �ִ� ���� ��� �̹Ƿ� ������ �Ұ���

	int value7 = 70;
	//ptr6 = &value7;   // error! pointer�� �ּҰ� ��� �̹Ƿ� ������ �Ұ���

	return 0;
}