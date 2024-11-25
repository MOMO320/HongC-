#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

// ���� �Ͽ� sorting ó��

mutex mtx2;

void SortingDataThread(vector<int>& data, const int& start_num, const int& end_num)
{
	std::scoped_lock lock(mtx2);
	std::sort(data.begin()+start_num, data.begin()+end_num);
}

int mainTodoTest()
{
	const int threadSize = 3;
	const int dataSize = 1000;
	vector<int> datas;
	vector<int> datas2;
	datas.reserve(dataSize);

	//random���� ���� �ѷ���
	random_device seed;
	mt19937 engine(seed());

	uniform_int_distribution<> uniformDist(1, dataSize);

	for (int i = 0; i < dataSize; ++i)
	{
		datas.push_back(uniformDist(engine));
	}

	datas2 = datas;

	//thread�� �ϴ� ���
	{
		const auto sta = chrono::steady_clock::now();
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		vector<thread> threads;
		threads.resize(threadSize);

		int part = dataSize / 2;
		// �ΰ��� �����尡 �� ������ �����Ѵ�.
		cout << "half sorting" << endl;
		for (int i = 0; i < 2; ++i)
		{
			threads[i] = std::thread(SortingDataThread,std::ref(datas), part * i, (part * i) + part);
		}

		// 3��° ������� ������ �����Ѱ� ��ü������ �����Ѵ�.
		cout << "all sorting" << endl;
		threads[2] = std::thread(SortingDataThread, std::ref(datas), 0, dataSize);

		for (int i = 0; i < threadSize; ++i)
			threads[i].join();

		cout << "��Ƽ ������ �ɸ� �ð� : " << dur.count() << endl;
	}
	for (auto& e : datas)
		cout << e << " ";
	cout << endl;

	cout << " -------------------------------------------------------" << endl;
	// �׳� �ϳ��� sorting ������ �ɸ��� �ð�
	{
		const auto sta = chrono::steady_clock::now();
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		std::sort(datas2.begin(), datas2.end());

		cout << "���� ���� �ɸ� �ð� : " << dur.count() << endl;
	}

	for (auto& e : datas2)
		cout << e << " ";
	cout << endl;

	return 0;
}