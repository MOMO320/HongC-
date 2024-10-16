#include <iostream>
#include <cassert>
using namespace std;

// [] subscript operator
// 첨자 연산자 오버로딩 하기

class IntList
{
private:
	int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };
public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getList()
	{
		return m_list;	// array 자체가 포인터
	}
	
	// 참조로 return 해주는 이유는 Lvalue 여야 하고,
	//  값 변경을 할 수 있게 하기 위해
	int& operator[] (const int value)	// 내가 구현한 코드
	{
		// assert를 이용해서 허점을 잡아냄
		// 자주 사용하는 첨자 연산자에 if문을 넣는것은 효율적이지 못하니깐
		// assert를 걸어 퍼포먼스를 높이고 디버깅을 잘 하자
		assert(value >= 0);
		assert(value < 10);

		return this->m_list[value];
	}

	// const operator
	const int& operator [] (const int index) const
	{
		assert(value >= 0);
		assert(value < 10);

		return this->m_list[index];
	}
};

int main9_6_1()
{
	IntList my_list;
	my_list.setItem(3, 1);

	cout << my_list.getItem(3) << endl;
	my_list.getList()[3] = 10;
	cout << my_list.getList()[3] << endl;

	cout << my_list[3] << endl;

	const IntList const_list;
	//const_list[1] = 10;	// const이기 때문에 에러 발생
	cout << const_list[1] << endl; // 읽는건 가능 함
	return 0;
}


int main()
{
	IntList* list = new IntList;

	(*list)[3] = 10;	// ok
	//list[3] = 10;		// 의도가 다르다.(error!)

	return 0;
}