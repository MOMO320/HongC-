#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;
// std::thread 와 멀티 쓰레딩의 기초(multithreading)

// Process : 프로그램을 실행 시킬때 관리하는 단위
// Thread  : 

int mainTest1()
{
	// thread 개수 확인하는 함수 : thread::hardware_concurrency
	//cout << std::thread::hardware_concurrency() << endl;
	
	//main 함수가 실행 되고 있는 thread의 넘버를 알 수 있는 함수
	//cout << std::this_thread::get_id() << endl;

	const int num_pro = std::thread::hardware_concurrency();

	cout << std::this_thread::get_id() << endl;


	// thread에 실행 시킬 함수를 지정해 준다.
	// 에러 발생! : 이유는 새로운 thread에 일을 시켜 놨는데 main 함수가 종료 되어 버리는 바람에
	// 문제가 발생 합니다.
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


	// thread가 합쳐진다.(t1이 끝날때까지 기다려준다.)
	// 그럼 위와 같이 main thread가 종료되어 에러가 발생하는 문제가 사라진다.
	//t1.join();
	//t2.join();
	//t3.join();
	//t4.join();

	return 0;
}

//멀티 쓰레드 사용시 출력이 깨지는 문제 해결 방법

mutex mtx; //mutual exclusion(나만 쓸 수 있어)

int main()
{
	auto work_func = [](const string& name)
		{
			for (int i = 0; i < 5; ++i)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));

				// mutex.lock을 하면은 unlock을 만나기 전까지 다른 쓰레드가 실행을 할 수 없다.
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