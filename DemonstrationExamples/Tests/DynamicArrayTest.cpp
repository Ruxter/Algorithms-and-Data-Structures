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
	ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<char> *list5;

	DynamicArrayOOPTemplate()
	{
		list = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int>();
		list2 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<int>(12);
		list3 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<DummyClass>();
		list4 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<string>();
		list5 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate::DynamicArray<char>();
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
* Add, Size, m_count, LastItem, Clear, Contains
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameter název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameter)
{
	EXPECT_EQ(true, list->IsEmpty());
	list->Add(5);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(1, list->m_count);
	EXPECT_EQ(true, list->Contains(5));

	list->Add(8);
	EXPECT_EQ(2, list->m_count);
	EXPECT_EQ(8, list->m_array[1]);
	EXPECT_EQ(10, list->Size());
	
	list->Add(10);	
	EXPECT_EQ(10, list->Size());
	list->Add(4);
	list->Add(25);

	list->Clear();
	EXPECT_EQ(false, list->Contains(5));
	EXPECT_EQ(0, list->m_count);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(true, list->IsEmpty());

	list->Add(4);	
	EXPECT_EQ(10, list->Size());
	list->Add(25);
	EXPECT_EQ(2, list->m_count);
	list->Add(10);
	list->Add(12);
	list->Add(2);
	list->Add(32);


	list->Report();
	list->Sort();
	list->Report();

	EXPECT_EQ(1, list->BinarySearch(0, list->Count(), 4));
	EXPECT_EQ(3, list->BinarySearch(0, list->Count(), 12));
	EXPECT_EQ(5, list->BinarySearch(0, list->Count(), 32));
	EXPECT_EQ(10, list->Size());
	
	EXPECT_EQ(true, list->Contains(4));
	for (int i = 0; i<8; i++)
	{
		list->Add(25);
	}
	EXPECT_EQ(26, list->Size());
	list->Add(25);
	EXPECT_EQ(26, list->Size());
	EXPECT_EQ(15, list->m_count);
}
/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add, Size, m_count, LastItem, Clear
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameterLoop název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameterLoop)
{
	for (int i = 0; i <15001; i++)
	{
		list->Add(i);
	}
	EXPECT_EQ(15002, list->Size());
	EXPECT_EQ(15001, list->m_count);	
	EXPECT_EQ(true, list->Contains(125));

	list->Remove(125);
	EXPECT_EQ(15002, list->Size());
	EXPECT_EQ(15000, list->m_count);
	for (int i = 0; i <16; i++)
	{
		list->Remove(i*10);
	}
	EXPECT_EQ(14986, list->Size());
	EXPECT_EQ(14984, list->m_count);	
	
	EXPECT_EQ(false, list->Contains(125));
	EXPECT_EQ(true, list->Contains(12468));
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add, Size, m_count, LastItem, Clear
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameterLoop název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameterLoopRemove)
{
	for (int i = 0; i <11; i++)
	{
		list->Add(i);
	}
	EXPECT_EQ(26, list->Size());
	EXPECT_EQ(11, list->m_count);
	
	EXPECT_EQ(true, list->Contains(5));

	list->Remove(5);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(10, list->m_count);
	
	EXPECT_EQ(false, list->Contains(5));
	for(int j = 0; j < list->m_count; j++)
	{
		if(j != 5)
		{
			EXPECT_EQ(true, list->Contains(j));
		}		
	}

	list->Remove(9);
	list->Remove(1);
	list->Remove(3);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(7, list->m_count);
	
	EXPECT_EQ(false, list->Contains(5));

	list->Remove(2);
	list->Remove(4);
	list->Remove(6);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(4, list->m_count);
	EXPECT_EQ(true, list->Contains(8));

	list->Remove(7);
	list->Remove(8);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(2, list->m_count);
	EXPECT_EQ(true, list->Contains(0));
	EXPECT_EQ(true, list->Contains(10));

	list->Remove(0);
	list->Remove(10);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(0, list->m_count);
	EXPECT_EQ(true, list->IsEmpty());	
}


