#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;
//  ���̽� �����(Race Condition)
// std::atomic, std::scoped_lock

// ��Ƽ �������� �������� ������ ���� �ϳ��� �޸� ������ �Բ� ���
// �� �� �ְ� ���ֱ� ������ �ٸ� ���� ó�� ����鿡 ���ؼ� �ξ� �����ϱ� ���մϴ�.
// ������ ���� �޸� ������ ���� �� �� �ִٴ� ������ ��� ���ִ� ���� �޸� ������ 
// ����ϱ� ������ ������ ����� �������� �� �� �ֽ��ϴ�.
// �װ��� ���̽� ������̶�� �մϴ�.

// ���̽� ������� �ذ��ϴ� ����� ã�� ���ô�.


int main()
{
	// atomic�� ������� �ʴ� ���, lock�� �������
	mutex mtx;
	
	//int shared_memory(0);
	// atomic<�ڷ���>
	atomic<int> shared_memory(0);

	int shared_memory2 = 0;

	auto count_func = [&]()
	{
			for (int i = 0; i < 1000; ++i)
			{
				//sleep_for�� ���� ������ �����带 ���� ������ ������ ���� �ݹ� ����������
				// ������ ��Ȳ�� ���� ��Ʊ� �����̴�.
				this_thread::sleep_for(chrono::milliseconds(1));

				// atomic add�� �Ϲ� �������� ���� ������ ���� ���̴�.
				// �׷��� ������ �������⿡ ����ϸ� �ȵȴ�.
				shared_memory++;  // ���⼭ ++�� operator�� �����ڰ� �ƴϰ� atomic ++�� ������ �̴�.
				//shared_memory.fetch_add(1); // ++�� ���� ������ �Ѵ�.(fetch_add())

				// unlock�� ���� ������ ������ �߻��Ѵ�.
				// �����ϰ� unlock�� ���ֱ� ���� lock_guard�� �̿��Ѵ�.
				// lock_guard�� unlock�� ���� �ʾƵ� �Լ� ȣ������ ���� �Ǹ� �ڵ����� unlock�� ���ݴϴ�.
				//std::lock_guard lock(mtx); // C++ 17�̻� ����
				std::scoped_lock lock(mtx);	// scoped_lock�� �� �����Ѵ�.
				
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