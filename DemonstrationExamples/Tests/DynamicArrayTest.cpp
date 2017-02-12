#include "DynamicArrayTest.h"
#include <gtest/gtest.h>
#include "../ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Queue.h"
#include "../ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/DynamicArray.h"
#include "../DummyClass.h"


/*
* Struktura ArrayBasedStructures::OOPTemplate::DynamicArray pro integer s prázdným konstruktorem
* integer s konstruktorem (int), DummyClass, string
*/
struct DynamicArrayOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int> *list;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int> *list2;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<DummyClass> *list3;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<string> *list4;

	DynamicArrayOOPTemplate()
	{
		list = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int>();
		list2 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int>(2);
		list3 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<DummyClass>();
		list4 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<string>();
	}

	~DynamicArrayOOPTemplate()
	{
		delete list;
		delete list2;
		delete list3;
		delete list4;
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
* @param DynamicArrayOOPTemplateTestWithoutParameterLoop název unit testu
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
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Insert, Size, m_count, LastItem, Clear, IsEmpty, IsFull
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithParameter název unit testu
*/

TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithParameter)
{

	EXPECT_EQ(true, list2->IsEmpty());
	EXPECT_EQ(NULL, list2->LastItem());
	list2->Insert(5);
	EXPECT_EQ(2, list2->Size());
	EXPECT_EQ(1, list2->m_count);
	list2->Insert(8);
	EXPECT_EQ(2, list2->m_count);
	EXPECT_EQ(2, list2->Size());
	EXPECT_EQ(8, list2->LastItem());
	list2->Insert(10);
	EXPECT_EQ(10, list2->LastItem());
	EXPECT_EQ(12, list2->Size());
	list2->Clear();
	EXPECT_EQ(0, list2->m_count);
	EXPECT_EQ(0, list2->Size());
	EXPECT_EQ(true, list2->IsEmpty());
	EXPECT_EQ(true, list2->IsFull());
	EXPECT_EQ(NULL, list2->LastItem());
	list2->Insert(4);
	EXPECT_EQ(4, list2->LastItem());
	EXPECT_EQ(10, list2->Size());
	list2->Insert(25);
	EXPECT_EQ(2, list2->m_count);
	EXPECT_EQ(25, list2->LastItem());
	EXPECT_EQ(10, list2->Size());
	for (int i = 0; i<8; i++)
	{
		list2->Insert(25);
	}
	EXPECT_EQ(10, list2->Size());
	list2->Insert(25);
	EXPECT_EQ(20, list2->Size());
	EXPECT_EQ(11, list2->m_count);
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Insert, Size, m_count, LastItem
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithParameterLoop název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithParameterLoop)
{
	for (int i = 0; i <15001; i++)
	{
		list2->Insert(i);
	}
	EXPECT_EQ(15002, list2->Size());
	EXPECT_EQ(15001, list2->m_count);
	EXPECT_EQ(15000, list2->LastItem());
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro DummyClass a string
* Insert, Size, m_count, LastItem
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestObjects název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestObjects)
{
	DummyClass *a;
	a = new DummyClass();
	list3->Insert(*a);
	EXPECT_EQ(1, list3->m_count);
	EXPECT_EQ(10, list3->Size());

	list4->Insert("A");
	list4->Insert("B");

	EXPECT_EQ("B", list4->LastItem());

}

DynamicArrayTest::DynamicArrayTest()
{
}


DynamicArrayTest::~DynamicArrayTest()
{
}
