#include <cstddef>		// for size_t
#include <stdexcept>	// for exceptions
#include <algorithm>	//for std::swap

namespace yyh
{
	template<typename T, std::size_t N>
	struct array
	{	
		// 멤버 변수 : 고정 크기 배열
		T elems[N];

		// 타입 정의
		using value_type = T;
		using size_type = std::size_t;
		using reference = T&;
		using const_reference = const T&;

		// 배열 크기 반환
		constexpr size_type size() const noexcept
		{
			return N;
		}

		// 비어있는지 확인
		constexpr bool empty() const noexcept
		{
			return N == 0;
		}

		// 인덱스 연산자
		reference operator[](size_type i) noexcept
		{
			return elems[i];
		}

		// const 인덱스 연산자
		const_reference operator[](size_type i) const noexcept
		{
			return elems[i];
		}

		// at() 함수 : 범위 검사 포함
		reference at(size_type i)
		{
			if (i >= N)
				throw std::out_of_range("array index out of range");
			return elems[i];
		}

		const_reference at(size_type i) const
		{
			if (i >= N)
				throw std::out_of_range("array index out of range");
			return elems[i];
		}

		// 첫 번째 원소 반환
		reference front() noexcept
		{
			return elems[0];
		}

		const_reference front() const noexcept
		{
			return elems[0];
		}

		// 마지막 원소 반환
		reference back() noexcept
		{
			return elems[N - 1];
		}

		const_reference back() const noexcept
		{
			return elems[N - 1];
		}

		// 데이터 포인터 반환
		T* data() noexcept
		{
			return elems;
		}

		const T* data() const noexcept
		{
			return elems;
		}

		// fill 함수 : 모든 원소를 주어진 값으로 설정
		void fill(const T& value)
		{
			std::fill_n(elems, N, value);
		}

		// swap 함수 : 다른 array와 교환
		void swap(array& other) noexcept(std::_Is_nothrow_swappable<T>)
		{
			std::swap_ranges(elems, elems + N, other.elems);
		}
	};

	// 비멤버 swap 함수
	template<typename T, std::size_t N>
	void swap(array<T, N>& a, array<T, N>& b) noexcept(noexcept(a.swap(b)))
	{
		a.swap(b);
	}
}