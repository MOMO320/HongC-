#include <iostream>

template<typename T>

class SharedPtr
{
private:
	T* ptr;				// ������ ����Ű�� ��ü
	int* ref_count;		// ���� ī��Ʈ�� �����ϴ� ������

public:
	//������
	explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1))
	{
		std::cout << "SharedPtr created. Ref count : " << *ref_count << std::endl;
	}

	// ���� ������
	SharedPtr(const SharedPtr& other)
		: ptr(other.ptr), ref_count(other.ref_count)
	{
		(*ref_count)++;	// ���� ī��Ʈ�� ������Ŵ
		std::cout << "SharedPtr copied. Ref count: " << *ref_count << std::endl;
	}

	// �Ҹ���
	~SharedPtr()
	{
		release();
	}

	// ���� ������
	SharedPtr& operator=(const SharedPtr& other)
	{
		if (this != other)
		{
			// ������ �ڿ��� ����
			release();

			// ���ο� �ڿ� ����
			ptr = other.ptr;
			ref_count = other.ref_count;
			(*ref_count)++;	// ���� ī��Ʈ ����

			std::cout << "SharedPtr assigned. Ref count : " << *ref_count << std::endl;
		}

		return *this;
	}

	// �ڿ� ���� �Լ�
	void release()
	{
		if (ref_count)
		{
			(*ref_count)--;

			std::cout << "ShaerdPtr release. Ref count : " << *ref_count << std::endl;

			if (*ref_count == 0)
			{
				delete ptr;
				delete ref_count;
				std::cout << "Resource destroyed.\n";
			}
		}
	}

	void reset(T* new_ptr = nullptr)
	{
		// ���� �ڿ� ����
		release();
		ptr = new_ptr;	// ���ο� ������ ����
		if (new_ptr)
		{
			ref_count = new int(1);	//���ο� ���� ī��Ʈ ����
			std::cout << "SharedPtr reset. Ref count : " << *ref_count << std::endl;
		}
		else
		{
			ref_count = nullptr;	// ���� nullptr�̸� ���� ī��Ʈ�� ����
			std::cout << "SharedPtr reset. No resource assigned.\n";
		}
	}

	// �����Ϳ� ������ �� �ִ� ������
	T& operator*() const
	{
		return *ptr;
	}

	T* operator->() const
	{
		return ptr;
	}

	// ���� ���� ī��Ʈ�� ��ȯ�ϴ� �Լ�
	int use_count() const
	{
		return *ref_count;
	}
};

int mainsharedPtrMake()
{
	SharedPtr<int> sp1(new int(10));

	{
		SharedPtr<int> sp2 = sp1;	//���� ī��Ʈ ����
		std::cout << "sp2 use count : " << sp2.use_count() << std::endl;

	} //sp2 �Ҹ�, ���� ī��Ʈ ����

	std::cout << "sp1 use count : " << sp1.use_count() << std::endl;

	sp1.reset(new int(20)); // ���ο� �ڿ����� ��ü
	sp1.reset();

	return 0;
}