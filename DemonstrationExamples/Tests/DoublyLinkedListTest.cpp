#include <gtest/gtest.h>
#include "../ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/DoublyLinkedList.h"

struct DoublyLinkedListOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<int> *dbllist;

	DoublyLinkedListOOPTemplate()
	{
		dbllist = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<int>();
	}

	~DoublyLinkedListOOPTemplate()
	{
		delete dbllist;
	}
};
/*
* Unit test ArrayBasedStructures::OOPTemplate::DoublyLinkedList pro int
* InsertBegin, InsertEnd, IsEmpty, Count. RemoveFirstItem, SearchItem
* @param StackArrayOOP název struktury,
* @param QueueArrayOOPTest2 název unit testu
*/
TEST_F(DoublyLinkedListOOPTemplate, DoubleLinkedListOOPTemplateTest)
{
	EXPECT_EQ(true, dbllist->IsEmpty());

	dbllist->InsertBegin(100);
	EXPECT_EQ(1, dbllist->Count());
	EXPECT_EQ(true, dbllist->SearchItem(100));

	dbllist->InsertBegin(200);
	EXPECT_EQ(2, dbllist->Count());
	EXPECT_EQ(false, dbllist->SearchItem(300));

	dbllist->InsertEnd(300);
	EXPECT_EQ(false, dbllist->IsEmpty());
	EXPECT_EQ(3, dbllist->Count());
	EXPECT_EQ(300, dbllist->LastItem());
	EXPECT_EQ(true, dbllist->SearchItem(300));

	dbllist->InsertEnd(400);
	EXPECT_EQ(4, dbllist->Count());
	EXPECT_EQ(400, dbllist->LastItem());
	EXPECT_EQ(true, dbllist->SearchItem(400));
	EXPECT_EQ(false, dbllist->SearchItem(12345));

	dbllist->RemoveFirstItem();
	EXPECT_EQ(3, dbllist->Count());
	EXPECT_EQ(false, dbllist->SearchItem(200));

	dbllist->RemoveFirstItem();
	EXPECT_EQ(2, dbllist->Count());
	EXPECT_EQ(false, dbllist->SearchItem(100));
	EXPECT_EQ(true, dbllist->SearchItem(300));
	EXPECT_EQ(true, dbllist->SearchItem(400));
}
/*
* Unit test ArrayBasedStructures::OOPTemplate::DoublyLinkedList pro int
* InsertBegin, InsertEnd, IsEmpty, Count. RemoveLastItem, SearchItem
* @param StackArrayOOP název struktury,
* @param QueueArrayOOPTest2 název unit testu
*/
TEST_F(DoublyLinkedListOOPTemplate, DoubleLinkedListOOPTemplateTest2)
{
	EXPECT_EQ(true, dbllist->IsEmpty());

	dbllist->InsertBegin(100);
	EXPECT_EQ(1, dbllist->Count());
	EXPECT_EQ(true, dbllist->SearchItem(100));

	dbllist->InsertBegin(200);
	EXPECT_EQ(2, dbllist->Count());
	EXPECT_EQ(false, dbllist->SearchItem(300));

	dbllist->InsertEnd(300);
	EXPECT_EQ(false, dbllist->IsEmpty());
	EXPECT_EQ(3, dbllist->Count());
	EXPECT_EQ(300, dbllist->LastItem());
	EXPECT_EQ(true, dbllist->SearchItem(300));

	dbllist->InsertEnd(400);
	EXPECT_EQ(4, dbllist->Count());
	EXPECT_EQ(400, dbllist->LastItem());
	EXPECT_EQ(true, dbllist->SearchItem(400));
	EXPECT_EQ(false, dbllist->SearchItem(12345));

	dbllist->RemoveLastItem();
	EXPECT_EQ(3, dbllist->Count());
	EXPECT_EQ(false, dbllist->SearchItem(400));

	dbllist->RemoveLastItem();
	EXPECT_EQ(2, dbllist->Count());
	EXPECT_EQ(false, dbllist->SearchItem(300));
	EXPECT_EQ(true, dbllist->SearchItem(200));
	EXPECT_EQ(true, dbllist->SearchItem(100));

	dbllist->InsertEnd(500);
	EXPECT_EQ(3, dbllist->Count());
	EXPECT_EQ(true, dbllist->SearchItem(500));

	dbllist->RemoveFirstItem();
	EXPECT_EQ(false, dbllist->SearchItem(200));
	EXPECT_EQ(true, dbllist->SearchItem(100));
	EXPECT_EQ(true, dbllist->SearchItem(500));
	EXPECT_EQ(2, dbllist->Count());

	dbllist->Clear();
	EXPECT_EQ(0, dbllist->Count());
}