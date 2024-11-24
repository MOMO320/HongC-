#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main()
{
	{
		/*
			Async�� future�� ������ �Ǿ� ���� ������
			�񵿱������ �۵����� �ʰ� ���������� �Լ��� ����ȴ�.

			���(future�̶� ������ �ȵǾ� ������)
			async1 start -> async1 end -> async2 start -> async2 end -> Main function
		
			���(future�� ���� �Ǿ� ������)
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