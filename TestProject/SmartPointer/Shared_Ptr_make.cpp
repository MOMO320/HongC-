#include <iostream>

template<typename T>

class SharedPtr
{
private:
	T* ptr;				// 실제로 가리키는 객체
	int* ref_count;		// 참조 카운트를 관리하는 포인터

public:
	//생성자
	explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1))
	{
		std::cout << "SharedPtr created. Ref count : " << *ref_count << std::endl;
	}

	// 복사 생성자
	SharedPtr(const SharedPtr& other)
		: ptr(other.ptr), ref_count(other.ref_count)
	{
		(*ref_count)++;	// 참조 카운트를 증가시킴
		std::cout << "SharedPtr copied. Ref count: " << *ref_count << std::endl;
	}

	// 소멸자
	~SharedPtr()
	{
		release();
	}

	// 대입 연산자
	SharedPtr& operator=(const SharedPtr& other)
	{
		if (this != other)
		{
			// 기존의 자원을 해제
			release();

			// 새로운 자원 공유
			ptr = other.ptr;
			ref_count = other.ref_count;
			(*ref_count)++;	// 참조 카운트 증가

			std::cout << "SharedPtr assigned. Ref count : " << *ref_count << std::endl;
		}

		return *this;
	}

	// 자원 해제 함수
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
		// 현재 자원 해제
		release();
		ptr = new_ptr;	// 새로운 포인터 설정
		if (new_ptr)
		{
			ref_count = new int(1);	//새로운 참조 카운트 생성
			std::cout << "SharedPtr reset. Ref count : " << *ref_count << std::endl;
		}
		else
		{
			ref_count = nullptr;	// 만약 nullptr이면 참조 카운트를 없애
			std::cout << "SharedPtr reset. No resource assigned.\n";
		}
	}

	// 포인터에 접근할 수 있는 연산자
	T& operator*() const
	{
		return *ptr;
	}

	T* operator->() const
	{
		return ptr;
	}

	// 현재 참조 카운트를 반환하는 함수
	int use_count() const
	{
		return *ref_count;
	}
};

int mainsharedPtrMake()
{
	SharedPtr<int> sp1(new int(10));

	{
		SharedPtr<int> sp2 = sp1;	//참조 카운트 증가
		std::cout << "sp2 use count : " << sp2.use_count() << std::endl;

	} //sp2 소멸, 참조 카운트 감소

	std::cout << "sp1 use count : " << sp1.use_count() << std::endl;

	sp1.reset(new int(20)); // 새로운 자원으로 교체
	sp1.reset();

	return 0;
}