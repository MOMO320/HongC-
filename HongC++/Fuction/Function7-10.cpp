#include <iostream>

using namespace std;

// 메모리 구조(Heap, Stack, Data, BSS, Code)
// 스택과 힙(Stack , Heap)
// 프로그램이 사용하는 메모리는 일반적으로 세그먼트(segment)라고 하는 몇 가지 다른 영역으로 나뉜다.
// 코드 세그먼트 / 데이터 세그먼트 / 힙 세그먼트 / 스택 세그먼트

/*

  - Heap	:	동적으로 할당된 변수가 할당되는 영역이다.
						   	< 호출 순서 >
				   [Stack]		->		[Heap]
					main()			sizeof(int) x 1000000
				   int *ptr				   Bytes

					delete를 통해 메모리 해제(반납)
		     후 nullptr를 대입해 데이터를 완전히 삭제 해줍니다.

							< 장 점 >
	힙은 큰 메모리 풀이므로 큰 배열, 구조체 또는 클래스를 할당 할 수 있다.						

							< 단 점 >
					힙에 메모리를 할당하는 것은 비교적 느리다.
		할당된 메모리는 명시적으로 할당 해제하거나 응용 프로그램이 종료될 때까지 유지된다.
				(메모리 릭 주의 == 메모리 누수 / memory leak)
		동적으로 할당된 메모리는 포인터를 통해 접근한다. 
	(포인터를 역참조 하는 것은 변수에 직접 접근하는 것보다 느리가.)

  - Stack	:	함수 매개 변수, 지역 변수 및 기타 함수 관련 정보가 저장되는 영역
				stack 안에 호출 순서 대로 저장되게 됩니다.
				가장 마지막에 쌓인 함수를 먼저 제거 하고 순서대로 해제 하게 됩니다.
				LIFO(Last In Fist Out) 
			  
								< 호출 순서 >
						main()	-> main() 안에 변수 저장
						first() -> first() 안에 변수 저장
						second()-> second() 안에 변수 저장

								< 장 점 >
							  속도가 빠르다.

								< 단 점 >
							stack 메모리가 작다.

  - Data	:   초기화된 전역 변수 및 정적 변수가 저장되는 영역 입니다.

  - BSS		: 0으로 초기화된 글로벌 스태틱 값들이 저장되어 있다.
  (Block started by symbol)

  - Code	:	컴파일된 프로그램이 저장되는 영역, 일반적으로 read-only 속성이다.
				코드 영역에는 우리가 작성한 프로그램이 저장되어 있다.(메모리에 올라가 있다.)





*/

#pragma region 메모리 영역 - Stack 예제

int g_i = 0;	// 전역 변수가 가장 먼저 메모리에 자리를 잡음

int second(int x)
{
	return 2 * x;
}

int first(int x)
{
	int y = 3;
	return second(x + y);
}

int main_stack()
{
	int a = 1, b;
	b = first(a);
	cout << b << endl;

	return 0;
}

#pragma endregion

#pragma region 메모리 영역 - Heap 예제

int main_heap()
{
	int* ptr = nullptr;
	ptr = new int[10000000];

	delete[] ptr;
	ptr = nullptr;		// nullptr로 할당해준다.

	return 0;
}
#pragma endregion

/* 함수내에서 heap 영역에 메모리 할당 후 delete(해제)하지 않은 경우 
	
	함수의 호출이 종료되면 메모리 할당한 변수가 사라지게 되어 
	할당해 놓은 메모리를 사용 할 수가 없어진다.(어디 있는지 알 수가 없기 때문에)

	위와 같은 상황은 메모리 누수라고 한다.(주의가 너무 필요하다.)
 */
 void initArray()
{
	int* ptr2 = new int[1000];
	// delete[] ptr2;
}

int main()
{
	initArray();

	return 0;
}