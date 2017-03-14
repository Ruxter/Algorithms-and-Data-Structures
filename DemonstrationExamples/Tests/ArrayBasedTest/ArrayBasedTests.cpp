#include "ArrayBasedTests.h"
#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/OOP/Stack.h"
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/OOP/Queue.h"
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Stack.h"
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Queue.h"
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/Procedural/Stack.h"
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/Procedural/Queue.h"
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/Procedural/List.h"

/*
* Tøída sloužící k testování ArrayBasedStructures (OOP, OOPTemplate, Procedural)
* Tøída DynamicArray je testována ve složce DynamicArrayTest
*/

/*
* Pomocná struktura pro testování
*/
struct ArrayBasedTest : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::Stack *stack;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::Queue *queue;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Stack<char> *stack2;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Queue<int> *queue2;
	ADSLibrary::DataStructures::ArrayBasedStructures::Procedural::Stack *stack3;
	ADSLibrary::DataStructures::ArrayBasedStructures::Procedural::Queue *queue3;
	ADSLibrary::DataStructures::ArrayBasedStructures::Procedural::List *list;

	ArrayBasedTest()
	{
		stack = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::Stack(10);
		queue = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::Queue(10);
		stack2 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Stack<char>(10);
		queue2 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Queue<int>(10);
		stack3 = new ADSLibrary::DataStructures::ArrayBasedStructures::Procedural::Stack();
		queue3 = new ADSLibrary::DataStructures::ArrayBasedStructures::Procedural::Queue();
		list = new ADSLibrary::DataStructures::ArrayBasedStructures::Procedural::List();
	}

	~ArrayBasedTest()
	{
		delete stack;
		delete queue;
		delete stack2;
		delete queue2;
		delete stack3;
		delete queue3;
		delete list;
	}
};

/*
* Unit test ArrayBasedStructures::OOPTemplate::Queue a ArrayBasedStructures::OOPTemplate::Stack
* Init, Push, Pop, Top, IsEmpty, IsFull, Enqueue, Dequeue, Clear
* @param ArrayBasedTest název struktury,
* @param ArrayBasedTest1 název unit testu
*/
TEST_F(ArrayBasedTest, ArrayBasedTest1)
{
	//Stack
	EXPECT_EQ(true, stack->IsEmpty());
	stack->Push('a');
	stack->Push('b');
	stack->Push('c');
	EXPECT_EQ(false, stack->IsFull());
	stack->Push('d');
	stack->Push('e');
	EXPECT_EQ(false, stack->IsEmpty());
	EXPECT_EQ(false, stack->IsFull());
	stack->Push('f');
	stack->Push('g');
	EXPECT_EQ(false, stack->IsFull());
	stack->Push('h');
	stack->Push('i');
	stack->Push('j');
	EXPECT_EQ(true, stack->IsFull());

	EXPECT_EQ('j', stack->Pop());
	EXPECT_EQ('i', stack->Pop());
	EXPECT_EQ('h', stack->Top());
	stack->Pop();
	EXPECT_EQ('g', stack->Pop());
	EXPECT_EQ('f', stack->Pop());
	EXPECT_EQ(false, stack->IsEmpty());
	stack->Clear();
	EXPECT_EQ(true, stack->IsEmpty());

	//Queue
	EXPECT_EQ(true, queue->IsEmpty());
	queue->Enqueue(1);
	queue->Enqueue(2);
	queue->Enqueue(3);
	EXPECT_EQ(false, queue->IsFull());
	queue->Enqueue(4);
	queue->Enqueue(5);
	EXPECT_EQ(false, queue->IsEmpty());
	EXPECT_EQ(false, queue->IsFull());
	queue->Enqueue(6);
	queue->Enqueue(7);
	EXPECT_EQ(false, queue->IsFull());
	queue->Enqueue(8);
	queue->Enqueue(9);
	queue->Enqueue(10);
	EXPECT_EQ(true, queue->IsFull());

	EXPECT_EQ(1, queue->Dequeue());
	EXPECT_EQ(2, queue->Dequeue());
	EXPECT_EQ(3, queue->Dequeue());
	EXPECT_EQ(4, queue->Dequeue());
	EXPECT_EQ(5, queue->Dequeue());
	EXPECT_EQ(false, queue->IsEmpty());
	queue->Clear();
	EXPECT_EQ(true, queue->IsEmpty());
}

