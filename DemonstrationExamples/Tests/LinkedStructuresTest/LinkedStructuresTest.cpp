#include "LinkedStructuresTest.h"
#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/LinkedStructures/Procedural/Stack.h"
#include "../../ADSLibrary/DataStructures/LinkedStructures/Procedural/Queue.h"
#include "../../ADSLibrary/DataStructures/LinkedStructures/Procedural/List.h"
#include "../../ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/Stack.h"
#include "../../ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/Queue.h"
#include "../../ADSLibrary/DataStructures/LinkedStructures/OOP/Stack.h"
#include "../../ADSLibrary/DataStructures/LinkedStructures/OOP/Queue.h"
#include "../../ADSLibrary/DataStructures/LinkedStructures/OOP/List.h"

/*
* T¯Ìda slouûÌcÌ k testov·nÌ LinkedStructures (OOP, OOPTemplate, Procedural)
* T¯Ìdy List a DoublyLinkedList ze jmennÈho prostoru OOPTemplate jsou testov·ny zvl·öù
*/

struct LinkedStructuresStruct : testing::Test
{
	ADSLibrary::DataStructures::LinkedStructures::Procedural::Stack *stack;
	ADSLibrary::DataStructures::LinkedStructures::Procedural::Queue *queue;
	ADSLibrary::DataStructures::LinkedStructures::Procedural::List *list;
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::Stack<int> *stack2;
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::Queue<int> *queue2;
	ADSLibrary::DataStructures::LinkedStructures::OOP::Stack *stack3;
	ADSLibrary::DataStructures::LinkedStructures::OOP::Queue *queue3;
	ADSLibrary::DataStructures::LinkedStructures::OOP::List *list3;

	LinkedStructuresStruct()
	{
		stack = new ADSLibrary::DataStructures::LinkedStructures::Procedural::Stack();
		queue = new ADSLibrary::DataStructures::LinkedStructures::Procedural::Queue();
		list = new ADSLibrary::DataStructures::LinkedStructures::Procedural::List();
		stack2 = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::Stack<int>();
		queue2 = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::Queue<int>();
		stack3 = new ADSLibrary::DataStructures::LinkedStructures::OOP::Stack();
		queue3 = new ADSLibrary::DataStructures::LinkedStructures::OOP::Queue();
		list3 = new ADSLibrary::DataStructures::LinkedStructures::OOP::List();

	}

	~LinkedStructuresStruct()
	{
		delete stack;
		delete queue;
		delete list;
		delete stack2;
		delete queue2;
		delete stack3;
		delete queue3;
		delete list3;
	}
};

