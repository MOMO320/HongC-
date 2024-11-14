#include <iostream>
#include "Resource.h"

// std::shared_ptr
// Ư¡ : �ڱⰡ ����Ű�� �ִ� �����Ͱ� �� �������� �����ϰ� �ִ���
// ī���� �ϰ� ����

void soSomething(std::unique_ptr<Resource> res)
{

}


int main15_6()
{
	// �Ʒ��� ���� �Լ� ȣ�� �Ҷ� �ȿ��� new Ű����� ��ü �����ϸ�
	// ������ ȣ�� ���� ���� �͵��� ������ �߻��Ͽ� ���� �ʴ�.(������ ���� �ٸ� ��Ȳ
	// �� �߻��� �� ����)
	//soSomething(std::unique_ptr<Resource>(new Resource(1000000)));
	//Resource* res = new Resource(3);
	//res->setAll(1);
	
	// std::make_unique ó�� make_(����Ʈ������)�� ����°� ����.
	soSomething(std::make_unique<Resource>(100000));
	
	{
		//std::shared_ptr<Resource> ptr1(res);
		auto ptr1 = std::make_shared<Resource>(3);
		ptr1->setAll(1);
		ptr1->print();

		{
			// ���� ���� �� �۵���
			//std::shared_ptr<Resource> ptr2(ptr1);

			// �Ʒ��� ���� res�� ������ ������ ����Ų��.
			//std::shared_ptr<Resource> ptr2(res);
			auto ptr2 = ptr1;

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out of the block" << std::endl;
		}

		ptr1->print();

		std::cout << "Going out of the outer block" << std::endl;
	} // �� �ܶ��� �����鼭 �����ϰ� �ִ� ī���Ͱ� �������ϱ� �޸� ������ �Ѵ�.
	
	std::getchar();

	return 0;
}