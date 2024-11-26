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

		typedef decltype(x)			x_type;
		typedef decltype(cx)		cx_type;
		typedef decltype(crx)		crx_type;
		typedef decltype
	}
};

int main()
{
	Example example;

	example.ex7_8();

	return 0;
}