#include <iostream>
#include "Resource.h"

// std::shared_ptr
// 특징 : 자기가 가르키고 있는 포인터가 몇 군데에서 공유하고 있는지
// 카운팅 하고 있음

void soSomething(std::unique_ptr<Resource> res)
{

}


int main15_6()
{
	// 아래와 같이 함수 호출 할때 안에서 new 키워드로 객체 생성하면
	// 생성자 호출 순서 같은 것들이 문제가 발생하여 좋지 않다.(컴파일 마다 다른 상황
	// 이 발생할 수 있음)
	//soSomething(std::unique_ptr<Resource>(new Resource(1000000)));
	//Resource* res = new Resource(3);
	//res->setAll(1);
	
	// std::make_unique 처럼 make_(스마트포인터)로 만드는게 좋다.
	soSomething(std::make_unique<Resource>(100000));
	
	{
		//std::shared_ptr<Resource> ptr1(res);
		auto ptr1 = std::make_shared<Resource>(3);
		ptr1->setAll(1);
		ptr1->print();

		{
			// 문제 없이 잘 작동함
			//std::shared_ptr<Resource> ptr2(ptr1);

			// 아래와 같이 res를 넣으면 문제를 일으킨다.
			//std::shared_ptr<Resource> ptr2(res);
			auto ptr2 = ptr1;

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out of the block" << std::endl;
		}

		ptr1->print();

		std::cout << "Going out of the outer block" << std::endl;
	} // 이 단락이 끝나면서 참조하고 있는 카운터가 없어지니깐 메모리 해제를 한다.
	
	std::getchar();

	return 0;
}