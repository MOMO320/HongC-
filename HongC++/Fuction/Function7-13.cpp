#include <iostream>
#include <string>
using namespace std;

// 방어적 프로그래밍의 개념
int main7_13()
{
	// syntax error
	//int x  -> 세미콜론 없는 오류

	// semantic errors(논리 오류) - 프로그램 작성자만 알 수 있는 오류
	int x = 0;
	//cin >> x;

	if (x > 5)//(x >= 5) // --> 논리 오류( > ) 해야 맞다.
		cout << " x is greater than 5" << endl;

	// violated assumption(가정을 위반했다.) : 사용자가 전혀 다른 방식으로 사용한다.
	string hello = "Hello, my name is Jack jack";

	// 기존 글자 수 보다 큰 숫자의 인덱스를 불러오면 out of range 에러
	cout << "Input from 0 to " << hello.size() - 1 << endl;

	while (true)
	{
		int ix;
		cin >> ix;

		// 선생님 코드
		if (ix >= 0 && ix <= hello.size() - 1)
		{
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}
	
	// 내 코드(ix가 0이하일 경우를 체크 안해줬음 ㅡㅡ)
	//if (hello.size()-1 < ix) cout << "size over!" << endl;
	//else cout << hello[ix] << endl;	


	return 0;
}