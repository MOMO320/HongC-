#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> array;

	// vector는 블록에 나가면 자동으로 메모리를 해제 해줍니다.
	// 동적 array의 경우 직접 메모리 해제를 해줘야 했지만, vector는 자동으로 해제 해준다.
	std::vector<int> array2 = { 1,2,3,4,5 };

	cout << array2.size() << endl;

	std::vector<int> array3 = { 1,2,3, };
	cout << array3.size() << endl;

	std::vector<int> array4{ 1,2,3, };
	cout << array4.size() << endl;

	// vector는 사이즈를 기억하고 있다.
	vector<int> arr = { 1,2,3,4,5 };

	for (auto& itr : arr)
	{
		cout << itr << " ";
	}
	cout << endl;

	// 아래 두가지의 차이는  array와 같다.
	cout << arr.size() << endl;
	cout << arr[1] << endl;
	cout << arr.at(1) << endl;

	arr.resize(10);

	cout << arr.size() << endl;
}