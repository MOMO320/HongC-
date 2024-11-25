#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

// 분할 하여 sorting 처리

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

	//random으로 숫자 뿌려줌
	random_device seed;
	mt19937 engine(seed());

	uniform_int_distribution<> uniformDist(1, dataSize);

	for (int i = 0; i < dataSize; ++i)
	{
		datas.push_back(uniformDist(engine));
	}

	datas2 = datas;

	//thread로 하는 방법
	{
		const auto sta = chrono::steady_clock::now();
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		vector<thread> threads;
		threads.resize(threadSize);

		int part = dataSize / 2;
		// 두개의 스레드가 반 나눠서 소팅한다.
		cout << "half sorting" << endl;
		for (int i = 0; i < 2; ++i)
		{
			threads[i] = std::thread(SortingDataThread,std::ref(datas), part * i, (part * i) + part);
		}

		// 3번째 스레드는 나눠서 정렬한걸 전체적으로 정렬한다.
		cout << "all sorting" << endl;
		threads[2] = std::thread(SortingDataThread, std::ref(datas), 0, dataSize);

		for (int i = 0; i < threadSize; ++i)
			threads[i].join();

		cout << "멀티 쓰레드 걸린 시간 : " << dur.count() << endl;
	}
	for (auto& e : datas)
		cout << e << " ";
	cout << endl;

	cout << " -------------------------------------------------------" << endl;
	// 그냥 하나로 sorting 했을때 걸리는 시간
	{
		const auto sta = chrono::steady_clock::now();
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		std::sort(datas2.begin(), datas2.end());

		cout << "단일 정렬 걸린 시간 : " << dur.count() << endl;
	}

	for (auto& e : datas2)
		cout << e << " ";
	cout << endl;

	return 0;
}