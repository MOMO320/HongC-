#include <iostream>

using namespace std;

// 6-13.포인터와 const
/*
	int value = 5;
	const int *ptr1 = &value;
	int *const ptr2 = &value;
	const int *const ptr3 = &value;
	
	
	*/


int main()
{

/// case 1
	const int value = 5;
	const int* ptr = &value;
	
	// const 키워드를 사용하면 de-reference 할 수 없다.
	//*ptr = 6;  // value = 6;
	cout << *ptr << endl;

/// case 2
	int value2 = 10;
	const int* ptr2 = &value; // 여기서 'const'의 의미는 ptr2 주소에 있는 값을 변경하지 않는다는 뜻
	//*ptr2 = 20;	// error! 발생 , 그렇기 때문에 ptr2에 있는 값을 변경하는것이 허용되지 않는다.
	value2 = 30;	// 하지만 직접적으로 value2의 값을 바꾸는건 허용이 된다.

/// case 3
	int value3 = 5;
	const int* ptr3 = &value3;	// 주소안에 있는 값을 변경하지 않는다는 의미의 'const'

	int value4 = 6;
	ptr3 = &value4;				// 그렇기 때문에 ptr3가 저장하는 주소값을 변경하는것은 가능합니다.

/// case 4
	int value5 = 5;
	int* const ptr4 = &value5;	// 여기서 'const'는 pointer의 주소 자체를 상수값으로 지정하게 함.

	*ptr4 = 10;					// 그렇기 때문에 주소에 있는 값은 변경이 가능하지만
	cout << *ptr << endl;

	int value6 = 12;
//	ptr4 = value6;				// error! , 주소 자체를 변경하는것은 불가 하다.
	
/// case 5
	int value6 = 60;

	// 여기서 'const'는 'pointer'의 주소와 주소안에 있는 값 둘다 상수로 하여 변경이 불가함
	const int* const ptr6 = &value6;	

	//*ptr6 = 10;		// error! 주소안에 있는 값은 상수 이므로 변경이 불가함

	int value7 = 70;
	//ptr6 = &value7;   // error! pointer의 주소가 상수 이므로 변경이 불가함

	return 0;
}