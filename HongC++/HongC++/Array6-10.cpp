#include <iostream>
using namespace std;

const char* getName()
{
	return "Jackjack";
}

int main()
{
	//char name[] = "Jack Jack";

	/// �Ϲ������� char *name = "Jack Jack"; �� error�� ����.
	/// �ֳ��ϸ� "Jack Jack"�� �ּҰ� �ƴ� ���ͷ��̱� �����Դϴ�.
	/// ������ 'const' Ű���带 ������ �ϳ��� ���� �����Ѵ�.
	/// �׷��� �ٸ� �̸��� ������ ���� ��(���ͷ�)�� ������ �� ������ ���� �ȴ�.
	/// �Ʒ��� 'name'�� 'name2'�� �ּҰ� ����.
	const char* name = "Jack Jack";
	const char* name2 = "Jack Jack";
	const char* name3 = "jack jack";

	cout << (uintptr_t)name << endl;	// Jack Jack�� ���� name �� name2�� ���� ���� �ּҰ��� ���´�.
	cout << (uintptr_t)name2 << endl;
	cout << (uintptr_t)name3 << endl;

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World!";
	const char* char_name = "Jack Jack";

	cout << "----------------------------------------" << endl;
	
	cout << int_arr << endl;
	cout << "char_arr : " << char_arr << endl;		// cout������ ���ڿ��� Ư���ϰ� ó���Ѵ�.
	cout << "char_name : " << char_name << endl;	// ���ڿ� �����ʹ� c��Ÿ���� ���ڸ� ����Ų�ٰ� �����ϰ� ���ڿ� array�� �����ϰ�
													// null character�� ���������� ����� �Ѵ�.
	
	cout << "*char_arr : " << *char_arr << endl;
	cout << "*char_name : " << *char_name << endl;

	char c = 'Q';

	// char���� �ּҸ� ����Ϸ��� �ϴϱ� �����Ϸ��� ���ڿ����� �˰� 
	// null character�� ���������� ���ڿ��� ��� �Ϸ��� �Ѵ�. 
	cout <<"&c : " << &c << endl;
	cout << "c : " << c << endl;


	return 0;
}