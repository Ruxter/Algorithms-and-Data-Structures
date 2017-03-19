#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/DoublyLinkedList.h"
#include "../../DummyClass.h"
#include <list>


/*
* Soubor sloužící k testování obousmìrného seznamu
*/

/*
* Pomocná struktura pro testování
*/
struct DoublyLinkedListOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<int> *dbllist;
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<char> *dbllist2;
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<DummyClass> *dbllist3;
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<std::string> *dbllist4;
	

	DoublyLinkedListOOPTemplate()
	{
		dbllist = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<int>();
		dbllist2 = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<char>();
		dbllist3 = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<DummyClass>();
		dbllist4 = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::DoublyLinkedList<std::string>();
	}

	~DoublyLinkedListOOPTemplate()
	{
		delete dbllist;
		delete dbllist2;
		delete dbllist3;
		delete dbllist4;
	}
	
};

/*
* Unit test ArrayBasedStructures::OOPTemplate::DoublyLinkedList pro int
* InsertBegin, InsertEnd, IsEmpty, Count. RemoveFirstItem, SearchItem
* @param DoublyLinkedListOOPTemplate název struktury,
* @param DoubleLinkedListOOPTemplateTestInt název unit testu
*/
TEST_F(DoublyLinkedListOOPTemplate, DoubleLinkedListOOPTemplateTestInt)
{
	EXPECT_EQ(true, dbllist->IsEmpty());

	dbllist->InsertBegin(100);
	EXPECT_EQ(1, dbllist->Count());
	EXPECT_EQ(true, dbllist->Search(100));

	dbllist->InsertBegin(200);
	EXPECT_EQ(2, dbllist->Count());
	EXPECT_EQ(false, dbllist->Search(300));

	dbllist->InsertEnd(300);
	EXPECT_EQ(false, dbllist->IsEmpty());
	EXPECT_EQ(3, dbllist->Count());
	EXPECT_EQ(300, dbllist->LastItem());
	EXPECT_EQ(true, dbllist->Search(300));

	dbllist->InsertEnd(400);
	EXPECT_EQ(4, dbllist->Count());
	EXPECT_EQ(400, dbllist->LastItem());
	EXPECT_EQ(true, dbllist->Search(400));
	EXPECT_EQ(false, dbllist->Search(12345));

	dbllist->RemoveFirstItem();
	EXPECT_EQ(3, dbllist->Count());
	EXPECT_EQ(false, dbllist->Search(200));

	dbllist->RemoveFirstItem();
	EXPECT_EQ(2, dbllist->Count());
	EXPECT_EQ(false, dbllist->Search(100));
	EXPECT_EQ(true, dbllist->Search(300));
	EXPECT_EQ(true, dbllist->Search(400));
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DoublyLinkedList pro char
* InsertBegin, InsertEnd, IsEmpty, Count. RemoveLastItem, SearchItem
* @param DoublyLinkedListOOPTemplate název struktury,
* @param DoubleLinkedListOOPTemplateTestChar název unit testu
*/
TEST_F(DoublyLinkedListOOPTemplate, DoubleLinkedListOOPTemplateTestChar)
{
	EXPECT_EQ(true, dbllist->IsEmpty());

	dbllist2->InsertBegin('A');
	EXPECT_EQ(1, dbllist2->Count());
	EXPECT_EQ(true, dbllist2->Search('A'));

	dbllist2->InsertBegin('B');
	EXPECT_EQ(2, dbllist2->Count());
	EXPECT_EQ(false, dbllist2->Search('C'));

	dbllist2->InsertEnd('C');
	EXPECT_EQ(false, dbllist2->IsEmpty());
	EXPECT_EQ(3, dbllist2->Count());
	EXPECT_EQ('C', dbllist2->LastItem());
	EXPECT_EQ(true, dbllist2->Search('C'));

	dbllist2->InsertEnd('D');
	EXPECT_EQ(4, dbllist2->Count());
	EXPECT_EQ('D', dbllist2->LastItem());
	EXPECT_EQ(true, dbllist2->Search('D'));
	EXPECT_EQ(false, dbllist2->Search('Z'));

	dbllist2->RemoveLastItem();
	EXPECT_EQ(3, dbllist2->Count());
	EXPECT_EQ(false, dbllist2->Search('D'));

	dbllist2->RemoveLastItem();
	EXPECT_EQ(2, dbllist2->Count());
	EXPECT_EQ(false, dbllist2->Search('D'));
	EXPECT_EQ(true, dbllist2->Search('B'));
	EXPECT_EQ(true, dbllist2->Search('A'));

	dbllist2->InsertEnd('E');
	EXPECT_EQ(3, dbllist2->Count());
	EXPECT_EQ(true, dbllist2->Search('E'));

	dbllist2->RemoveFirstItem();
	EXPECT_EQ(false, dbllist2->Search('B'));
	EXPECT_EQ(true, dbllist2->Search('A'));
	EXPECT_EQ(true, dbllist2->Search('E'));
	EXPECT_EQ(2, dbllist2->Count());

	dbllist2->Clear();
	EXPECT_EQ(0, dbllist2->Count());
}

/*
* Unit test ArrayBasedStructures::OOPTemplate::DoublyLinkedList pro DummyClass a string
* InsertBegin, InsertEnd, IsEmpty, Count, RemoveLastItem, SearchItem
* @param DoublyLinkedListOOPTemplate název struktury,
* @param DoubleLinkedListOOPTemplateTestDummyAndString název unit testu
*/
TEST_F(DoublyLinkedListOOPTemplate, DoubleLinkedListOOPTemplateTestDummyAndString)
{
	DummyClass *a, *b;
	a = new DummyClass();
	b = new DummyClass();

	DummyClass c;
	DummyClass d;

	EXPECT_EQ(true, dbllist3->IsEmpty());

	dbllist3->InsertBegin(*a);
	dbllist3->InsertBegin(*a);
	dbllist3->InsertEnd(*b);
	
	EXPECT_EQ(false, dbllist3->IsEmpty());
	EXPECT_EQ(3, dbllist3->Count());

	dbllist4->InsertBegin("A"); 
	dbllist4->InsertBegin("B");
	dbllist4->InsertBegin("C");
	dbllist4->InsertBegin("D");
	dbllist4->InsertBegin("E");

	EXPECT_EQ("A", dbllist4->LastItem());
	EXPECT_EQ(true, dbllist4->Search("B"));
	dbllist4->RemoveLastItem();
	EXPECT_EQ("B", dbllist4->LastItem());
	EXPECT_EQ("E", dbllist4->FirstItem());

}