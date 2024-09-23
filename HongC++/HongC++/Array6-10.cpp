#include <iostream>
using namespace std;

const char* getName()
{
	return "Jackjack";
}

int main()
{
	//char name[] = "Jack Jack";

	/// 일반적으로 char *name = "Jack Jack"; 은 error가 난다.
	/// 왜냐하면 "Jack Jack"은 주소가 아닌 리터럴이기 때문입니다.
	/// 하지만 'const' 키워드를 넣으면 하나의 값을 저장한다.
	/// 그렇기 다른 이름의 변수에 같은 값(리터럴)을 넣으면 한 군데에 저장 된다.
	/// 아래에 'name'과 'name2'의 주소가 같다.
	const char* name = "Jack Jack";
	const char* name2 = "Jack Jack";
	const char* name3 = "jack jack";

	cout << (uintptr_t)name << endl;	// Jack Jack의 값이 name 과 name2가 같아 같은 주소값이 나온다.
	cout << (uintptr_t)name2 << endl;
	cout << (uintptr_t)name3 << endl;

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World!";
	const char* char_name = "Jack Jack";

	cout << "----------------------------------------" << endl;
	
	cout << int_arr << endl;
	cout << "char_arr : " << char_arr << endl;		// cout에서는 문자열을 특별하게 처리한다.
	cout << "char_name : " << char_name << endl;	// 문자열 포인터는 c스타일의 문자를 가르킨다고 생각하고 문자열 array로 생각하고
													// null character를 만날때까지 출력을 한다.
	
	cout << "*char_arr : " << *char_arr << endl;
	cout << "*char_name : " << *char_name << endl;

	char c = 'Q';

	// char형의 주소를 출력하려고 하니깐 컴파일러가 문자열인줄 알고 
	// null character를 만날때까지 문자열을 출력 하려고 한다. 
	cout <<"&c : " << &c << endl;
	cout << "c : " << c << endl;


	return 0;
}