/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add, Size, m_count, LastItem, Clear, IsEmpty, IsFull
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithParameter název unit testu
*/

TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithParameter)
{

	EXPECT_EQ(true, list2->IsEmpty());
	
	list2->Add(5);
	EXPECT_EQ(12, list2->Size());
	EXPECT_EQ(1, list2->m_count);
	list2->Add(8);
	EXPECT_EQ(2, list2->m_count);
	EXPECT_EQ(12, list2->Size());
	
	list2->Add(10);	
	EXPECT_EQ(12, list2->Size());
	list2->Clear();
	EXPECT_EQ(0, list2->m_count);
	EXPECT_EQ(10, list2->Size());
	EXPECT_EQ(true, list2->IsEmpty());
	
	list2->Add(4);	
	EXPECT_EQ(10, list2->Size());
	list2->Add(25);
	EXPECT_EQ(2, list2->m_count);
	
	EXPECT_EQ(10, list2->Size());
	for (int i = 0; i<8; i++)
	{
		list2->Add(25);
	}
	EXPECT_EQ(10, list2->Size());
	list2->Add(25);
	EXPECT_EQ(26, list2->Size());
	EXPECT_EQ(11, list2->m_count);

	
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add, Size, m_count, LastItem
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestWithParameterLoop název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithParameterLoop)
{
	for (int i = 0; i <15001; i++)
	{
		list2->Add(i);
	}
	EXPECT_EQ(15004, list2->Size());	
	EXPECT_EQ(15001, list2->Count());	

	for (int i = 0; i <14000; i++)
	{
		list2->Remove(i);
	}
	EXPECT_EQ(1004, list2->Size());
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro DummyClass a string
* Add, Size, m_count, LastItem
* @param DynamicArrayOOPTemplate název struktury,
* @param DynamicArrayOOPTemplateTestObjects název unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestObjects)
{
	DummyClass *a, *b, *c;	
	a = new DummyClass();
	a->a = 5;
	a->b = 10;
	b = new DummyClass();
	b->a = 10;
	b->b = 20;
	c = new DummyClass();
	c->a = 15;
	c->b = 30;
	list3->Add(*a);
	list3->Add(*b);
	list3->Add(*c);



	EXPECT_EQ(3, list3->m_count);
	EXPECT_EQ(10, list3->Size());

	EXPECT_EQ(true, list4->IsEmpty());
	EXPECT_EQ(false, list4->Contains("A"));
	/*list4->Add("A");
	list4->Add("C");
	list4->Add("B");
	list4->Add("D");*/
	list4->Add("A");
	list4->Add("B");
	list4->Add("C");
	list4->Add("D");

	EXPECT_EQ(true, list4->Contains("A"));
	EXPECT_EQ(false, list4->IsEmpty());
	EXPECT_EQ(4, list4->m_count);
	EXPECT_EQ(10, list4->Size());

	for(int i = 0; i < 8; i++)
	{
		list4->Add(std::to_string(i));
	}

	EXPECT_EQ(12, list4->m_count);
	EXPECT_EQ(26, list4->Size());
	
	EXPECT_EQ(true, list4->Contains("4"));
	list4->Remove("4");
	EXPECT_EQ(false, list4->Contains("4"));

	EXPECT_EQ(11, list4->m_count);
	EXPECT_EQ(26, list4->Size());	

	EXPECT_EQ(true, list4->Contains("3"));
	list4->Remove("3");
	EXPECT_EQ(false, list4->Contains("3"));

	EXPECT_EQ(10, list4->m_count);
	EXPECT_EQ(10, list4->Size());	

	list4->Clear();
	EXPECT_EQ(0, list4->m_count);
	EXPECT_EQ(10, list4->Size());
}

DynamicArrayTest::DynamicArrayTest()
{
	
}


DynamicArrayTest::~DynamicArrayTest()
{
}