/*
* Unit test LinkedStructures::OOP::Queue, LinkedStructures::OOP::Stack, LinkedStructures::OOP::List, LinkedStructures::OOP::ListWithSentinel, 
* LinkedStructures::OOP::BinarySearchTree
* Init, Push, Pop, Top, IsEmpty, IsFull, Enqueue, Dequeue, Clear, Count, Insert, Delete
* @param LinkedStructuresStruct n·zev struktury,
* @param LinkedStructuresTest n·zev unit testu
*/
TEST_F(LinkedStructuresStruct, LinkedStructuresTest)
{
	//Stack
	EXPECT_EQ(true, stack2->IsEmpty());
	stack2->Push('a');
	stack2->Push('b');
	stack2->Push('c');
	EXPECT_EQ('c', stack2->Top());
	stack2->Push('d');
	stack2->Push('e');
	EXPECT_EQ(false, stack2->IsEmpty());
	stack2->Push('f');
	stack2->Push('g');
	stack2->Push('h');
	EXPECT_EQ('h', stack2->Top());
	stack2->Push('i');
	stack2->Push('j');
	EXPECT_EQ('j', stack2->Top());

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
	EXPECT_EQ(1, queue2->Peek());
	queue2->Enqueue(4);
	queue2->Enqueue(5);
	EXPECT_EQ(false, queue2->IsEmpty());
	queue2->Enqueue(6);
	queue2->Enqueue(7);
	EXPECT_EQ(1, queue2->Peek());
	queue2->Enqueue(8);
	queue2->Enqueue(9);
	queue2->Enqueue(10);

	EXPECT_EQ(1, queue2->Dequeue());
	EXPECT_EQ(2, queue2->Dequeue());
	EXPECT_EQ(3, queue2->Peek());
	EXPECT_EQ(3, queue2->Dequeue());
	EXPECT_EQ(4, queue2->Dequeue());
	EXPECT_EQ(5, queue2->Peek());
	EXPECT_EQ(5, queue2->Dequeue());
	EXPECT_EQ(false, queue2->IsEmpty());
	queue2->Clear();
	EXPECT_EQ(true, queue2->IsEmpty());


	//List
	EXPECT_EQ(true, list3->IsEmpty());
	list3->Insert(1);
	list3->Insert(2);
	list3->Insert(3);
	list3->Insert(4);
	list3->Insert(5);
	EXPECT_EQ(false, list3->IsEmpty());
	list3->Insert(6);
	list3->Insert(7);
	list3->Insert(8);
	list3->Insert(9);
	list3->Insert(10);
	EXPECT_EQ(10, list3->Count());

	EXPECT_EQ(true, list3->Search(2));
	list3->Delete(2);
	EXPECT_EQ(false, list3->Search(2));
	EXPECT_EQ(9, list3->Count());
	list3->Delete(4);
	EXPECT_EQ(8, list3->Count());
	EXPECT_EQ(false, list3->Search(4));
	EXPECT_EQ(true, list3->Search(9));
	list3->Clear();
	EXPECT_EQ(true, list3->IsEmpty());
	EXPECT_EQ(0, list3->Count());
}
/*
* Unit test LinkedStructures::OOPTemplate::Queue a LinkedStructures::OOPTemplate::Stack
* Init, Push, Pop, Top, IsEmpty, IsFull, Enqueue, Dequeue, Clear
* @param LinkedStructuresStruct n·zev struktury,
* @param LinkedStructuresTest2 n·zev unit testu
*/
TEST_F(LinkedStructuresStruct, LinkedStructuresTest2)
{
	//Stack
	EXPECT_EQ(true, stack2->IsEmpty());
	stack2->Push('a');
	stack2->Push('b');
	stack2->Push('c');
	EXPECT_EQ('c', stack2->Top());
	stack2->Push('d');
	stack2->Push('e');
	EXPECT_EQ(false, stack2->IsEmpty());
	stack2->Push('f');
	stack2->Push('g');
	stack2->Push('h');
	EXPECT_EQ('h', stack2->Top());
	stack2->Push('i');
	stack2->Push('j');
	EXPECT_EQ('j', stack2->Top());

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
	queue2->Enqueue(4);
	queue2->Enqueue(5);
	EXPECT_EQ(false, queue2->IsEmpty());
	queue2->Enqueue(6);
	queue2->Enqueue(7);
	queue2->Enqueue(8);
	queue2->Enqueue(9);
	queue2->Enqueue(10);

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
* Unit test LinkedStructures::Procedural::Queue, LinkedStructures::Procedural::Stack a LinkedStructures::Procedural::List
* Init, Push, Pop, Top, IsEmpty, Enqueue, Dequeue, Insert, Count, Delete, Search, Clear
* @param LinkedStructuresStruct n·zev struktury,
* @param LinkedStructuresTest3 n·zev unit testu
*/
TEST_F(LinkedStructuresStruct, LinkedStructuresTest3)
{
	Init(*stack);
	EXPECT_EQ(true, IsEmpty(*stack));
	Push(*stack, 'a');
	EXPECT_EQ('a', Top(*stack));
	Push(*stack, 'b');
	EXPECT_EQ('b', Top(*stack));
	Push(*stack, 'c');
	EXPECT_EQ(false, IsEmpty(*stack));
	Push(*stack, 'd');
	EXPECT_EQ('d', Top(*stack));
	Push(*stack, 'e');
	EXPECT_EQ(false, IsEmpty(*stack));
	Push(*stack, 'f');
	Push(*stack, 'g');
	Push(*stack, 'h');
	EXPECT_EQ('h', Top(*stack));
	Push(*stack, 'i');
	Push(*stack, 'j');
	EXPECT_EQ(false, IsEmpty(*stack));

	EXPECT_EQ('j', Pop(*stack));
	EXPECT_EQ('i', Pop(*stack));
	EXPECT_EQ('h', Top(*stack));
	Pop(*stack);
	EXPECT_EQ('g', Pop(*stack));
	EXPECT_EQ('f', Pop(*stack));
	EXPECT_EQ(false, IsEmpty(*stack));
	Clear(*stack);
	EXPECT_EQ(true, IsEmpty(*stack));

	Init(*queue);
	EXPECT_EQ(true, IsEmpty(*queue));
	Enqueue(*queue, 1);
	Enqueue(*queue, 2);
	EXPECT_EQ(1, Peek(*queue));
	Enqueue(*queue, 3);
	EXPECT_EQ(false, IsEmpty(*queue));
	Enqueue(*queue, 4);
	Enqueue(*queue, 5);
	EXPECT_EQ(false, IsEmpty(*queue));
	Enqueue(*queue, 6);
	Enqueue(*queue, 7);
	Enqueue(*queue, 8); 
	EXPECT_EQ(1, Peek(*queue));
	Enqueue(*queue, 9);
	Enqueue(*queue, 10);

	EXPECT_EQ(1, Dequeue(*queue));
	EXPECT_EQ(2, Dequeue(*queue));
	EXPECT_EQ(3, Peek(*queue));
	Dequeue(*queue);
	EXPECT_EQ(4, Dequeue(*queue));
	EXPECT_EQ(5, Dequeue(*queue));
	EXPECT_EQ(false, IsEmpty(*queue));
	Clear(*queue);
	EXPECT_EQ(true, IsEmpty(*queue));

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

LinkedStructuresTest::LinkedStructuresTest()
{
}


LinkedStructuresTest::~LinkedStructuresTest()
{
}
