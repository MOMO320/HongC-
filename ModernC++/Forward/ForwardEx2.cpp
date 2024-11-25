#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

class CustomVector
{
public:
	unsigned n_data = 0;
	int* ptr = nullptr;

	CustomVector(const unsigned& _n_data, const int& _init = 0)
	{
		cout << "Constructor" << endl;
		init(_n_data, _init);
	}

	CustomVector(CustomVector& l_input)
	{
		cout << "Copy Constructor" << endl;
		init(l_input.n_data);

		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}

	CustomVector(CustomVector&& r_input)
	{
		cout << "Move Constructor" << endl;
	
		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	~CustomVector()
	{
		delete[] ptr;
	}

	void init(const unsigned& _n_data, const int& _init = 0)
	{
		n_data = _n_data;
		ptr = new int[n_data];
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};

void doSomething(CustomVector& vec)
{
	cout << "pass by L-reference" << endl;
	CustomVector new_vec(vec);
}

void doSomething(CustomVector&& vec)
{
	cout << "pass by R-reference" << endl;
	CustomVector new_vec(std::move(vec));
}

template<typename T>
void doSomethingTemplate(T&& vec)
{
	doSomething(vec);
}

template<typename T>
void doSomethingTemplateForward(T&& vec)
{
	doSomething(std::forward<T>(vec));
}

int main()
{

	CustomVector my_vec(10, 1024);
	// std::move : move constructor를 부르겠다라는 의미가 강함
	//CustomVector temp(std::move(my_vec));

	// move constructor가 호출되면 my_vec에 내용이 없어진다.
	cout << my_vec.n_data << endl;
	cout << " --------------------------------------" << endl;
	//doSomething(my_vec);
	//doSomething(CustomVector(10, 8));

	doSomethingTemplate(my_vec);
	doSomethingTemplate(CustomVector(10,8));
	cout << " --------------------------------------" << endl;

	doSomethingTemplateForward(my_vec);
	doSomethingTemplateForward(CustomVector(10, 8)); // 정상적으로 move structor가 호출 되고 있음

	return 0;
}