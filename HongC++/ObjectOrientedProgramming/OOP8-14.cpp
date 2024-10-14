#include "file.h"

// Ŭ���� �ȿ� ���Ե� �ڷ���(Nested types)
//
//enum FruitType
//{
//	APPLE, BANANA, CHERRY,
//};

// Ư�� Ŭ������ ����ϴ� ������ Ÿ���� ���
// Ŭ���� �ȿ� �����ؼ� ����ϴ� ���� ����.
class Fruit
{
public:
	//									Ŭ������::�ڷ���
	// �Ʒ��� ���� �����ϸ� ����Ҷ� -> Fruit::APPLE �̷��� ��� ������
	//enum FruitType    
	//{
	//	APPLE, BANANA, CHERRY,
	//};

	// Fruit::FruitType::APPLE  �̷��� ���
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