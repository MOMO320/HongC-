#include <iostream>

using namespace std;

// 인라인 함수
// 인라인 함수는 헤더에 함수 선언뿐 아니라 정의까지 하는 함수를 말한다.
// 인라인 함수는 컴파일러가 알아서 변경 한다.
// 그렇기 때문에 많이 사용하면 컴파일러가 코드를 변경 하기 때문에 프로그램이 커진다.

// inline 키워드를 쓰면 아래와 같이 작성하는걸
//  강제성은 아니고 권장을 한다.
inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main7_6()
{
	cout << min(5, 6) << endl;
	// inline 함수를 사용하여 위의 코드가 아래와 같이 실행된다.
	cout << (5 > 6 ? 6 : 5) << endl;

	cout << min(3, 2) << endl;
	// inline 함수를 사용하여 위의 코드가 아래와 같이 실행된다.
	cout << (3 > 2 ? 2 : 3) << endl;

	return 0;
}