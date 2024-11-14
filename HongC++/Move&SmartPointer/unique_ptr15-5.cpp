#include <iostream>
#include "Resource.h"
#include <memory.h>
using namespace std;

// std::unique_ptr
// Ư¡ : unique_ptr�� ���� ���簡 �ȵȴ�.
// �������� �ѱ������� �־�� �ϱ� �����̴�.

auto doSomething()
{
	// copy
	//auto res1 = std::make_unique<Resource>(5);
	//return res1;

	// moveSementics
	return std::make_unique<Resource>(5);
}

auto doSomething2(std::unique_ptr<Resource> res)
{
	res->setAll(100);
	res->print();

	return res;
}

// pointer�� �Ѱܼ� �۾��ϴ°�
void doSomething3(Resource* res)
{
	res->setAll(100);
	res->print();
}

int main15_5_1()
{
	{
		//Resource* res = new Resource(100000);

		// unique_ptr ����
		std::unique_ptr<Resource> res(new Resource(100000000));
	}

	// �ٸ� ����
	{
		std::unique_ptr<int> upi(new int);
		std::unique_ptr<Resource> res1(new Resource(5));
		//std::unique_ptr<Resource> res2 = std::make_unique<Resource>(5);
		//res2 = doSomething();

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		// unique_ptr�� ���簡 �ȵȴ�.(�������� �Ѱ����� ���� �� �ִ�.)
		// �׷��� ������ ���簡 �ȵȴ�.
		//res2 = res1; -> error!!
		
		// std::move semantics�� ��� �����ϴ�.(������ ������ �����ϴϱ�)
		res2 = std::move(res1);

		std::cout << std::boolalpha;	// bool������ ������ �����ϴ°�
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		if (res1 != nullptr) res1->print();
		if (res2 != nullptr) res2->print();
	}


	return 0;
}

// test2
int main15_5_2()
{
	auto res1 = std::make_unique<Resource>(5);

	res1->setAll(1);
	res1->print();

	std::cout << std::boolalpha;
	std::cout << static_cast<bool>(res1) << std::endl;

	// copy�� �ź��Ѵ�. = unique_ptr(������ ������ �ȵȴ�.)
	//doSomething2(std::move(res1));

	// �Լ� ȣ�� �� �ٽ� ����ϰ� ������(std::move ��� ��)
	// �ٽ� �������� �Ѱ��ش�.
	//res1 = doSomething2(std::move(res1));
	doSomething3(res1.get());	//unique_ptr�� pointer�� �Ѱ��ش�.


	std::cout << std::boolalpha;
	std::cout << static_cast<bool>(res1) << std::endl;
	res1->print();

	//res1->print();

	return 0;
}

// unique_ptr �ϸ� �ȵǴ� ���� �׽�Ʈ
int main15_5_3()
{
	Resource* res = new Resource;

	// �������� �� ������ ����� ��Ȳ
	std::unique_ptr<Resource> res1(res);	
	std::unique_ptr<Resource> res2(res);

	// unique_ptr�� �����ϰ� �ִµ� ���� delete �ع����� 
	// �Ҹ��� ȣ�� �Ҷ� �޸� ���� �߻�
	delete res;
	return 0;
}