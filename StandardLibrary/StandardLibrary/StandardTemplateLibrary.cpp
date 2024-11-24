#include "header.h"

// ǥ�� ���ø� ���̺귯���� �����̳� �Ұ�
// Standard Template Libraries Containers


/// <summary>
/// sequence container
/// </summary>
void vectorTest()
{
	// vector
	{
		vector<int> vec;	
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);

		for (auto& e : vec)
			cout << e << " ";
		cout << endl;
	}
}

void dequeTest()
{
	deque<int> deq;	// ��, �ڷ� �����͸� ���� �� �ִ�.
	for (int i = 0; i < 10; ++i)
	{
		deq.push_back(i);
		deq.push_front(i);
	}

	for (auto& e : deq)
		cout << e << " ";
	cout << endl;
}

/// <summary>
/// sequence container
/// </summary>

/// <summary>
/// Associative_conatainer
/// </summary>
/// <returns></returns>

void setTest()
{
	set<string> str_set;
	str_set.insert("Hello");
	str_set.insert("World");
	str_set.insert("Hello"); // ���� ���� ���´ٸ� �����ϰԵȴ�.

	cout << str_set.size() << endl;	//2�� ���´�.

	for (auto& e : str_set)
		cout << e << " ";
	cout << endl;
}

// multiset : duplication is allowed , �ڵ� ������ �ȴ�.
void multiSetTest()
{
	cout << "--------- multisetTest ---------------" << endl;
	std::multiset<string> str_set;

	str_set.insert("Hello");
	str_set.insert("World");
	str_set.insert("Hello");
	str_set.insert("b");
	str_set.insert("e");
	str_set.insert("a");

	cout << str_set.size() << endl; // 6(�ߺ��� ������ ���� ��)

	for (auto& e : str_set)
		cout << e << "";
	cout << endl;
}

// map : key / value(����)
void mapTest()
{
	cout << "--------- map Test ---------------" << endl;

	std::map<char, int> map;
	map['c'] = 50;
	map['a'] = 10;
	map['b'] = 20;

	cout << map['a'] << endl;

	map['a'] = 1000;

	cout << map['a'] << endl;

	for (auto& e : map)
		cout << e.first << " / " << e.second << " ";
	cout << endl;
}

// multimap : duplicated keys
void multimapTest()
{
	cout << "--------- multimap Test ---------------" << endl;
	std::multimap<char, int> map;
	map.insert(std::pair<char,int>('a', 10));
	map.insert(std::pair<char,int>('b', 10));
	map.insert(std::pair<char,int>('c', 10));
	map.insert(std::pair<char,int>('a', 2000));

	cout << map.count('a') << endl;

	for (auto& e : map)
		cout << e.first << " " << e.second << " ";
	cout << endl;
}

/// <summary>
/// Container_adapters
/// </summary>
/// <returns></returns>

void stackTest()
{
	cout << "--------- stack Test ---------------" << endl;

	std::stack<int> stack;

	stack.push(1);		// push add a copy
	stack.emplace(2);   // emplace constructs a new object
	stack.emplace(3);

	cout << stack.top() << endl;
	stack.pop();
	cout << stack.top() << endl;
}

// queue
void queueTest()
{
	cout << "--------- queue Test ---------------" << endl;

	std::queue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);

	cout << queue.front() << " " << queue.back() << endl;
	queue.pop();
	cout << queue.front() << " " << queue.back() << endl;
}

// �켱���� ť(Priority queue)
void priorityQueueTest()
{
	cout << "--------- priority queue Test ---------------" << endl;

	std::priority_queue<int> queue;

	for (const int n : {1, 8, 4, 5, 2, 0, 9, 7, 3,11})
		queue.push(n);

	for (int i = 0; i < 10; ++i)
	{
		cout << queue.top() << endl;
		queue.pop();
	}
}


int mainTest()
{
	//vectorTest();
	dequeTest();
	setTest();
	multiSetTest();
	mapTest();
	multimapTest();
	stackTest();
	queueTest();
	priorityQueueTest();
	return 0;
}