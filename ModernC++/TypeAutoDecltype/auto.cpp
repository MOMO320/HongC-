#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 자료형 추론 auto와 decltype

/*
	auto
	: auto는 가장 기본적인 자료형을 추론하여 데이터형을 맞춰준다.
	예를 들어 const, &, volatile 키워드를 제외하고 순수하게 자료형만이 추론한다.

	원하는 데로 const, &, volatile 를 추가하려면 일반적인 방법을 auto를 데이터형처럼 하여
	선언해 준다.

	ex) const auto& _data; -> const와 & 다 사용된다.

*/

class Example
{
public:
	void ex1()
	{
		std::vector<int> vect;
		for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		// auto키워드가 생기면서 간단하게 선언 가능함
		for (auto itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;
	}

	void ex2()
	{
		// auto는 const와 reference를 제외하고 추론한다.
		int x = int();

		auto auto_x = x;

		const int& crx = x;
		
		auto auto_crx1 = crx; // int형으로 추론 

		// const와 reference를 auto에 추가해서 원하는 형으로 추론 할 수 있다.
		const auto& auto_crx2 = crx;  

		int* ptr = &x;

		auto ptr_auto = ptr;  // 포인터는 정상적으로 형 추론이 가능하다.

		// volatile : 데이터가 자주 바뀌니깐 최적화 하지 말아달라는 키워드
		volatile int vx = 1024;

		auto avx = vx;  // volatile 키워드가 제외된 int형만 추론됨

		volatile auto vavx = vx; // volatile키워드를 추가하여 원하는 데이터형으로 만듬
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
		func_ex3(crx); // 이것또한 int형만 인식함
	
		func_ex3_2(crx); // const int& 데이터형으로 인식
	}

	void ex4()
	{
		const int c = 0;
		auto& rc = c; // 이럴때는 const auto &로 인식을 해줍니다.
		//rc = 123; // const로 인해 값 변경이 안됨
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
		auto p2 = p1;  // const int* 데이터형으로 추론 됨
	}

	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)
	{
		// 어떤 자료형이 될지 모를때는 auto를 이용해주면 자동으로 추론해줘서 좋다.
		auto prod1 = lhs * rhs; 

		// 데이터 타입을 리턴해주는 함수가 있었다.
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