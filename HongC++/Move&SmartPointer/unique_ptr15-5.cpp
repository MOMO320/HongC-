#include <iostream>
#include "Resource.h"
#include <memory.h>
using namespace std;

// std::unique_ptr
// 특징 : unique_ptr은 대입 복사가 안된다.
// 소유권이 한군데에만 있어야 하기 때문이다.

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

// pointer만 넘겨서 작업하는거
void doSomething3(Resource* res)
{
	res->setAll(100);
	res->print();
}

int main15_5_1()
{
	{
		//Resource* res = new Resource(100000);

		// unique_ptr 사용법
		std::unique_ptr<Resource> res(new Resource(100000000));
	}

	// 다른 예제
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

		// unique_ptr은 복사가 안된다.(소유권이 한곳에만 있을 수 있다.)
		// 그렇기 때문에 복사가 안된다.
		//res2 = res1; -> error!!
		
		// std::move semantics만 사용 가능하다.(소유권 이전이 가능하니깐)
		res2 = std::move(res1);

		std::cout << std::boolalpha;	// bool값으로 나오게 설정하는것
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

	// copy를 거부한다. = unique_ptr(값으로 넣으면 안된다.)
	//doSomething2(std::move(res1));

	// 함수 호출 후 다시 사용하고 싶으면(std::move 사용 후)
	// 다시 소유권을 넘겨준다.
	//res1 = doSomething2(std::move(res1));
	doSomething3(res1.get());	//unique_ptr의 pointer만 넘겨준다.


	std::cout << std::boolalpha;
	std::cout << static_cast<bool>(res1) << std::endl;
	res1->print();

	//res1->print();

	return 0;
}

// unique_ptr 하면 안되는 예시 테스트
int main15_5_3()
{
	Resource* res = new Resource;

	// 소유권을 두 군데에 줘버린 상황
	std::unique_ptr<Resource> res1(res);	
	std::unique_ptr<Resource> res2(res);

	// unique_ptr로 관리하고 있는데 직접 delete 해버리면 
	// 소멸자 호출 할때 메모리 문제 발생
	delete res;
	return 0;
}