#include <iostream>
#include <memory>	//std::allocator

int mainAllocatorTest()
{
	// int Ÿ���� ���� allocator ����
	std::allocator<int> allocator;

	// 5���� int�� ���� �޸� �Ҵ�
	int* ptr = allocator.allocate(5);

	// �Ҵ�� �޸𸮿� �� �ʱ�ȭ(construct ���)
	for (int i = 0; i < 5; ++i)
		allocator.construct(ptr + i, i * 10);	// 0, 10, 20, 30, 40���� �ʱ�ȭ

	// �޸𸮿� �ִ� �� ���
	for (int i = 0; i < 5; ++i)
		std::cout << ptr[i] << " ";	// ��� : 0 10 20 30 40
	std::cout << std::endl;

	// ��ü �ı�(destroy ���)
	for (int i = 0; i < 5; ++i)
		allocator.destroy(ptr + i);

	// �޸� ����
	allocator.deallocate(ptr, 5);

	return 0;
}