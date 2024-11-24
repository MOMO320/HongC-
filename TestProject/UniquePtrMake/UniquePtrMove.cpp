#include <memory>
#include <iostream>

void process(std::unique_ptr<int> p)
{
	std::cout << "Processed value : " << *p << std::endl;
}

std::unique_ptr<int> processRetur(std::unique_ptr<int> p)
{
	std::cout << "ProcessReturn vlaue : " << *p << std::endl;

	return p;
}

// 상수 참조로 매개변수를 넣으면 소유권이 이전 되지 않고 값만 사용할 수 있다.
void print_value(const std::unique_ptr<int>& value)
{
	std::cout << *value << std::endl;
}

int mainUniquePtrMove()
{
	auto uptr = std::make_unique<int>(30);

	// unique_ptr의 소유권을 다른 함수로 이동
	uptr = processRetur(std::move(uptr));

	// 이동 후 uptr은 더 이상 메모리를 소유하지 않음(nullptr 상태)
	if (!uptr)
	{
		std::cout << "uptr은 더 이상 소유 하지 않음." << std::endl;
	}
	else
	{
		std::cout << "uptr의 소유권 살아 있음 value : " << *uptr << std::endl;
	}

	//상수 참조로 전달
	print_value(uptr);

	// 이동 후 uptr은 더 이상 메모리를 소유하지 않음(nullptr 상태)
	if (!uptr)
	{
		std::cout << "uptr은 더 이상 소유 하지 않음." << std::endl;
	}
	else
	{
		std::cout << "uptr의 소유권 살아 있음 value : " << *uptr << std::endl;
	}
	return 0;
}