/*
* Unit test ArrayBasedStructures::OOP::Queue a ArrayBasedStructures::OOP::Stack
* Init, Push, Pop, Top, IsEmpty, IsFull, Enqueue, Dequeue, Clear
* @param ArrayBasedTest název struktury,
* @param ArrayBasedTest2 název unit testu
*/
TEST_F(ArrayBasedTest, ArrayBasedTest2)
{
	//Stack
	EXPECT_EQ(true, stack2->IsEmpty());
	stack2->Push('a');
	stack2->Push('b');
	stack2->Push('c');
	EXPECT_EQ(false, stack2->IsFull());
	stack2->Push('d');
	stack2->Push('e');
	EXPECT_EQ(false, stack2->IsEmpty());
	EXPECT_EQ(false, stack2->IsFull());
	stack2->Push('f');
	stack2->Push('g');
	EXPECT_EQ(false, stack2->IsFull());
	stack2->Push('h');
	stack2->Push('i');
	stack2->Push('j');
	EXPECT_EQ(true, stack2->IsFull());

	EXPECT_EQ('j', stack2->Pop());
	EXPECT_EQ('i', stack2->Pop());
	EXPECT_EQ('h', stack2->Top());
	stack2->Pop();
	EXPECT_EQ('g', stack2->Pop());
	EXPECT_EQ('f', stack2->Pop());
	EXPECT_EQ(false, stack2->IsEmpty());
	stack2->Clear();
	EXPECT_EQ(true, stack2->IsEmpty());

	//Queue
	EXPECT_EQ(true, queue2->IsEmpty());
	queue2->Enqueue(1);
	queue2->Enqueue(2);
	queue2->Enqueue(3);
	EXPECT_EQ(false, queue2->IsFull());
	queue2->Enqueue(4);
	queue2->Enqueue(5);
	EXPECT_EQ(false, queue2->IsEmpty());
	EXPECT_EQ(false, queue2->IsFull());
	queue2->Enqueue(6);
	queue2->Enqueue(7);
	EXPECT_EQ(false, queue2->IsFull());
	queue2->Enqueue(8);
	queue2->Enqueue(9);
	queue2->Enqueue(10);
	EXPECT_EQ(true, queue2->IsFull());

	EXPECT_EQ(1, queue2->Dequeue());
	EXPECT_EQ(2, queue2->Dequeue());
	EXPECT_EQ(3, queue2->Dequeue());
	EXPECT_EQ(4, queue2->Dequeue());
	EXPECT_EQ(5, queue2->Dequeue());
	EXPECT_EQ(false, queue2->IsEmpty());
	queue2->Clear();
	EXPECT_EQ(true, queue2->IsEmpty());
}


