#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main()
{
	{
		/*
			Async가 future랑 연결이 되어 있지 않으면
			비동기식으로 작동하지 않고 순차적으로 함수가 진행된다.

			출력(future이랑 연결이 안되어 있으면)
			async1 start -> async1 end -> async2 start -> async2 end -> Main function
		
			출력(future랑 연결 되어 있으면)
			Main function -> async1 start -> async2 start -> async2 end -> async1 end
		*/
		auto f1 = std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});

		auto f2 = std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		std::cout << "Main function" << endl;

		//f1.join();
		//f2.join();
	}


	return 0;
}