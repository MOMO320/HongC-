#include<iostream>
#include<future>
#include<thread>
#include <chrono>
using namespace std;

// �۾�(Task)��� �񵿱� ���α׷���
// async, future, promise


// ��Ƽ ������ ����
// 1~100���� ���ϴµ� 1~50 thread1���� 51~100�� thread2���� ���� �ϰ� ó��
void testThread()
{

	mutex mtx;

	int result_value = 0;

	thread t1([&]() { 
		for (int i = 1; i <= 50; ++i)
		{
			mtx.lock();
			result_value += i;
			cout << "thread1 value : " << result_value << endl;
			mtx.unlock();
		}
	});
	thread t2([&](){

		for (int i = 51; i <= 100; ++i)
		{
			mtx.lock();
			result_value += i;
			cout << "thread2 value : " << result_value << endl;
			mtx.unlock();
		}
	});

	t1.join();
	t2.join();

	cout << "result_value : " << result_value << endl;
}

int mainTask()
{
	// multi-threading
	// ��Ƽ �������� �Ҷ��� �������� �а� �����
	// �� �ȿ� �ִ� �������� ���� ��������� �����ϸ� ��Ƽ �������� �ϴ°��� 
	// �⺻ �Դϴ�.
	{
		int result;
		std::thread t([&](void) {result = 1 + 2; });
		t.join(); // thread�� ���� ���������� ��ٸ��ϴ�.

		cout << result << endl;
	}

	// task-based parallelism(thread parallelism���� task�� ��ȣ�Ѵ�.)
	{
		// std::future<int> fut = ...
		// ���� return ���� ���� �𸨴ϴ�.
		auto fut = std::async([] {return 1 + 2; }); //async = �񵿱����̴�.
		cout << fut.get() << endl; // return ���� �ö����� ��ٸ��ϴ�.( future.get())
	}

	// future and promise
	{
		std::promise<int> prom;
		std::promise<int> aProm;
		auto fut = prom.get_future();
		auto afut = aProm.get_future();

		// promise<int>&& rvalue�� �־�����Ѵ�.
		auto t = std::thread([](std::promise<int>&& prom)
			{
				prom.set_value(1 + 2);  // ���� �־��ش�.
			}, std::move(prom));

		auto a = std::async([](std::promise<int>&& prom)
			{
				prom.set_value(4 + 2);
			}, std::move(aProm));

		// ���� �ٶ����� ��ٸ���.
		cout << fut.get() << endl;
		cout << afut.get() << endl;
		t.join(); // thread�̱� ������ join�Լ��� ȣ���� ��� �Ѵ�.
	}

	//testThread();

	return 0;
}


