#include<iostream>
#include<future>
#include<thread>
#include <chrono>
using namespace std;

// 작업(Task)기반 비동기 프로그래밍
// async, future, promise


// 멀티 쓰레딩 연습
// 1~100까지 더하는데 1~50 thread1에서 51~100은 thread2에서 진행 하게 처리
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
	// 멀티 쓰레딩을 할때는 스코프를 넓게 잡고서는
	// 그 안에 있는 변수들을 여러 쓰레드들이 공유하며 멀티 쓰레딩을 하는것이 
	// 기본 입니다.
	{
		int result;
		std::thread t([&](void) {result = 1 + 2; });
		t.join(); // thread가 일을 끝날때까지 기다립니다.

		cout << result << endl;
	}

	// task-based parallelism(thread parallelism보다 task를 선호한다.)
	{
		// std::future<int> fut = ...
		// 언제 return 값이 올지 모릅니다.
		auto fut = std::async([] {return 1 + 2; }); //async = 비동기적이다.
		cout << fut.get() << endl; // return 값이 올때까지 기다립니다.( future.get())
	}

	// future and promise
	{
		std::promise<int> prom;
		std::promise<int> aProm;
		auto fut = prom.get_future();
		auto afut = aProm.get_future();

		// promise<int>&& rvalue로 넣어줘야한다.
		auto t = std::thread([](std::promise<int>&& prom)
			{
				prom.set_value(1 + 2);  // 값을 넣어준다.
			}, std::move(prom));

		auto a = std::async([](std::promise<int>&& prom)
			{
				prom.set_value(4 + 2);
			}, std::move(aProm));

		// 값을 줄때까지 기다린다.
		cout << fut.get() << endl;
		cout << afut.get() << endl;
		t.join(); // thread이기 때문에 join함수를 호출해 줘야 한다.
	}

	//testThread();

	return 0;
}


