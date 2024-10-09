#include "file.h"

// �������� ��� �̴ϼȶ����� ����Ʈ

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in) : m_b(m_b_in) {}
};

class A
{
private:
	int _a;

public:
	void print()
	{
		cout << _a << endl;
	}
};

class Something
{
private:
	int		m_i			= 100;
	double	m_d			= 100.0;
	char	m_c			= 'F';
	int		m_arr[5]	= { 100, 200, 300, 400, 500 };
	B m_b				{1024};
	//int* m_arr_p = new int[10];

	
public:	
	// �⺻ �����ڰ� ���� ��� ��� ���� ��ü���� �ʱ�ȭ �ϴ� �ͺ��� �켱 ������ ����.
	// ( ) : �ʱ�ȭ ���ִ°� �̴ϼȶ����� ����Ʈ ��� �Ѵ�.
	Something() : m_i(1), m_d(3.14), m_c('a'), m_arr{1,2,3,4,5}, m_b(m_i -1)
	{
		// �̴ϼȶ����� ����Ʈ���� �ʱ�ȭ ���ְ� '{' �ȿ� �ִ� ������ �ʱ�ȭ �ȴ�.
		m_i *= 3;
		m_d *= 3.0;
		m_c += 3;
	 }

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		
		for (auto& element : m_arr)
			cout << element << " ";
		cout << endl;

	}
};


int main8_4()
{
	Something some;
	some.print();



	return 0;
}