#include <iostream>
#include <vector>

using namespace std;

// vector를 스택처럼 사용하기

int main7_11_1()
{
	// 동적 배열
	// int *v = new int[3]{1,2,3}; 아래의 코드는 위에 코드와 같다.
	vector<int> v{ 10,20,30 };
	
	//v.resize(2);
	v.reserve(1024);	// 메모리 용량 예약,
	
	/* -size->capacity안에서 그중에 몇 개만 사용한다고 생각 하면 된다.
	
	   - capacity(용량) -> 실제로는 capacity 만큼 메모리를 잡고 있고
	  
	   - reserve는 메모리의 용량을 미리 확보 해놓고 있겠다.
	   미리 용량을 확보하면 new, delete를 호출하는 횟수가 줄어 속도가 빨라진다.
	*/

	// size에 맞춰서 for-each문이 돌아간다.
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// for문 사용법
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	cout << v.size() << " / "  << v.capacity() <<  endl;
	

#pragma region 강제로 size영역에 벗어난 데이터 가져오는 방법

	// vector는 작은 사이즈로 resize할 경우 size만 줄이고 용량을 줄이지 않고 가지고 있다.
	// delete는 성능이 떨어지기 때문에 용량을 바로 줄이지 않는다.

	// 내가 생각한 코드
	int* my_ptr = &v[0];
	cout << *(my_ptr + 2) << endl;

	// 선생님 코드
	int* ptr = v.data();
	cout << ptr[2] << endl;

#pragma endregion


	return 0;
}

void printStack(const vector<int>& stack)
{
	for (auto& e : stack)
		cout << e << " ";

	cout << "/ size : " << stack.size() << endl;
	cout << endl;
}

int main7_11_2()
{
	std::vector<int> stack;

	stack.push_back(3);
	printStack(stack);
	stack.push_back(5);
	printStack(stack);
	stack.push_back(7);
	printStack(stack);
	stack.pop_back();
	printStack(stack);
	stack.pop_back();
	printStack(stack);
	stack.pop_back();


	return 0;
}