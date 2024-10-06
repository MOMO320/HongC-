#include <iostream>
#include <string>
using namespace std;

// �Ű������� �⺻ ��

// default parameter
//void print(int x = 1024)
//{
//	cout << x << endl;
//}

// �Լ� �����ε��� ���� ������ Ÿ���� �Ű� ������ default parameter��
// ������ �����Ϸ��� � �Լ��� ����ؾ� �ϴ��� �򰥷� �մϴ�.
// �׷��� ������ ���� ������ Ÿ���� �Լ� �����ε��� �� �� default parameter�� 
// ����ϴ� ���� �����ؾ� �Ѵ�.

// �Լ� ����� ���Ǹ� ���� �Ѵٸ� �ѱ��������� default parameter�� �ʱ�ȭ �ؾ� �Ѵ�.
void print(int x = 10, int y = 20, int z = 30);	// in header


void print(int x , int y , int z  )
{
	// default parameter�� �Ҷ� ������ �Ű� �������� �ʱ�ȭ�� �����ָ� error�� �߻��Ѵ�.
	cout << x << " " << y << " " << z << endl;
}

void print(std::string str) {}
void print(char ch = ' ') {}

int main()
{
	print(10);	// 10 , 20 , 30
	//print();	// 10, 20, 30
	print(100, 200); // 100, 200, 30
	print(100, 200, 300);	// 100, 200, 300


	return 0;
}