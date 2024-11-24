#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//std::vector에서 요소를 조건에 따라 삭제하면서 iterator 갱신하는 다양한 예제

// 1.조건부 삭제
void conditionRemove()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	for (auto it = v.begin(); it != v.end();)
	{
		// 짝수인 요소 삭제
		if (*it % 2 == 0)
			it = v.erase(it);  // 삭제 후 유효한 iterator 반환
		else
			++it;				// 다음 요소로 이동
	}

	for (auto& e : v)
		cout << e << " ";
	cout << endl;
}

// 2. 구간 삭제
void rangeRemove()
{
	std::vector<int> v = { 10, 20,30,40,50,60 };

	// 세 번째 요소부터 끝까지 삭제
	auto it = v.erase(v.begin() + 2, v.end());

	//결과 출력 : 10 20
	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	// 요소 끝까지 삭제 했기 때문에 v.end()를 가르킴
	if (it == v.end())
	{
		cout << "All elements after the range have been removed." << endl;
	}
}

// 3. iterator 갱신 없이 모든 짝수 삭제
void removeIf()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	// 짝수인 요소를 제거
	v.erase(std::remove_if(v.begin(), v.end(), [](int x) {return x % 2 == 0; }), v.end());

	// 결과 출력 : 1 3 5
	for (int x : v)
		std::cout << x << " ";
}

int main()
{
	conditionRemove();

	rangeRemove();

	removeIf();

	return 0;
}