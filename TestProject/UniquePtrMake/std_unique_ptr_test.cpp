#include <memory>
#include <iostream>

int mainPtrTest()
{
	std::unique_ptr<int> uptr(new int(10));	// int 포인터를 관리하는 unique_ptr
	std::cout << "Value : " << *uptr << std::endl;
	
	std::unique_ptr<int> uptr2(std::move(uptr));

	if (uptr == nullptr)
	{
		std::cout << "uptr nullptr" << std::endl;
	}
	else
	{
		std::cout << "uptr Value : " << *uptr << std::endl;
	}
	std::cout << "uptr2 value : " << *uptr2 << std::endl;

	return 0;
}