#include<iostream>

using namespace std;

// �Լ� ���ø�
// 
// ���ø��� �������� Ÿ�Կ� ���� �ν��Ͻ��� ����
// 
// typename �ڸ��� class Ű���尡 ���� �� �� �ִ�.
// class�� ������ � Ŭ������ Ÿ���� �� �� �ִٰ� �����ϸ� �ȴ�.
// ũ�� �ٸ����� ���ٰ� �����ϸ� �˴ϴ�.

// ���� 1 : ���ø��� �����Ϸ� ���� �Ǿ� ���������� ���� �ڵ� ���簡 �̷����� �ǰ�?
// �ƴ� �ۼ����ص� �ٷ� �����Ϸ��� �ǽð����� ó���� �ִ°ǰ�?

// ���� 2 : '���ø� �ν��Ͻ�', '�ν��Ͻÿ��̼�' �� ���� ���� �ʿ�

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents): m_cents(cents) 
	{

	}
	
	bool operator>(const Cents& other)
	{
		return (this->m_cents > other.m_cents);
	}
	
	// friend�� ����� ���
	//friend bool operator>(const Cents& c1, const Cents& c2)
	//{
	//	return (c1.m_cents > c2.m_cents);
	//}

	friend ostream& operator<<(ostream& os, const Cents& c)
	{
		os << c.m_cents << " cents";
		return os;
	}

};

//template<typename T>
//T getMax(T x, T y)
//{
//	return (x > y) ? x : y;
//}

//int getMax(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//double getMax(double x, double y)
//{
//	return (x > y) ? x : y;
//}
//
//float getMax(float x, float y)
//{
//	return (x > y) ? x : y;
//}

int main13_1()
{
	// �����Ϸ��� ���������� �� ������ְ� �ִ�.]
	// function overloading ó���ؼ� �����Ϸ��� �ٲ㼭 ���ְ� �ִ�.

	// 
	//cout << getMax(1, 2) << endl;
	//cout << getMax(3.14, 1.58) << endl;
	//cout << getMax(1.0f, 3.4f) << endl;
	//cout << getMax('a', 'c') << endl;
	//cout << getMax("strd", "srr") << endl;

	//cout << getMax(Cents(5), Cents(9)) << endl;	// 9 cents

	return 0;
}
