#include <memory>
#include <iostream>

int main()
{
	// 배열을 관리하는 unique_ptr 생성
	std::unique_ptr<int[]> uptr(new int[5] {1, 2, 3, 4, 5});
	std::cout << "uptr1 print() : ";
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Element " << i << ": " << uptr[i];
	}std::cout << std::endl;

	// 소유권을 해제하고 원시 포인터 반환
	int* raw_ptr = uptr.release();

	if (!uptr)
	{
		std::cout << "uptr은 더 이상 배열을 소유하지 않음." << std::endl;
	}

	std::unique_ptr<int[]> uptr2(raw_ptr);
	
	std::cout << "uptr2 print() : ";

	std::cout << *(uptr2.get())+1 << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << uptr2[i] << ", ";
	}std::cout << std::endl;

	uptr2.reset(new int[3] {10, 20, 30});

	for (int i = 0; i < 3; ++i)
	{
		std::cout << uptr2[i]<< ", ";
	}std::cout << std::endl;
	return 0;
}