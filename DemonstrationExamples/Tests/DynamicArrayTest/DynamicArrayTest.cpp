#include "DynamicArrayTest.h"
#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/Queue.h"
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/OOPTemplate/DynamicArray.h"
#include "../../DummyClass.h"

/*
* Soubor slou��c� k testov�n� dynamick�ho pole
*/

/*
* Pomocn� struktura pro testov�n�
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
* Add, Size, Count(), LastItem, Clear, Contains
* @param DynamicArrayOOPTemplate n�zev struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameter n�zev unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameter)
{
	EXPECT_EQ(true, list->IsEmpty());
	list->Add(5);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(1, list->Count());
	EXPECT_EQ(true, list->Contains(5));
	EXPECT_EQ(false, list->IsEmpty());

	list->Add(8);
	EXPECT_EQ(2, list->Count());
	EXPECT_EQ(10, list->Size());

	list->Add(10);
	EXPECT_EQ(10, list->Size());
	list->Add(4);
	list->Add(25);

	list->Clear();
	EXPECT_EQ(false, list->Contains(5));
	EXPECT_EQ(0, list->Count());
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(true, list->IsEmpty());

	list->Add(4);
	EXPECT_EQ(10, list->Size());
	list->Add(25);
	EXPECT_EQ(2, list->Count());
	list->Add(10);
	list->Add(12);
	list->Add(2);
	list->Add(32);
	list->Add(10);
	list->Add(12);
	list->Add(2);
	list->Add(32);
	list->RemoveAt(1);
	list->RemoveAt(5);

	list->InsertAt(2, 100);
	list->InsertAt(2, 100);
	list->InsertAt(2, 100);
	list->InsertAt(2, 100);

	list->Sort();
}
/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add, Size, Count(), LastItem, Clear
* @param DynamicArrayOOPTemplate n�zev struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameterLoop n�zev unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameterLoop)
{
	for (int i = 0; i <15001; i++)
	{
		list->Add(i);
	}
	EXPECT_EQ(15002, list->Size());
	EXPECT_EQ(15001, list->Count());
	EXPECT_EQ(true, list->Contains(125));

	list->Remove(125);
	EXPECT_EQ(15002, list->Size());
	EXPECT_EQ(15000, list->Count());
	for (int i = 0; i <16; i++)
	{
		list->Remove(i * 10);
	}
	EXPECT_EQ(14986, list->Size());
	EXPECT_EQ(14984, list->Count());

	EXPECT_EQ(false, list->Contains(125));
	EXPECT_EQ(true, list->Contains(12468));
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add, Size, Count(), LastItem, Clear
* @param DynamicArrayOOPTemplate n�zev struktury,
* @param DynamicArrayOOPTemplateTestWithoutParameterLoop n�zev unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithoutParameterLoopRemove)
{
	for (int i = 0; i <11; i++)
	{
		list->Add(i);
	}
	EXPECT_EQ(26, list->Size());
	EXPECT_EQ(11, list->Count());

	EXPECT_EQ(true, list->Contains(5));

	list->Remove(5);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(10, list->Count());

	EXPECT_EQ(false, list->Contains(5));
	for (int j = 0; j < list->Count(); j++)
	{
		if (j != 5)
		{
			EXPECT_EQ(true, list->Contains(j));
		}
	}

	list->Remove(9);
	list->Remove(1);
	list->Remove(3);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(7, list->Count());

	EXPECT_EQ(false, list->Contains(5));

	list->Remove(2);
	list->Remove(4);
	list->Remove(6);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(4, list->Count());
	EXPECT_EQ(true, list->Contains(8));

	list->Remove(7);
	list->Remove(8);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(2, list->Count());
	EXPECT_EQ(true, list->Contains(0));
	EXPECT_EQ(true, list->Contains(10));

	list->Remove(0);
	list->Remove(10);
	EXPECT_EQ(10, list->Size());
	EXPECT_EQ(0, list->Count());
	EXPECT_EQ(true, list->IsEmpty());
}


/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add, Size, Count(), LastItem, Clear, IsEmpty, IsFull
* @param DynamicArrayOOPTemplate n�zev struktury,
* @param DynamicArrayOOPTemplateTestWithParameter n�zev unit testu
*/

TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithParameter)
{
	EXPECT_EQ(true, list2->IsEmpty());

	list2->Add(5);
	EXPECT_EQ(12, list2->Size());
	EXPECT_EQ(1, list2->Count());
	list2->Add(8);
	EXPECT_EQ(2, list2->Count());
	EXPECT_EQ(12, list2->Size());

	list2->Add(10);
	EXPECT_EQ(12, list2->Size());
	list2->Clear();
	EXPECT_EQ(0, list2->Count());
	EXPECT_EQ(10, list2->Size());
	EXPECT_EQ(true, list2->IsEmpty());

	list2->Add(4);
	EXPECT_EQ(10, list2->Size());
	list2->Add(25);
	EXPECT_EQ(2, list2->Count());

	EXPECT_EQ(10, list2->Size());
	for (int i = 0; i<8; i++)
	{
		list2->Add(25);
	}
	EXPECT_EQ(10, list2->Size());
	list2->Add(25);
	EXPECT_EQ(26, list2->Size());
	EXPECT_EQ(11, list2->Count());
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add, Size, Count(), LastItem
* @param DynamicArrayOOPTemplate n�zev struktury,
* @param DynamicArrayOOPTemplateTestWithParameterLoop n�zev unit testu
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
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add, Contains, Remove
* @param DynamicArrayOOPTemplate n�zev struktury,
* @param DynamicArrayOOPTemplateTestWithParameterLoop2 n�zev unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithParameterLoop2)
{
	for (int i = 1; i <=10; i++)
	{
		list->Add(i);
	}
	list->Remove(5);
	EXPECT_EQ(true, list->Contains(1));
	EXPECT_EQ(true, list->Contains(2));
	EXPECT_EQ(true, list->Contains(3));
	EXPECT_EQ(true, list->Contains(4));
	EXPECT_EQ(true, list->Contains(6));
	EXPECT_EQ(true, list->Contains(7));
	EXPECT_EQ(true, list->Contains(8));
	EXPECT_EQ(true, list->Contains(9));
	EXPECT_EQ(true, list->Contains(10));
	
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro integer
* Add,  RemoveAt, 
* @param DynamicArrayOOPTemplate n�zev struktury,
* @param DynamicArrayOOPTemplateTestWithParameterLoop3 n�zev unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestWithParameterLoop3)
{
	for (int i = 1; i <= 10; i++)
	{
		list->Add(i);
	}
	list->RemoveAt(4);
	EXPECT_EQ(true, list->Contains(1));
	EXPECT_EQ(true, list->Contains(2));
	EXPECT_EQ(true, list->Contains(3));
	EXPECT_EQ(true, list->Contains(4));
	EXPECT_EQ(false, list->Contains(5));
	EXPECT_EQ(true, list->Contains(6));
	EXPECT_EQ(true, list->Contains(7));
	EXPECT_EQ(true, list->Contains(8));
	EXPECT_EQ(true, list->Contains(9));
	EXPECT_EQ(true, list->Contains(10));

}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DynamicArray pro DummyClass a string
* Add, Size, Count(), LastItem
* @param DynamicArrayOOPTemplate n�zev struktury,
* @param DynamicArrayOOPTemplateTestObjects n�zev unit testu
*/
TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestObjects)
{
	DummyClass* d1 = new DummyClass(10, 10);
	DummyClass* d2 = new DummyClass(11, 10);
	DummyClass* d3 = new DummyClass(5, 10);
	DummyClass* d4 = new DummyClass(4, 10);
	DummyClass* d5 = new DummyClass(15, 10);

	list3->Add(*d1);
	list3->Add(*d2);
	list3->Add(*d3);
	list3->Add(*d4);
	list3->Add(*d5);

	EXPECT_EQ(true, list4->IsEmpty());
	EXPECT_EQ(false, list4->Contains("A"));
	list4->Add("A");
	list4->Add("B");
	list4->Add("C");
	list4->Add("D");

	list4->Report();
	list4->Reverse();
	list4->Report();

	EXPECT_EQ(true, list4->Contains("A"));
	EXPECT_EQ(false, list4->IsEmpty());
	EXPECT_EQ(4, list4->Count());
	EXPECT_EQ(10, list4->Size());

	for (int i = 0; i < 8; i++)
	{
		list4->Add(std::to_string(i));
	}

	EXPECT_EQ(12, list4->Count());
	EXPECT_EQ(26, list4->Size());

	EXPECT_EQ(true, list4->Contains("4"));
	list4->Remove("4");
	EXPECT_EQ(false, list4->Contains("4"));

	EXPECT_EQ(11, list4->Count());
	EXPECT_EQ(26, list4->Size());

	EXPECT_EQ(true, list4->Contains("3"));
	list4->Remove("3");
	EXPECT_EQ(false, list4->Contains("3"));

	EXPECT_EQ(10, list4->Count());
	EXPECT_EQ(10, list4->Size());

	list4->Clear();
	EXPECT_EQ(0, list4->Count());
	EXPECT_EQ(10, list4->Size());
}

TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestBinarySearch)
{
	list->Add(4);
	list->Add(5);
	list->Add(25);
	list->Add(0);
	list->Add(6);
	list->Sort();
	EXPECT_EQ(0, list->BinarySearch(0, list->Count(), 0));
	EXPECT_EQ(4, list->BinarySearch(0, list->Count(), 25));
	EXPECT_EQ(2, list->BinarySearch(0, list->Count(), 5));
	EXPECT_EQ(1, list->BinarySearch(0, list->Count(), 4));
	EXPECT_EQ(3, list->BinarySearch(0, list->Count(), 6));
	list->Report();

	EXPECT_EQ(-1, list->BinarySearch(0, list->Count(), 1000));

	cout << "\n";
	list->RemoveAt(4);
	list->Report();
}

TEST_F(DynamicArrayOOPTemplate, DynamicArrayOOPTemplateTestInsertAt)
{
	list->Add(4);
	list->Add(5);
	list->Add(25);
	list->Add(0);
	list->Add(6);
	list->Sort();
	EXPECT_EQ(0, list->BinarySearch(0, list->Count(), 0));
	EXPECT_EQ(4, list->BinarySearch(0, list->Count(), 25));
	EXPECT_EQ(2, list->BinarySearch(0, list->Count(), 5));
	EXPECT_EQ(1, list->BinarySearch(0, list->Count(), 4));
	EXPECT_EQ(3, list->BinarySearch(0, list->Count(), 6));
}

DynamicArrayTest::DynamicArrayTest()
{

}


DynamicArrayTest::~DynamicArrayTest()
{
}