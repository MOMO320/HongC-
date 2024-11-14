#include<iostream>
#include "AutoPtr.h"
#include "Resource.h"
#include <vector>
#include <string>

using namespace std;

// std::move

template<class T>
void MySwap(T& a, T& b)
{
	/*T tmp = a;
	a = b;
	b = tmp;*/

	T temp{ std::move(a) };
	a = std::move(b);
	b = std::move(temp);
	
}

int main15_4()
{
	// Test1
	//{
	//	AutoPtr<Resource> res1(new Resource(100000));

	//	cout << res1.m_ptr << endl;

	//	// 아래와 같이 하면은 Lvalue를 넘겨 주기 때문에
	//	// Copy가 된다.(deep)
	//	//AutoPtr<Resource> res2 = res1;

	//	// std::move함수를 이용해 Lvalue를 Rvalue로 만들어준다.
	//	// assignment로 한다.
	//	AutoPtr<Resource> res2 = std::move(res1);

	//	cout << res1.m_ptr << endl;
	//	cout << res2.m_ptr << endl;
	//}

	// Test2
	/*{
		AutoPtr<Resource> res1(new Resource(3));
		res1->setAll(3);

		AutoPtr<Resource> res2(new Resource(5));
		res2->setAll(5);

		res1->print();
		res2->print();

		MySwap(res1, res2);

		res1->print();
		res2->print();
	}*/

	// Test3
	//{
	//	vector<string> v;
	//	string str = "Hello";

	//	v.push_back(str);

	//	cout << str << endl;		// Hello
	//	cout << v[0] << endl;		// Hello

	//	v.push_back(std::move(str));

	//	// 아무것도 안나옴(move해버려서 str안에 내용물이 없어짐)
	//	cout << str << endl;		
	//	cout << v[0] << " " << v[1] << endl;	// Hello Hello
	//}

	//Test4
	{
		std::string x{ "abc" };
		std::string y{ "de" };

		std::cout << "x : " << x << std::endl;
		std::cout << "y : " << y << std::endl;

		MySwap(x, y);

		std::cout << "x : " << x << std::endl;
		std::cout << "y : " << y << std::endl;
	}


	return 0;
}