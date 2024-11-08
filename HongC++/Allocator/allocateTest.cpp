#include <iostream>
#include <memory>	//std::allocator

int mainAllocatorTest()
{
	// int 타입을 위한 allocator 생성
	std::allocator<int> allocator;

	// 5개의 int를 위한 메모리 할당
	int* ptr = allocator.allocate(5);

	// 할당된 메모리에 값 초기화(construct 사용)
	for (int i = 0; i < 5; ++i)
		allocator.construct(ptr + i, i * 10);	// 0, 10, 20, 30, 40으로 초기화

	// 메모리에 있는 값 출력
	for (int i = 0; i < 5; ++i)
		std::cout << ptr[i] << " ";	// 출력 : 0 10 20 30 40
	std::cout << std::endl;

	// 객체 파괴(destroy 사용)
	for (int i = 0; i < 5; ++i)
		allocator.destroy(ptr + i);

	// 메모리 해제
	allocator.deallocate(ptr, 5);

	return 0;
}