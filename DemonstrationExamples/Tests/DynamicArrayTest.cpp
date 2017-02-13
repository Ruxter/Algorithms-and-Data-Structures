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
* Insert, Size, m_count, LastItem, Clear, Search
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameter název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameter)
{
	EXPECT_EQ(true, list->IsEmpty());
	list->Insert(5);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(1, list->m_count);
	EXPECT_EQ(true, list->Search(5));
	list->Insert(8);
	EXPECT_EQ(2, list->m_count);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(8, list->LastItem());
	list->Insert(10);
	EXPECT_EQ(10, list->LastItem());
	EXPECT_EQ(10, list->Size());
	list->Clear();
	EXPECT_EQ(false, list->Search(5));
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
	EXPECT_EQ(true, list->Search(4));
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
	EXPECT_EQ(true, list->Search(125));

	list->Remove(125);
	EXPECT_EQ(15000, list->Size());
	EXPECT_EQ(15000, list->m_count);
	EXPECT_EQ(15000, list->LastItem());
	EXPECT_EQ(false, list->Search(125));
	EXPECT_EQ(true, list->Search(12468));
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Insert, Size, m_count, LastItem, Clear
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameterLoop název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameterLoopRemove)
{
	for (int i = 0; i <11; i++)
	{
		list->Insert(i);
	}
	EXPECT_EQ(20, list->Size());
	EXPECT_EQ(11, list->m_count);
	EXPECT_EQ(10, list->LastItem());
	EXPECT_EQ(true, list->Search(5));

	list->Remove(5);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(10, list->m_count);
	EXPECT_EQ(10, list->LastItem());
	EXPECT_EQ(false, list->Search(5));
	for(int j = 0; j < list->m_count; j++)
	{
		if(j != 5)
		{
			EXPECT_EQ(true, list->Search(j));
		}		
	}

	list->Remove(9);
	list->Remove(1);
	list->Remove(3);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(7, list->m_count);
	EXPECT_EQ(10, list->LastItem());
	EXPECT_EQ(false, list->Search(5));

	list->Remove(2);
	list->Remove(4);
	list->Remove(6);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(4, list->m_count);
	EXPECT_EQ(true, list->Search(8));

	list->Remove(7);
	list->Remove(8);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(2, list->m_count);
	EXPECT_EQ(true, list->Search(0));
	EXPECT_EQ(true, list->Search(10));

	list->Remove(0);
	list->Remove(10);
	EXPECT_EQ(0, list->Size());
	EXPECT_EQ(0, list->m_count);
	EXPECT_EQ(true, list->IsEmpty());
	EXPECT_EQ(false, list->IsFull());
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
	EXPECT_EQ(false, list2->IsFull());
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

	EXPECT_EQ(true, list4->IsEmpty());
	EXPECT_EQ(false, list4->Search("A"));
	list4->Insert("A");
	list4->Insert("B");
	list4->Insert("C");
	list4->Insert("D");

	EXPECT_EQ("D", list4->LastItem());
	EXPECT_EQ(true, list4->Search("A"));
	EXPECT_EQ(false, list4->IsEmpty());
	EXPECT_EQ(4, list4->m_count);
	EXPECT_EQ(10, list4->Size());

	for(int i = 0; i < 8; i++)
	{
		list4->Insert(std::to_string(i));
	}

	EXPECT_EQ(12, list4->m_count);
	EXPECT_EQ(20, list4->Size());
	EXPECT_EQ("7", list4->LastItem());

	EXPECT_EQ(true, list4->Search("4"));
	list4->Remove("4");
	EXPECT_EQ(false, list4->Search("4"));

	EXPECT_EQ(11, list4->m_count);
	EXPECT_EQ(20, list4->Size());
	EXPECT_EQ("7", list4->LastItem());

	EXPECT_EQ(true, list4->Search("3"));
	list4->Remove("3");
	EXPECT_EQ(false, list4->Search("3"));

	EXPECT_EQ(10, list4->m_count);
	EXPECT_EQ(10, list4->Size());
	EXPECT_EQ("7", list4->LastItem());

}

DynamicArrayTest::DynamicArrayTest()
{
}


DynamicArrayTest::~DynamicArrayTest()
{
}
