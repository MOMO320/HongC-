#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ڷ��� �߷� auto�� decltype

/*
	auto
	: auto�� ���� �⺻���� �ڷ����� �߷��Ͽ� ���������� �����ش�.
	���� ��� const, &, volatile Ű���带 �����ϰ� �����ϰ� �ڷ������� �߷��Ѵ�.

	���ϴ� ���� const, &, volatile �� �߰��Ϸ��� �Ϲ����� ����� auto�� ��������ó�� �Ͽ�
	������ �ش�.

	ex) const auto& _data; -> const�� & �� ���ȴ�.

*/

class Example
{
public:
	void ex1()
	{
		std::vector<int> vect;
		for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		// autoŰ���尡 ����鼭 �����ϰ� ���� ������
		for (auto itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;
	}

	void ex2()
	{
		// auto�� const�� reference�� �����ϰ� �߷��Ѵ�.
		int x = int();

		auto auto_x = x;

		const int& crx = x;
		
		auto auto_crx1 = crx; // int������ �߷� 

		// const�� reference�� auto�� �߰��ؼ� ���ϴ� ������ �߷� �� �� �ִ�.
		const auto& auto_crx2 = crx;  

		int* ptr = &x;

		auto ptr_auto = ptr;  // �����ʹ� ���������� �� �߷��� �����ϴ�.

		// volatile : �����Ͱ� ���� �ٲ�ϱ� ����ȭ ���� ���ƴ޶�� Ű����
		volatile int vx = 1024;

		auto avx = vx;  // volatile Ű���尡 ���ܵ� int���� �߷е�

		volatile auto vavx = vx; // volatileŰ���带 �߰��Ͽ� ���ϴ� ������������ ����
	}

	template<class T>
	void func_ex3(T arg)
	{

	}

	template<class T>
	void func_ex3_2(const T& arg)
	{

	}

	void ex3()
	{
		const int& crx = 123;
		func_ex3(crx); // �̰Ͷ��� int���� �ν���
	
		func_ex3_2(crx); // const int& ������������ �ν�
	}

	void ex4()
	{
		const int c = 0;
		auto& rc = c; // �̷����� const auto &�� �ν��� ���ݴϴ�.
		//rc = 123; // const�� ���� �� ������ �ȵ�
	}

	void ex5()
	{
		int i = 42;
		auto&& ri_1 = i;   // l-value
		auto&& ri_2 = 42;  // r-value;
	}

	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1;  // const int* ������������ �߷� ��
	}

	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)
	{
		// � �ڷ����� ���� �𸦶��� auto�� �̿����ָ� �ڵ����� �߷����༭ ����.
		auto prod1 = lhs * rhs; 

		// ������ Ÿ���� �������ִ� �Լ��� �־���.
		//typedef typeof(lhs* rhs) product_type; 
		typedef decltype(lhs* rhs) product_type;

		product_type prod2 = lhs * rhs;

		decltype(lhs * rhs) prod3 = lhs * rhs;
	}

	template<typename T, typename S>
	auto  func_ex8(T lhs, S rhs) -> decltype(lhs* rhs)
	{
		return lhs * rhs;
	}

	void ex7_8()
	{
		cout << typeid(func_ex7(1.0, 345)).name() << endl;
		cout << typeid(func_ex8(1.2, 345)).name() << endl;
	}

	struct S
	{
		int m_x;

		S()
		{
			m_x = 42;
		}
	};

	void ex9()
	{
		int x;
		const int cx = 53;
		const int& crx = x;
		const S* p = new S();

		auto a = x;
		auto b = cx;
		auto c = crx;
		auto d = p;
		auto e = p->m_x;


		// decltype : ������ ������ Ÿ������ �����ɴϴ�.
		typedef decltype(x)			x_type;
		typedef decltype(cx)		cx_type;	// const int
		typedef decltype(crx)		crx_type;	// const int &
		typedef decltype(p->m_x)	m_x_type;	//"declared" type , int

		//��ȣ�ϳ��� �� ������ &�� �پ� ����
		typedef decltype((x))		x_with_parens_type;		// add references to lvalues
		typedef decltype((cx))		cx_with_parens_type;	
		typedef decltype((crx))		crx_with_parens_type;
		typedef decltype((p->m_x))	m_w_with_parens_type; // const int&
	}

	const S foo()
	{
		return S();
	}

	const int& foobar()
	{
		return 123;
	}

	void ex10()
	{
		std::vector<int> vect = { 42, 43 };

		auto a = foo();  // const s
		typedef decltype(foo()) foo_type; //const s

		auto b = foobar();  // int 
		typedef decltype(foobar())	foobar_type; //const int&

		auto itr = vect.begin();   //vector<int>::iterator
		typedef decltype(vect.begin()) iterator_type;  //vector<int>::iterator

		auto first_element = vect[0];   // int
		decltype(vect[1]) second_element = vect[1];  // int& ([] : ���ȣ operator�� int&�� ���۷����� ������ �˴ϴ�.)
	}

	void ex11()
	{
		int x = 0;
		int y = 0;
		const int cx = 42;
		const int cy = 43;
		double d1 = 3.14;
		double d2 = 2.72;

		typedef decltype(x* y) prod_xy_type;
		auto a = x * y;

		typedef decltype(cx* cy) prod_cxcy_type;	// result is prvalue (int)
		auto b = cx * cy;

		typedef decltype(d1 < d2 ? d1 : d2) cond_type;	// result is lvalue. &is added.
		auto c = d1 < d2 ? d1 : d2;

		typedef decltype(x < d2 ? x : d2) cond_type_mixed;	//promotion of x to double
		auto d = x < d2 ? x : d2;

	}
};

int main()
{
	Example example;

	example.ex7_8();

	return 0;
}