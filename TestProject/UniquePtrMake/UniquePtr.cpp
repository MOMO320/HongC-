#include <iostream>
#include <utility>

template<typename T>
class unique_ptr
{
private:
	T* ptr;

public:
	// ������ : ���� �������� �������� ����
	explicit unique_ptr(T* p = nullptr) noexcept : ptr(p)
	{

	}

	// �Ҹ��� : ������ ��ü ����
	~unique_ptr()
	{
		delete ptr;
	}

	// ���� �����ڿ� ���� �Ҵ� �����ڸ� �����Ͽ� ���縦 ����
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

	// �̵� ������ : ������ ����
	unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr)
	{
		other.ptr = nullptr;
	}

	// �̵� �Ҵ� ������ : ������ ����
	unique_ptr& operator=(unique_ptr&& other) noexcept
	{
		if (this != &other)
		{
			delete ptr;
			ptr = other.ptr;
			other.ptr = nullptr;
		}
		return *this;
	}

	// �������� �������� �����ϰ� ��ȯ(�������� �����ϰ� ��ȯ����?)
	T* release() noexcept
	{
		T* oldPtr = ptr;
		ptr = nullptr;
		return oldPtr;
	}

	// �����ϴ� �����͸� �ٸ� ������ ��ü
	void reset(T* p = nullptr) noexcept
	{
		delete ptr;
		ptr = p;
	}

	// ���� ������ ���
	T* get() const noexcept
	{
		return ptr;
	}

	// ������ó�� ������ �� �ֵ��� ������*, ������-> �����ε�
	T& operator*() const
	{
		return *ptr;
	}

	T* operator->() const noexcept
	{
		return ptr;
	}
};

// ��� ����
int mainUniquePtrTest()
{
	unique_ptr<int> uptr(new int(42));
	unique_ptr<int> move_ptr = std::move(uptr);

	if (!uptr.get())
	{
		std::cout << "uptr�� ���̻� �������� ������ ���� ����" << std::endl;
	}

	return 0;
}