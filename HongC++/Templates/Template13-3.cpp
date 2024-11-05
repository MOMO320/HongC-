// 자료형이 아닌 템플릿 매개변수
#include "MyArray.h"

int main13_3()

	// std::vector<double> my_array; my_array.resize(100);
	// MyArray<double> my_array(100);
{
	// 템플릿은 컴파일 타임에 값을 알려줘야 한다.
	// non-type parameter 자료형이 아닌 타입-> 리터럴(상수)
	// 변수는 안됨 ex) int i = 10; MyArray<double, i> my_array; -> error!!!
	MyArray<char, 10> my_array;

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();

	return 0;
}