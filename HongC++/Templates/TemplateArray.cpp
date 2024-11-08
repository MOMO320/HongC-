#include <cstddef>		// for size_t
#include <stdexcept>	// for exceptions
#include <algorithm>	//for std::swap

namespace yyh
{
	template<typename T, std::size_t N>
	struct array
	{	
		// ��� ���� : ���� ũ�� �迭
		T elems[N];

		// Ÿ�� ����
		using value_type = T;
		using size_type = std::size_t;
		using reference = T&;
		using const_reference = const T&;

		// �迭 ũ�� ��ȯ
		constexpr size_type size() const noexcept
		{
			return N;
		}

		// ����ִ��� Ȯ��
		constexpr bool empty() const noexcept
		{
			return N == 0;
		}

		// �ε��� ������
		reference operator[](size_type i) noexcept
		{
			return elems[i];
		}

		// const �ε��� ������
		const_reference operator[](size_type i) const noexcept
		{
			return elems[i];
		}

		// at() �Լ� : ���� �˻� ����
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

		// ù ��° ���� ��ȯ
		reference front() noexcept
		{
			return elems[0];
		}

		const_reference front() const noexcept
		{
			return elems[0];
		}

		// ������ ���� ��ȯ
		reference back() noexcept
		{
			return elems[N - 1];
		}

		const_reference back() const noexcept
		{
			return elems[N - 1];
		}

		// ������ ������ ��ȯ
		T* data() noexcept
		{
			return elems;
		}

		const T* data() const noexcept
		{
			return elems;
		}

		// fill �Լ� : ��� ���Ҹ� �־��� ������ ����
		void fill(const T& value)
		{
			std::fill_n(elems, N, value);
		}

		// swap �Լ� : �ٸ� array�� ��ȯ
		void swap(array& other) noexcept(std::_Is_nothrow_swappable<T>)
		{
			std::swap_ranges(elems, elems + N, other.elems);
		}
	};

	// ���� swap �Լ�
	template<typename T, std::size_t N>
	void swap(array<T, N>& a, array<T, N>& b) noexcept(noexcept(a.swap(b)))
	{
		a.swap(b);
	}
}