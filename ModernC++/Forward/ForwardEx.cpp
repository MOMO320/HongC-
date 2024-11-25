#include<iostream>
#include <vector>
#include <utility> // std::forward
using namespace std;
// �Ϻ��� ���ް� std::forward(perfect Forwarding)

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}

template<typename T>
void func_wrapper(T t)
{
	// template Ÿ���� �Ǹ鼭 Lvalue ���� Rvalue���� 
	// ������ ���� ���ϰ� �ȴ�.
	func(t);
}

template<typename T>
void func_wrapperR(T&& t) // perfect-forward 
{
	// std::forward�� �ϴ���
	// : t�� ���ö� Lvalue���� Rvalue���� �Ǵ��� �ִ� ������ �Ѵ�.
	func(std::forward<T>(t));
}

int mainEx1()
{
	MyStruct s;

	func_wrapper(s);			//L-ref ���
	func_wrapper(MyStruct());	//L-ref ���

	cout << "--------- func_wrapperR --------" << endl;

	func_wrapperR(s);			// L-ref ���
	func_wrapperR(MyStruct());	// R-ref ���
	//func(s);
	//func(MyStruct());	// �͸� ��ü�� Rvalue�� ���ֵȴ�.


	return 0;
}