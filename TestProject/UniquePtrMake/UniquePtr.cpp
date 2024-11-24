#include <iostream>
#include <utility>

template<typename T>
class unique_ptr
{
private:
	T* ptr;

public:
	// 생성자 : 원시 포인터의 소유권을 가짐
	explicit unique_ptr(T* p = nullptr) noexcept : ptr(p)
	{

	}

	// 소멸자 : 소유된 객체 해제
	~unique_ptr()
	{
		delete ptr;
	}

	// 복사 생성자와 복사 할당 연산자를 삭제하여 복사를 방지
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

	// 이동 생성자 : 소유권 이전
	unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr)
	{
		other.ptr = nullptr;
	}

	// 이동 할당 연산자 : 소유권 이전
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

	// 포인터의 소유권을 해제하고 반환(소유권을 해제하고 반환하지?)
	T* release() noexcept
	{
		T* oldPtr = ptr;
		ptr = nullptr;
		return oldPtr;
	}

	// 관리하는 포인터를 다른 것으로 교체
	void reset(T* p = nullptr) noexcept
	{
		delete ptr;
		ptr = p;
	}

	// 원시 포인터 얻기
	T* get() const noexcept
	{
		return ptr;
	}

	// 포인터처럼 접근할 수 있도록 연산자*, 연산자-> 오버로드
	T& operator*() const
	{
		return *ptr;
	}

	T* operator->() const noexcept
	{
		return ptr;
	}
};

// 사용 예시
int mainUniquePtrTest()
{
	unique_ptr<int> uptr(new int(42));
	unique_ptr<int> move_ptr = std::move(uptr);

	if (!uptr.get())
	{
		std::cout << "uptr의 더이상 소유권을 가지고 있지 않음" << std::endl;
	}

	return 0;
}