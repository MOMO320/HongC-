#include <iostream>
#include <cmath> // sin(), cos()
#include <vector>

using namespace std;

// ������ ���� �μ� ����(Call By Reference)
// ���� ���� �μ� ���� ���� ������ ��� �޸𸮸� �� �Ҹ��Ѵ�.

// ������ ���� ȣ���� ���� ��ü�� �ѱ�� ������ ������ �ּҰ� ����
// ���簡 �̷������ �ʽ��ϴ�.
void addOne(int& y)
{
	// &y == &x �ּҰ� ����.
	cout << y << " " << &y << endl;
	y = y + 1;
}

int main7_3_1()
{
	int x = 5;

	cout << x << " " << &x << endl; // x = 5

	addOne(x);

	cout << x << " " << &x << endl; // x = 6

	return 0;
}

// const Ű���带 ������ ���ͷ��� �־ �ȴ�.
// �ٸ� �Լ������� ������ �� �� ����.
void foo(const int& x)
{
	cout << x << endl;
}

void getSinCos(const double degree, double& sin_out, double& cos_out)
{
	static const double pi = 3.141592 / 180.0;

	double radians = degree * pi;
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

int main7_3_2()
{
	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);

	cout << sin << " " << cos << endl;
	
	foo(6);		// call by reference�̱� ������ ���ͷ��� �־��ָ� �ȵȴ�.
				// (const Ű���带 ������ �����ϴ�.)

	return 0;
}


// pointer�� call by reference�� �޴� ���
void  foo(int*& ptr)
{
	cout <<"In foo : " << ptr << " " << &ptr << endl;
}

typedef int* pint;
// �򰥸��� �ʰ� typedef�� int* Ÿ���� ������ �����ϸ� ���ϴ�.
//void foo(pint& ptr)
//{
//	cout << ptr << " " << &ptr << endl;
//}

int main7_3_3()
{
	int x = 5;
	int* ptr = &x;
	pint ptrP = &x;

	cout << "In main x: " << &x << endl;

	cout <<"In main : " << ptr << " " << &ptr << endl;
	foo(ptr);

	return 0;
}

// ���� �迭�̱� ������ element�� ������ �ݵ�� ���� �մϴ�.
// ���� �迭 call by reference ���� �ִ� ���
void printElement(int (&arr)[4])
{

}

// ���� �迭 call by reference ���� �ִ� ���
void printVecElement(const vector<int>& arr)
{

}

int main7_3_4()
{
	int arr[]{ 1,2,3,4 };
	vector<int> arrV{ 1,2,3,4 };

	printElement(arr);


	return 0;
}