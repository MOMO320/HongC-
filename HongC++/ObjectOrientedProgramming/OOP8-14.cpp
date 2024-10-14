#include "file.h"

// 클래스 안에 포함된 자료형(Nested types)
//
//enum FruitType
//{
//	APPLE, BANANA, CHERRY,
//};

// 특정 클래스만 사용하는 데이터 타입일 경우
// 클래스 안에 선언해서 사용하는 것이 좋다.
class Fruit
{
public:
	//									클래스명::자료형
	// 아래와 같이 선언하면 사용할때 -> Fruit::APPLE 이렇게 사용 가능함
	//enum FruitType    
	//{
	//	APPLE, BANANA, CHERRY,
	//};

	// Fruit::FruitType::APPLE  이렇게 사용
	enum class FruitType		
	{
		APPLE, BANANA, CHERRY,
	};

	class InnerClass
	{

	};

	struct InnerStruct
	{

	};

private:
	FruitType m_type;

public:
	Fruit(FruitType type) : m_type(type) {}

	FruitType getType() { return m_type; }
};

int main8_14()
{
	Fruit apple(Fruit::FruitType::APPLE);

	if (apple.getType() == Fruit::FruitType::APPLE)
	{
		cout << "Apple" << endl;
	}


	return 0;
}