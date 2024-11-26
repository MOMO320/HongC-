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
		auto& rc = c;
		rc = 123;
	}
};

int main()
{
	Example example;

	return 0;
}