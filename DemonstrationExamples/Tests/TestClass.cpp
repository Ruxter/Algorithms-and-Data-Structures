#include "TestClass.h"
#include <gtest/gtest.h>
#include <stack>
#include "../ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Stack.h"
#include "../ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Queue.h"
#include "../ADSLibrary/DataStructures/ArrayBasedStructures/OOP/Stack.h"

/**
* Struktura pro test kompilace �ablon.
*/
struct DummyStruct
{
	int a;
	double b;
};


/**
* Struktura ArrayBasedStructures::OOPTemplate::Stack pro int
*/
struct StackArrayTempInt : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Stack<int> *stack;

	StackArrayTempInt()
	{
		stack = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::
			Stack<int>();
	}

	~StackArrayTempInt()
	{
		delete stack;
	}
};

/*
* Unit test ArrayBasedStructures::OOPTemplate::Stack pro int
* Push, Pop, IsFull, IsEmpty
* @param StackArrayTemp n�zev struktury,
* @param StackArrayTempTest n�zev unit testu
*/
TEST_F(StackArrayTempInt, StackArrayTempTest)
{
	stack->Push(1);
	stack->Push(3);
	EXPECT_EQ(3, stack->Top());
	stack->Push(5);
	EXPECT_EQ(5, stack->Top());

	stack->Pop();
	EXPECT_EQ(3, stack->Top());

	EXPECT_EQ(false, stack->IsFull());

	stack->Clear();
	EXPECT_EQ(true, stack->IsEmpty());
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::Stack v cyklu pro int
* Push, IsFull,
* @param StackArrayTemp n�zev struktury,
* @param StackArrayTempTest2 n�zev unit testu
*/
TEST_F(StackArrayTempInt, StackArrayTempTest2)
{
	for (int i = 0; i < 100; i++)
	{
		stack->Push(i);
	}

	EXPECT_EQ(true, stack->IsFull());
}


/**
* Struktura ArrayBasedStructures::OOPTemplate::Queue pro string
*/
struct QueueArrayTemp : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Queue<string> *queue;
	QueueArrayTemp()
	{
		queue = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Queue<string>;
	}

	~QueueArrayTemp()
	{
		delete queue;
	}
};

/*
* Unit test ArrayBasedStructures::OOPTemplate::Queue pro string
* Enqueue, Dequeue, Peek,
* @param QueueArrayTemp n�zev struktury,
* @param QueueArrayTempTest n�zev unit testu
*/
TEST_F(QueueArrayTemp, QueueArrayTempTest)
{
	queue->Enqueue("T");
	queue->Enqueue("E");
	queue->Enqueue("S");
	queue->Enqueue("T");
	EXPECT_EQ(false, queue->IsEmpty());
	EXPECT_EQ("T", queue->Peek());
	queue->Dequeue();
	EXPECT_EQ("E", queue->Peek());
	queue->Dequeue();
	EXPECT_EQ("S", queue->Peek());

	EXPECT_EQ(false, queue->IsFull());
	EXPECT_EQ(false, queue->IsEmpty());

	queue->Clear();
	EXPECT_EQ(true, queue->IsEmpty());
}

TEST_F(QueueArrayTemp, QueueArrayTempTest2)
{
	//empty test
}

/**
* Struktura ArrayBasedStructures::OOP::Stack*
*/
struct StackArrayOOP : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::
		Stack *stack;

	StackArrayOOP()
	{
		stack = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::
			Stack;
	}

	~StackArrayOOP()
	{
		delete stack;
	}
};

/*
* Unit test ArrayBasedStructures::OOPTemplate::Queue pro string
* Push, Top, IsEmpty, IsFull
* @param StackArrayOOP n�zev struktury,
* @param QueueArrayOOPTest n�zev unit testu
*/
TEST_F(StackArrayOOP, QueueArrayOOPTest)
{
	stack->Push(1);
	EXPECT_EQ(1, stack->Top());
	EXPECT_EQ(false, stack->IsEmpty());
	EXPECT_EQ(false, stack->IsFull());
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::Queue pro string
* Push, Top, IsEmpty, IsFull. Clear
* @param StackArrayOOP n�zev struktury,
* @param QueueArrayOOPTest2 n�zev unit testu
*/
TEST_F(StackArrayOOP, QueueArrayOOPTest2)
{
	for (int i = 0; i < 100; i++)
	{
		stack->Push(i);
	}

	EXPECT_EQ('c', stack->Top());
	EXPECT_EQ(true, stack->IsFull());

	stack->Clear();
	EXPECT_EQ(true, stack->IsEmpty());
}



TestClass::TestClass()
{
}


TestClass::~TestClass()
{
}