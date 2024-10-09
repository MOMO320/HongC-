#include "file.h"

// 생성자의 멤버 이니셜라이져 리스트

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
	// 기본 생성자가 있을 경우 멤버 변수 자체에서 초기화 하는 것보다 우선 순위가 높다.
	// ( ) : 초기화 해주는걸 이니셜라이져 리스트 라고 한다.
	Something() : m_i(1), m_d(3.14), m_c('a'), m_arr{1,2,3,4,5}, m_b(m_i -1)
	{
		// 이니셜라이저 리스트에서 초기화 해주고 '{' 안에 있는 값으로 초기화 된다.
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