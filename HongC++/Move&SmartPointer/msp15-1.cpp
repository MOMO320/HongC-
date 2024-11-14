#include <iostream>
#include "AutoPtr.h"
#include "Resource.h"
using namespace std;

// Move semantics
// '이동'의 의미와 스마트 포인터 소개(SmartPointer)

// RAII : new키워드로 메모리 할당한 곳에 delete 키워드를 사용해야한다.(메모리 해제)
// RAII : resource acquisition is initialization


// autoPointer의 한계점 
// : 다른곳에 참조되어 있을때 함수가 종료 되면서 소멸자로 인해 객체 소멸되어 다른곳에선
// 사용을 할 수 없는 문제가 있다.



void doSomething()
{
	try
	{
		// 수동으로 메모리 할당 및 해제 해주는걸 멍청한 포인터(dullPointer)라고 부릅니다.
		Resource* resA = new Resource;
		AutoPtr<Resource> res = new Resource;	// smart pointer

		return;
		// work with res
		if (true)
		{
			throw - 1; // exception
		}

		//delete res;
	}
	catch (...)
	{

	}

	return;
}

int main15_1()
{
	//doSomething();

	{
		AutoPtr<Resource> res1(new Resource); // int i; int *ptr1(&i); int *ptr2 = nullptr; 
		AutoPtr<Resource> res2;

		cout << std::boolalpha;
		
		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
		
		// 대입연산으로 인해 얕은 복사가 이뤄진다.
		// 얕은 복사로 인해 소멸자가 두번 불러와 주면서 문제가 발생한다.
		//res2 = res1;	

		//res2 = res1; // 소유권을 이전하는것을 = move semantics

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}

	// syntax vs. semantics
	// syntax = 문법 검사(컴파일 되는거냐 안되는거냐의 문제)
	// semantics = 컴파일 되는거는 다 똑같은데 실제로 내부적인 의미가 뭔지 확인
	int x = 1, y = 1;
	x + y;

	std::string str1("Hello"), str2("World");
	str1 + str2;	// append

	// value semantics (copy semantics)
	// reference semantics (pointer)
	// move semantics (move)

	return 0;
}