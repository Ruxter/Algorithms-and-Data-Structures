#include "TestClass.h"
#include "ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Stack.h"
#include "ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Queue.h"
#include "ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/Stack.h"
#include "ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/Queue.h"
#include "ADSLibrary/DataStructures/LinkedStructures/OOP/Queue.h"
#include <gtest/gtest.h>
#include "ADSLibrary/DataStructures/ArrayBasedStructures/OOP/Stack.h"
#include "ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/DynamicArray.h"

/**
* Struktura pro test kompilace šablon.
*/
struct DummyStruct
{
	int a;
	double b;
};

/**
* Pahýl funkce, pouze pro zajištìní bezchybného pøekladu.
*/


static void Init()
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Stack<int> *s1 =
		new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Stack<int>();

	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Queue<DummyStruct> *q1 =
		new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::Queue<DummyStruct>();

	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::Stack<DummyStruct> *s2 =
		new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::Stack<DummyStruct>();

	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::Queue<DummyStruct> *q2 =
		new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::Queue<DummyStruct>();

	ADSLibrary::DataStructures::LinkedStructures::OOP::Queue *q =
		new ADSLibrary::DataStructures::LinkedStructures::OOP::Queue();
}

/**
* Struktura ArrayBasedStructures::OOPTemplate::Stack pro integer
*/
struct StackArrayTempInt : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::
		Stack<int> *stack;

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
* Unit test ArrayBasedStructures::OOPTemplate::Stack pro integer
* Push, Pop, IsFull, IsEmpty
* @param StackArrayTemp název struktury,
* @param StackArrayTempTest název unit testu
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
* Unit test ArrayBasedStructures::OOPTemplate::Stack v cyklu pro integer
* Push, IsFull,
* @param StackArrayTemp název struktury,
* @param StackArrayTempTest2 název unit testu
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
* @param QueueArrayTemp název struktury,
* @param QueueArrayTempTest název unit testu
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
* @param StackArrayOOP název struktury,
* @param QueueArrayOOPTest název unit testu
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
* @param StackArrayOOP název struktury,
* @param QueueArrayOOPTest2 název unit testu
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
/*
 * Struktura ArrayBasedStructures::OOPTemplate::DynamicArray pro integer s prázdným konstruktorem
 */
struct DynamicArrayOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int> *list;
	DynamicArrayOOPTemplate()
	{
		list = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int>();
	}

	~DynamicArrayOOPTemplate()
	{
		delete list;
	}
};

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Insert, Size, m_count, LastItem, Clear
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameter název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameter)
{
	EXPECT_EQ(true, list->IsEmpty());
	list->Insert(5);
	EXPECT_EQ(10, list->Size());	
	EXPECT_EQ(1, list->m_count);
	list->Insert(8);
	EXPECT_EQ(2, list->m_count);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(8, list->LastItem());
	list->Insert(10);
	EXPECT_EQ(10, list->LastItem());
	EXPECT_EQ(10, list->Size());
	list->Clear();
	EXPECT_EQ(0, list->m_count);
	EXPECT_EQ(0, list->Size());
	EXPECT_EQ(true, list->IsEmpty());
	list->Insert(4);
	EXPECT_EQ(4, list->LastItem());
	EXPECT_EQ(10, list->Size());
	list->Insert(25);
	EXPECT_EQ(2, list->m_count);
	EXPECT_EQ(25, list->LastItem());
	EXPECT_EQ(10, list->Size());
	for(int i = 0; i<8; i++)
	{
		list->Insert(25);
	}
	EXPECT_EQ(10, list->Size());
	list->Insert(25);
	EXPECT_EQ(20, list->Size());
	EXPECT_EQ(11, list->m_count);
}
/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Insert, Size, m_count, LastItem, Clear
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithParameter název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameterLoop)
{
	for(int i = 0; i <15001; i++)
	{
		list->Insert(i);
	}	
	EXPECT_EQ(15010, list->Size());
	EXPECT_EQ(15001, list->m_count);
	EXPECT_EQ(15000, list->LastItem());
}

/*
* Struktura ArrayBasedStructures::OOPTemplate::DynamicArray pro integer s parametrem
*/
struct DynamicArrayOOPTemplateWithParameter : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int> *list;
	DynamicArrayOOPTemplateWithParameter()
	{
		list = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int>(2);
	}

	~DynamicArrayOOPTemplateWithParameter()
	{
		delete list;
	}
};

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Insert, Size, m_count, LastItem, Clear
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameter název unit testu
*/

TEST_F(DynamicArrayOOPTemplateWithParameter, DynamicArrayOOPTemplateTestWithParameter)
{	
	EXPECT_EQ(true, list->IsEmpty());
	list->Insert(5);
	EXPECT_EQ(2, list->Size());
	EXPECT_EQ(1, list->m_count);
	list->Insert(8);
	EXPECT_EQ(2, list->m_count);
	EXPECT_EQ(2, list->Size());
	EXPECT_EQ(8, list->LastItem());
	list->Insert(10);
	EXPECT_EQ(10, list->LastItem());
	EXPECT_EQ(12, list->Size());
	list->Clear();
	EXPECT_EQ(0, list->m_count);
	EXPECT_EQ(0, list->Size());
	list->Insert(4);
	EXPECT_EQ(4, list->LastItem());
	EXPECT_EQ(10, list->Size());
	list->Insert(25);
	EXPECT_EQ(2, list->m_count);
	EXPECT_EQ(25, list->LastItem());
	EXPECT_EQ(10, list->Size());
	for (int i = 0; i<8; i++)
	{
		list->Insert(25);
	}
	EXPECT_EQ(10, list->Size());
	list->Insert(25);
	EXPECT_EQ(20, list->Size());
	EXPECT_EQ(11, list->m_count);
}
/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Insert, Size, m_count, LastItem, Clear
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithParameter název unit testu
*/
TEST_F(DynamicArrayOOPTemplateWithParameter, DynamicArrayOOPTemplateTestWithParameterLoop)
{
	for (int i = 0; i <15001; i++)
	{
		list->Insert(i);
	}
	EXPECT_EQ(15002, list->Size());
	EXPECT_EQ(15001, list->m_count);
	EXPECT_EQ(15000, list->LastItem());
}



TestClass::TestClass()
{
}


TestClass::~TestClass()
{
}
