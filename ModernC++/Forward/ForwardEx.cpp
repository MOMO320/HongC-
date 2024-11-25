#include<iostream>
#include <vector>
#include <utility> // std::forward
using namespace std;
// 완벽한 전달과 std::forward(perfect Forwarding)

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
	// template 타이즈 되면서 Lvalue 인지 Rvalue인지 
	// 구분을 하지 못하게 된다.
	func(t);
}

template<typename T>
void func_wrapperR(T&& t) // perfect-forward 
{
	// std::forward가 하는일
	// : t가 들어올때 Lvalue인지 Rvalue인지 판단해 주는 역할을 한다.
	func(std::forward<T>(t));
}

int mainEx1()
{
	MyStruct s;

	func_wrapper(s);			//L-ref 출력
	func_wrapper(MyStruct());	//L-ref 출력

	cout << "--------- func_wrapperR --------" << endl;

	func_wrapperR(s);			// L-ref 출력
	func_wrapperR(MyStruct());	// R-ref 출력
	//func(s);
	//func(MyStruct());	// 익명 객체는 Rvalue로 간주된다.


	return 0;
}