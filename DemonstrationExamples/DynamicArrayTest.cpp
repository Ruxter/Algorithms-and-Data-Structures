#include "DynamicArrayTest.h"
#include "ADSLibrary/DataStructures/LinkedStructures/OOP/Queue.h"
#include "ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/Queue.h"
#include "ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Queue.h"
#include "ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Stack.h"
#include "ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/Stack.h"
#include <gtest/gtest.h>
#include "ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/DynamicArray.h"
#include "DummyClass.h"

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


/**------------------Start DynamicArrayTest---------------------**/
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
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameterLoop)
{
	for (int i = 0; i <15001; i++)
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
* Insert, Size, m_count, LastItem, Clear, IsEmpty, IsFull
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameter název unit testu
*/

TEST_F(DynamicArrayOOPTemplateWithParameter, DynamicArrayOOPTemplateTestWithParameter)
{

	EXPECT_EQ(true, list->IsEmpty());
	EXPECT_EQ(NULL, list->LastItem());
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
	EXPECT_EQ(true, list->IsEmpty());
	EXPECT_EQ(true, list->IsFull());
	EXPECT_EQ(NULL, list->LastItem());
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
* Insert, Size, m_count, LastItem
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

struct DynamicArrayOOPTemplateObject : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<DummyClass> *list;
	DynamicArrayOOPTemplateObject()
	{
		list = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<DummyClass>();
	}

	~DynamicArrayOOPTemplateObject()
	{
		delete list;
	}
};
TEST_F(DynamicArrayOOPTemplateObject, DynamicArrayOOPTemplateTestObjects)
{
	DummyClass *a, *b, *c, *d, *e;
	a = new DummyClass();
	b = new DummyClass();
	c = new DummyClass();
	d = new DummyClass();
	e = new DummyClass();
	list->Insert(*a);
	EXPECT_EQ(1, list->m_count);
	EXPECT_EQ(10, list->Size());

}

/**------------------End DynamicArrayTest---------------------**/

DynamicArrayTest::DynamicArrayTest()
{
}


DynamicArrayTest::~DynamicArrayTest()
{
}
