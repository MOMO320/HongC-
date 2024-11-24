#include<iostream>
#include <memory>

int mainReleaseReset()
{
	auto uptr = std::make_unique<int>(40);

	// 포인터의 소유권을 해제하고 raw 포인터를 반환
	int* raw_ptr = uptr.release(); 

	// release 후에는 unique_ptr이 더이상 소유하지 않음
	if (!uptr)
	{
		std::cout << "uptr은 더 이상 소유하지 않음." << std::endl;
	}

	delete raw_ptr;	// 직접 메모리 해제

	uptr.reset(new int(50));	//새 포인터로 리셋
	std::cout << "New value : " << *uptr << std::endl;

	return 0;
}