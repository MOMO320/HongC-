#include "header.h"

// Iterators (STL 반복자 소개)

int main()
{
	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	//vector<int>::const_iterator const_itr;
	vector<int>::iterator itr;
	itr = container.begin(); // 

	while (itr != container.end())
	{
		cout << *itr << " ";
		++itr;
	}
	cout << endl;

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	for (auto itr = container.begin(); itr != container.end(); ++itr)
		cout << *itr << " ";
	cout << endl;


	return 0;
}