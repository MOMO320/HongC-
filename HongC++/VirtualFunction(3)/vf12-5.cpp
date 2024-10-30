#include <iostream>

using namespace std;

// 동적 바인딩과 정적 바인딩
// 동적 바인딩과 정적 바인딩의 차이
// 정적 바인딩이 더 빠르다.
// 동적 바인딩을 사용하면 프로그램이 조금 더 유연해진다.

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int main12_5()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract , 2 : multiply" << endl;
	cin >> op;

	// static binding(earlyu binding)
	{
		int result;
		switch (op)
		{
		case 0: result = add(x, y); break;
		case 1: result = subtract(x, y); break;
		case 2: result = multiply(x, y); break;
		}

		cout << result << endl;
	}

	//Dynamic binding (late binding)
	{
		int(*func_ptr)(int, int) = nullptr;
		switch (op)
		{
		case 0: func_ptr = add; break;
		case 1: func_ptr = subtract; break;
		case 2: func_ptr = multiply; break;
		}

		cout << func_ptr(x, y) << endl;
	}




	return 0;
}