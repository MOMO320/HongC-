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

// ��� ������ �Ű������� ������ �������� ���� ���� �ʰ� ���� ����� �� �ִ�.
void print_value(const std::unique_ptr<int>& value)
{
	std::cout << *value << std::endl;
}

int mainUniquePtrMove()
{
	auto uptr = std::make_unique<int>(30);

	// unique_ptr�� �������� �ٸ� �Լ��� �̵�
	uptr = processRetur(std::move(uptr));

	// �̵� �� uptr�� �� �̻� �޸𸮸� �������� ����(nullptr ����)
	if (!uptr)
	{
		std::cout << "uptr�� �� �̻� ���� ���� ����." << std::endl;
	}
	else
	{
		std::cout << "uptr�� ������ ��� ���� value : " << *uptr << std::endl;
	}

	//��� ������ ����
	print_value(uptr);

	// �̵� �� uptr�� �� �̻� �޸𸮸� �������� ����(nullptr ����)
	if (!uptr)
	{
		std::cout << "uptr�� �� �̻� ���� ���� ����." << std::endl;
	}
	else
	{
		std::cout << "uptr�� ������ ��� ���� value : " << *uptr << std::endl;
	}
	return 0;
}