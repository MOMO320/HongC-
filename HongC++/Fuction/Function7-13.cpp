#include <iostream>
#include <string>
using namespace std;

// ����� ���α׷����� ����
int main7_13()
{
	// syntax error
	//int x  -> �����ݷ� ���� ����

	// semantic errors(�� ����) - ���α׷� �ۼ��ڸ� �� �� �ִ� ����
	int x = 0;
	//cin >> x;

	if (x > 5)//(x >= 5) // --> �� ����( > ) �ؾ� �´�.
		cout << " x is greater than 5" << endl;

	// violated assumption(������ �����ߴ�.) : ����ڰ� ���� �ٸ� ������� ����Ѵ�.
	string hello = "Hello, my name is Jack jack";

	// ���� ���� �� ���� ū ������ �ε����� �ҷ����� out of range ����
	cout << "Input from 0 to " << hello.size() - 1 << endl;

	while (true)
	{
		int ix;
		cin >> ix;

		// ������ �ڵ�
		if (ix >= 0 && ix <= hello.size() - 1)
		{
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}
	
	// �� �ڵ�(ix�� 0������ ��츦 üũ �������� �Ѥ�)
	//if (hello.size()-1 < ix) cout << "size over!" << endl;
	//else cout << hello[ix] << endl;	


	return 0;
}