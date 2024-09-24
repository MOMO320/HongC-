#include <iostream>

using namespace std;

// 6-11. 메모리 동적 할당 new 와 delete

int main6_11()
{
	// <- error!발생 메모리 공간이 부족해서 , stack은 메모리 공간이 부족하다.
	//int array[1000000000];	

	
	//int var;					// stack 영역에 변수 선언	
	int *ptr = new int;			// heap 영역에 변수 선언(힙영역에 메모리 할당)
	int* ptr_ = new (std::nothrow)int{ 7 };	// 이렇게 초기화 가능

	// std::nothrow -> new 키워드로 메모리 할당이 되지 않는다면 
	// nullptr로 대입해 에러를 발생시켜주지 않게 하는 예외 방법

	*ptr = 7;

	if (ptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}
	else 
	{
		cout << "Could not allocate memory" << endl; 
	}
	

	delete ptr;					// heap영역에 할당된 메모리를 돌려주는 키워드 -> delete
	ptr = nullptr;
							
	cout << "After delete" << endl;
	if (ptr != nullptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}

	int* ptr2 = ptr;
	
	delete ptr;
	ptr = nullptr;
	ptr2 = nullptr;


	return 0;
}
 

int main6_11_2()
{
	// memory leak(메모리 누수) : 할당 후 메모리를 해제해 주지 않으면 발생
	while (true)
	{
		int* ptr = new int;
		delete ptr;			// delete를 하지 않으면 memeory 사용량이 계속 늘어남
	}

	return 0;
}