/*
* Unit test ArrayBasedStructures::Procedural::Queue, ArrayBasedStructures::Procedural::Stack a ArrayBasedStructures::Procedural::List
* Init, Push, Pop, Top, IsEmpty, IsFull, Enqueue, Dequeue, Insert, Count, Delete, Search, Clear
* @param ArrayBasedTest název struktury,
* @param ArrayBasedTest3 název unit testu
*/
TEST_F(ArrayBasedTest, ArrayBasedTest3)
{
	using namespace ADSLibrary::DataStructures::ArrayBasedStructures::Procedural;
	Init(*stack3);
	EXPECT_EQ(true, IsEmpty(*stack3));
	Push(*stack3, 'a');
	Push(*stack3, 'b');
	Push(*stack3, 'c');
	EXPECT_EQ(false, IsEmpty(*stack3));
	EXPECT_EQ(false, IsFull(*stack3));
	Push(*stack3, 'd');
	Push(*stack3, 'e');
	EXPECT_EQ(false, IsFull(*stack3));
	EXPECT_EQ(false, IsEmpty(*stack3));
	Push(*stack3, 'f');
	Push(*stack3, 'g');
	EXPECT_EQ(false, IsFull(*stack3));
	Push(*stack3, 'h');
	Push(*stack3, 'i');
	Push(*stack3, 'j');
	EXPECT_EQ(true, IsFull(*stack3));

	EXPECT_EQ('j', Pop(*stack3));
	EXPECT_EQ('i', Pop(*stack3));
	EXPECT_EQ('h', Top(*stack3));
	Pop(*stack3);
	EXPECT_EQ('g', Pop(*stack3));
	EXPECT_EQ('f', Pop(*stack3));
	EXPECT_EQ(false, IsEmpty(*stack3));
	Clear(*stack3);
	EXPECT_EQ(true, IsEmpty(*stack3));

	Init(*queue3);
	EXPECT_EQ(true, IsEmpty(*queue3));
	Enqueue(*queue3, 1);
	Enqueue(*queue3, 2);
	Enqueue(*queue3, 3);
	EXPECT_EQ(false, IsEmpty(*queue3));
	EXPECT_EQ(false, IsFull(*queue3));
	Enqueue(*queue3, 4);
	Enqueue(*queue3, 5);
	EXPECT_EQ(false, IsFull(*queue3));
	EXPECT_EQ(false, IsEmpty(*queue3));
	Enqueue(*queue3, 6);
	Enqueue(*queue3, 7);
	EXPECT_EQ(false, IsFull(*queue3));
	Enqueue(*queue3, 8);
	Enqueue(*queue3, 9);
	Enqueue(*queue3, 10);
	EXPECT_EQ(true, IsFull(*queue3));

	EXPECT_EQ(1, Dequeue(*queue3));
	EXPECT_EQ(false, IsFull(*queue3));
	EXPECT_EQ(2, Dequeue(*queue3));
	EXPECT_EQ(false, IsFull(*queue3));
	EXPECT_EQ(3, Peek(*queue3));
	EXPECT_EQ(false, IsFull(*queue3));
	Dequeue(*queue3);
	EXPECT_EQ(4, Dequeue(*queue3));
	EXPECT_EQ(5, Dequeue(*queue3));
	EXPECT_EQ(false, IsEmpty(*queue3));
	Clear(*queue3);
	EXPECT_EQ(true, IsEmpty(*queue3));
	EXPECT_EQ(true, IsFull(*queue3));

	Init(*list);
	EXPECT_EQ(true, IsEmpty(*list));
	Insert(*list, 1);
	Insert(*list, 2);
	Insert(*list, 3);
	EXPECT_EQ(false, IsEmpty(*list));
	Insert(*list, 4);
	Insert(*list, 5);
	Insert(*list, 6);
	EXPECT_EQ(false, IsEmpty(*list));
	Insert(*list, 7);
	Insert(*list, 8);
	Insert(*list, 9);
	Insert(*list, 10);
	EXPECT_EQ(false, IsEmpty(*list));
	EXPECT_EQ(10, Count(*list));

	Delete(*list, 1);
	EXPECT_EQ(9, Count(*list));
	Delete(*list, 6);
	EXPECT_EQ(8, Count(*list));
	EXPECT_EQ(true, Search(*list, 5));
	Delete(*list, 5);
	EXPECT_EQ(false, Search(*list, 5));
	Clear(*list);
	EXPECT_EQ(true, IsEmpty(*list));
}

ArrayBasedTests::ArrayBasedTests()
{
}


ArrayBasedTests::~ArrayBasedTests()
{
}