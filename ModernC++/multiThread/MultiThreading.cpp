#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;
// std::thread �� ��Ƽ �������� ����(multithreading)

// Process : ���α׷��� ���� ��ų�� �����ϴ� ����
// Thread  : 

int mainTest1()
{
	// thread ���� Ȯ���ϴ� �Լ� : thread::hardware_concurrency
	//cout << std::thread::hardware_concurrency() << endl;
	
	//main �Լ��� ���� �ǰ� �ִ� thread�� �ѹ��� �� �� �ִ� �Լ�
	//cout << std::this_thread::get_id() << endl;

	const int num_pro = std::thread::hardware_concurrency();

	cout << std::this_thread::get_id() << endl;


	// thread�� ���� ��ų �Լ��� ������ �ش�.
	// ���� �߻�! : ������ ���ο� thread�� ���� ���� ���µ� main �Լ��� ���� �Ǿ� ������ �ٶ���
	// ������ �߻� �մϴ�.
	/*std::thread t1 = std::thread([]() {
		
		cout << std::this_thread::get_id() << endl;

		while (true)
		{

		}
		
	});

	std::thread t2 = std::thread([]() {

		cout << std::this_thread::get_id() << endl;
		while (true)
		{

		}
	});

	std::thread t3 = std::thread([]() {

		cout << std::this_thread::get_id() << endl;
		while (true)
		{

		}
	});

	std::thread t4 = std::thread([]() {

		cout << std::this_thread::get_id() << endl;
		while (true)
		{

		}
	});*/

	vector<std::thread> my_threads;
	my_threads.resize(num_pro);

	for (auto& e : my_threads)
	{
		e = std::thread([]()
			{
				cout << std::this_thread::get_id() << endl;
				while (true);
			});
	}


	for (auto& e : my_threads)
	{
		e.join();
	}


	// thread�� ��������.(t1�� ���������� ��ٷ��ش�.)
	// �׷� ���� ���� main thread�� ����Ǿ� ������ �߻��ϴ� ������ �������.
	//t1.join();
	//t2.join();
	//t3.join();
	//t4.join();

	return 0;
}

//��Ƽ ������ ���� ����� ������ ���� �ذ� ���

mutex mtx; //mutual exclusion(���� �� �� �־�)

int main()
{
	auto work_func = [](const string& name)
		{
			for (int i = 0; i < 5; ++i)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));

				// mutex.lock�� �ϸ��� unlock�� ������ ������ �ٸ� �����尡 ������ �� �� ����.
				mtx.lock(); 
				cout << name << " " << std::this_thread::get_id() << "is working " << i << " " << endl;
				//mtx.unlock();
			}
	};

	//single thread
	work_func("JackJack");
	work_func("Dash");

	// multithread
	std::thread t1 = std::thread(work_func, "Jack Jack");
	std::thread t2 = std::thread(work_func, "MOMO");

	t1.join();
	t2.join();

	return 0;
}