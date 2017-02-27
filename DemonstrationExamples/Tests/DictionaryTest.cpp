#include <gtest/gtest.h>
#include "DictionaryTest.h"
#include "../ADSLibrary/DataStructures/CollectionsGenerics/Dictionary/Dictionary.h"
#include "../ADSLibrary/DataStructures/LinkedStructures/Procedural/List.h"

struct DictionaryOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::Dictionary<int, int> *dic;
	ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::Dictionary<std::string, int> *dic2;

	DictionaryOOPTemplate()
	{
		dic = new ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::Dictionary<int, int>();
		dic2 = new ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::Dictionary<std::string, int>();
	}

	~DictionaryOOPTemplate()
	{
		delete dic;
		delete dic2;
	}
};

TEST_F(DictionaryOOPTemplate, DictionarOOPTemplateTest)
{
	dic->Insert(50, 1000);
	dic->Insert(152, 2000);
	dic->Insert(457, 3000);
	dic->Insert(12, 40000);
	dic->Insert(488, 5000);
	dic->Insert(3565, 1000);
	dic->Insert(88552, 1000);
	dic->Insert(120, 1000);
	dic->Insert(4, 1000);
	dic->Insert(5, 1000);
	dic->Insert(6, 1000);
	dic->Insert(896, 1000);
	dic->Insert(756, 1000);
	dic->Insert(2443, 1000);
	dic->Insert(8566, 1000);
	dic->Insert(257, 1000);
	dic->Insert(4, 2000);

	EXPECT_EQ(2000, dic->Get(4));
	
}

TEST_F(DictionaryOOPTemplate, DictionarOOPTemplateTestString)
{
	dic2->Insert("Neco", 1000);
	dic2->Insert("Neco2", 4000);
}


DictionaryTest::DictionaryTest()
{
}


DictionaryTest::~DictionaryTest()
{
}