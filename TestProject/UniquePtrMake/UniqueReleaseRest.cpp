#include<iostream>
#include <memory>

int mainReleaseReset()
{
	auto uptr = std::make_unique<int>(40);

	// �������� �������� �����ϰ� raw �����͸� ��ȯ
	int* raw_ptr = uptr.release(); 

	// release �Ŀ��� unique_ptr�� ���̻� �������� ����
	if (!uptr)
	{
		std::cout << "uptr�� �� �̻� �������� ����." << std::endl;
	}

	delete raw_ptr;	// ���� �޸� ����

	uptr.reset(new int(50));	//�� �����ͷ� ����
	std::cout << "New value : " << *uptr << std::endl;

	return 0;
}