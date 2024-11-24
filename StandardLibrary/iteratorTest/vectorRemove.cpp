#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//std::vector���� ��Ҹ� ���ǿ� ���� �����ϸ鼭 iterator �����ϴ� �پ��� ����

// 1.���Ǻ� ����
void conditionRemove()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	for (auto it = v.begin(); it != v.end();)
	{
		// ¦���� ��� ����
		if (*it % 2 == 0)
			it = v.erase(it);  // ���� �� ��ȿ�� iterator ��ȯ
		else
			++it;				// ���� ��ҷ� �̵�
	}

	for (auto& e : v)
		cout << e << " ";
	cout << endl;
}

// 2. ���� ����
void rangeRemove()
{
	std::vector<int> v = { 10, 20,30,40,50,60 };

	// �� ��° ��Һ��� ������ ����
	auto it = v.erase(v.begin() + 2, v.end());

	//��� ��� : 10 20
	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	// ��� ������ ���� �߱� ������ v.end()�� ����Ŵ
	if (it == v.end())
	{
		cout << "All elements after the range have been removed." << endl;
	}
}

// 3. iterator ���� ���� ��� ¦�� ����
void removeIf()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	// ¦���� ��Ҹ� ����
	v.erase(std::remove_if(v.begin(), v.end(), [](int x) {return x % 2 == 0; }), v.end());

	// ��� ��� : 1 3 5
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