#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;
//  레이스 컨디션(Race Condition)
// std::atomic, std::scoped_lock

// 멀티 쓰레딩은 여러개의 스레드 들이 하나의 메모리 공간을 함께 사용
// 할 수 있게 해주기 때문에 다른 병렬 처리 기법들에 비해서 훨씬 구현하기 편리합니다.
// 하지만 같은 메모리 공간을 공유 할 수 있다는 장점은 어떠한 경우애는 같은 메모리 공간을 
// 사용하기 때문에 오류가 생기는 문제점이 될 수 있습니다.
// 그것을 레이스 컨디션이라고 합니다.

// 레이스 컨디션을 해결하는 방법을 찾아 봅시다.


int main()
{
	// atomic을 사용하지 않는 방법, lock을 사용해줌
	mutex mtx;
	
	//int shared_memory(0);
	// atomic<자료형>
	atomic<int> shared_memory(0);

	int shared_memory2 = 0;

	auto count_func = [&]()
	{
			for (int i = 0; i < 1000; ++i)
			{
				//sleep_for를 넣은 이유는 스레드를 쉬게 해주지 않으면 일을 금방 끝내버리기
				// 때문에 상황을 보기 어렵기 때문이다.
				this_thread::sleep_for(chrono::milliseconds(1));

				// atomic add는 일반 연산자의 증감 연산자 보다 무겁다.
				// 그렇기 때문에 여기저기에 사용하면 안된다.
				shared_memory++;  // 여기서 ++은 operator의 연산자가 아니고 atomic ++의 연산자 이다.
				//shared_memory.fetch_add(1); // ++와 같은 역할을 한다.(fetch_add())

				// unlock을 하지 않으면 문제가 발생한다.
				// 안전하게 unlock을 해주기 위해 lock_guard를 이용한다.
				// lock_guard는 unlock을 하지 않아도 함수 호출행이 종료 되면 자동으로 unlock을 해줍니다.
				//std::lock_guard lock(mtx); // C++ 17이상 가능
				std::scoped_lock lock(mtx);	// scoped_lock을 더 권장한다.
				
				//mtx.lock();
				shared_memory2++;
				//mtx.unlock();

			}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);
			
	t1.join();
	t2.join();

	cout << "After" << endl;
	cout << "Shared memory1 : " << shared_memory << endl;
	cout << "Shared memory2 : " << shared_memory2 << endl;


	return 0;
}