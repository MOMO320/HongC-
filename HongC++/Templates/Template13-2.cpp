#include"MyArray.h"

using namespace std;

// Ŭ���� ���ø�
// 

/*
	- Ŭ���� ���ø� ���� ����
	: Ŭ���� ���ø��� header�� ���� �� ���Ǹ� �� �ؾ��Ѵ�.

	- ���� 
	: ����ϴ� ������ ��� ���ϸ� include�ϱ� ������ .cpp�� �ִ� ������
	��޴ϴ�.
	�׷��� ������ ����� ���Ǹ� �� header�� ����� �����Ϸ��� �ľ��ϰ� 
	�������� ��ȯ�� �Ͽ� ����� �� �ִ�.

	explicit instantiation�� �̿��ϸ� cpp�� ���ø� �������൵ �������� �� �� �ִ�.

*/



int main13_2()
{
	MyArray<char> my_array(10);

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();

	return 0;
}