#include <iostream>

using namespace std;

// �Լ� �����ε�
// ���� ���� : �Ű� ������ �ٸ��� �ٸ� �Լ���� ���� �Ѵ�.


int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

// return Ÿ���� �ٸ����� �Ű������� ���� ������ �Լ� �����ε��� ���� �ʴ´�.
//int add(double x, double y)
//{
//	return x + y;
//}

// return ���� �ƴ� �Ű������� ���� ���� �޴� �������� 
// �Լ� �����ε��� ����Ѵ�.
void getRandomValue(int &x) {}
void getRandomValue(double &x) {}

int main7_7_1()
{
	// ������ ������ � �Լ��� ��� �� �� ������ �Ǿ�� �Ѵ�.
	add(1, 2);
	add(3.0, 4.0);

	// error �߻�! : void �������� ������ �ʱ�ȭ �� �� ����.
	//int x = getRandomValue(x);
	int x;
	getRandomValue(x);

	return 0;
}


typedef int my_int;

//void print(int x) {}		// my_int�� ����.
//void print(my_int x) {}		// my_int�� ����.(typedef�� ������ �����Ͽ��� ����.)

//void print(const char* vale) {}
//void print(int value) {}
void print(unsigned int value) {}
void print(float value) {}

int main7_7_2()
{
	//print(0);

	// char�������� int Ÿ������ �ν� �ϰ� �־� ������ �߻�
	// const Ű���带 �־��ָ� char�� �Լ��� �ν� �Ѵ�.
	//print("a"); 
				
	//print("a");	// ���ڷ� �־��ָ� �Լ��� ã�� ���Ѵ�.(const ���̴�)

	// ��ȣ������ ���� �������� � �Լ��� ��� �� �� ������
	//print(3.14159);		-> error �߻�
	// f��ȣ�� ���� double�� float������ ��ȣ�� ���� �ʰ� float������ ó����
	print(3.14159f);	

	print((unsigned int)'a');	// ĳ������ ���� �Լ� �����ε��� ��ȣ���� ���� ��

	return 0;
}

