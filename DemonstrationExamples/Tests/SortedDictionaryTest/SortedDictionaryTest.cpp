#include <gtest/gtest.h>
#include "SortedDictionaryTest.h"
#include "../../ADSLibrary/DataStructures/CollectionsGenerics/Dictionary/SortedDictionary.h"

/*
* Soubor sloužící k testování setøízeného slovníku
*/

/*
* Pomocná struktura pro testování
*/
struct SortedDictionaryOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::SortedDictionary<int, int> *dic;
	ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::SortedDictionary<std::string, int > *dic2;

	SortedDictionaryOOPTemplate()
	{
		dic = new ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::SortedDictionary<int, int>();
		dic2 = new ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::SortedDictionary<std::string, int>();
	}

	~SortedDictionaryOOPTemplate()
	{
		delete dic;
		delete dic2;
	}
};

TEST_F(SortedDictionaryOOPTemplate, SortedDictionarOOPTemplateTest)
{
	EXPECT_EQ(true, dic->IsEmpty());
	EXPECT_EQ(false, dic->Contains(4));
	dic->Add(5, 1000);
	dic->Add(4, 2000);
	dic->Add(6, 3000);
	dic->Add(3, 4000);
	dic->Add(7, 5000);
	EXPECT_EQ(true, dic->Contains(5));
	EXPECT_EQ(5, dic->Size());
	EXPECT_EQ(false, dic->IsEmpty());
	dic->Clear();
	EXPECT_EQ(true, dic->IsEmpty());
}

TEST_F(SortedDictionaryOOPTemplate, SortedDictionarOOPTemplateTestOrders)
{
	dic->Add(30, 1000);
	dic->Add(10, 2000);
	dic->Add(20, 3000);
	dic->Add(40, 4000);
	dic->Add(50, 5000);

	dic->InOrder();
	std::cout << "\n\n";
	dic->PreOrder();
	std::cout << "\n\n";
	dic->PostOrder();
}

TEST_F(SortedDictionaryOOPTemplate, SortedDictionarOOPTemplateTestRemove)
{
	dic->Add(50, 500);
	dic->Add(40, 1000);
	dic->Add(45, 1500);
	dic->Add(42, 2000);
	dic->Add(35, 2500);
	dic->Add(55, 3000);
	dic->Add(52, 3500);
	dic->Add(100, 4000);
	dic->Add(72, 4500);
	dic->Add(37, 5000);
	dic->Add(34, 5500);
	dic->Add(101, 6000);

	dic->Remove(40);
	EXPECT_EQ(11, dic->Size());
	EXPECT_EQ(false, dic->Contains(40));
	EXPECT_EQ(true, dic->Contains(50));
	dic->Clear();
	EXPECT_EQ(true, dic->IsEmpty());
}

TEST_F(SortedDictionaryOOPTemplate, SortedDictionarOOPTemplateTestRemove2)
{
	dic->Add(50, 500);
	dic->Add(40, 1000);
	dic->Add(45, 1500);
	dic->Add(42, 2000);
	dic->Add(35, 2500);
	dic->Add(55, 3000);
	dic->Add(52, 3500);
	dic->Add(100, 4000);
	dic->Add(72, 4500);
	dic->Add(37, 5000);
	dic->Add(34, 5500);
	dic->Add(101, 6000);

	dic->Remove(50);
	dic->Remove(55);

	dic->Add(51, 2568);
	dic->Add(48, 963);
}

TEST_F(SortedDictionaryOOPTemplate, SortedDictionarOOPTemplateTest3)
{
	dic->Add(40, 500);
	dic->Add(30, 1000);
	dic->Add(50, 1500); 
	dic->Add(50, 1500);
	dic->Add(30, 1000);
}

TEST_F(SortedDictionaryOOPTemplate, SortedDictionarOOPTemplateNotIntTest)
{
	dic2->Add("M", 1);
	dic2->Add("G", 2);
	dic2->Add("R", 2);
	dic2->Add("B", 3);
	dic2->Add("I", 4);
	dic2->Add("H", 5);
	dic2->Add("X", 6);

	dic2->Remove("M");
}



SortedDictionaryTest::SortedDictionaryTest()
{
}


SortedDictionaryTest::~SortedDictionaryTest()
{
}