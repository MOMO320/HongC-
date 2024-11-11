#include <iostream>		//std::allocator
#include <memory>
#include <stdexcept>	// for std::out_of_range
#include <initializer_list>

using namespace std;

template<typename T>
class vectorAllocator
{
private:
	std::allocator<T> alloc;	// allocator to manage memory
	T* data;					// pointer to the allocated memory			
	size_t capacity;			// total allocated capacity
	size_t length;				// current number of elements

	// Helper function to reallocate memory with a larger capacity
	void reallocate(size_t new_capacity)
	{
		// 새로운 메모리 할당(데이터 교체를 위해)
		T* new_data = alloc.allocate(new_capacity);
		for (size_t i = 0; i < length; ++i)
		{
			// std::move(data[i]) -> data의 value를 받기 위해
			// 메모리에 값 초기화(객체 생성)
			alloc.construct(new_data + i, std::move(data[i]));
			// 기존 data의 메모리에 값 삭제(객체)
			alloc.destroy(data + i);

			// 이유 : 기존 data들을 new_data에 생성자를 통해 데이터 이전
			
		}
		// 기존 데이터 메모리 해제
		alloc.deallocate(data, capacity);
		data = new_data;
		capacity = new_capacity;
	}
	
public:
	// Constructor
	vectorAllocator() : data(nullptr), capacity(0), length(0) {}
	vectorAllocator(initializer_list<T> datas)
	{
		size_t _length = (size_t)datas.size();
		
		// 메모리 할당
		data = alloc.allocate(_length);;
		size_t index = 0;
		// foreach밖에 접근 안됨
		for (auto& value : datas)
		{
			alloc.construct(data + index, value);
			++index;
		}
		length = _length;
		capacity = _length * 2;
	}
	// Destructor
	~vectorAllocator()
	{
		for (size_t i = 0; i < length; ++i)
			alloc.destroy(data + i);	// destroy each element
		alloc.deallocate(data, capacity);
	}

	// Add on element to the end of the vector
	void push_back(const T& value)
	{
		if (length == capacity)
		{
			size_t new_capacity = (capacity == 0) ? 1 : 2 * capacity;
			// 새로운 용량 만큼 메모리 할당 및 기존 메모리 해제
			reallocate(new_capacity);	
		}
		alloc.construct(data + length, value);
		++length;
	}

	// Remove the last element of the vector
	void pop_back()
	{
		if (length > 0)
		{
			--length;
			alloc.destroy(data + length);
		}
	}

	// Access an element by index
	T& operator[](size_t index)
	{
		if (index >= length)
			throw std::out_of_range("Index out of range");

		int _index = (int)index;
		return data[index];
	}

	size_t size() const
	{
		return length;
	}

	size_t get_capacity() const
	{
		return capacity;
	}
};

int mainAllocatorTest()
{
	vectorAllocator<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	vectorAllocator<int> vecDouble = { 1,2,3,4 };

	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";

	std::cout << std::endl;

	vec.pop_back();

	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < vecDouble.size(); ++i)
	{
		std::cout << vecDouble[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}