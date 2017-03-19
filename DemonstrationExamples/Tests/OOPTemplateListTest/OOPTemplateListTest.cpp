#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/List.h"
#include "../../DummyClass.h"

/*
* Soubor sloužící k testování spojového seznamu OOPTemplate
*/

/*
* Pomocná struktura pro testování
*/
struct LinkedListOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::List<int> *list;
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::List<char> *list2;
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::List<DummyClass> *list3;
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::List<std::string> *list4;

	LinkedListOOPTemplate()
	{
		list = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::List<int>();
		list2 = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::List<char>();
		list3 = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::List<DummyClass>();
		list4 = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::List<std::string>();
	}

	~LinkedListOOPTemplate()
	{
		delete list;
		delete list2;
		delete list3;
		delete list4;
	}
};
/*
* Unit test ArrayBasedStructures::OOPTemplate::List pro int
* Insert, FirstItem, IsEmpty, Count, RemoveFirstItem, Search
* @param StackArrayOOP název struktury,
* @param QueueArrayOOPTest2 název unit testu
*/
TEST_F(LinkedListOOPTemplate, LinkedListOOPTemplateTest)
{
	EXPECT_EQ(true, list->IsEmpty());
	EXPECT_EQ(0, list->Count());
	
	list->Insert(5);
	EXPECT_EQ(false, list->IsEmpty());
	EXPECT_EQ(1, list->Count());
	EXPECT_EQ(5, list->FirstItem());
	
	list->Insert(10);
	EXPECT_EQ(2, list->Count());
	EXPECT_EQ(10, list->FirstItem());
	
	list->Insert(20);
	EXPECT_EQ(3, list->Count());
	EXPECT_EQ(20, list->FirstItem());
	EXPECT_EQ(true, list->Search(5));
	EXPECT_EQ(true, list->Search(10));
	EXPECT_EQ(true, list->Search(20));
	EXPECT_EQ(false, list->Search(35));
	
	list->RemoveFirstItem();
	EXPECT_EQ(10, list->FirstItem());
	EXPECT_EQ(2, list->Count());
	
	list->RemoveFirstItem();
	EXPECT_EQ(5, list->FirstItem());
	EXPECT_EQ(1, list->Count());
	
	list->Clear();
	EXPECT_EQ(true, list->IsEmpty());
}
