#include <gtest/gtest.h>
#include "SortedDictionaryTest.h"
#include "../ADSLibrary/DataStructures/CollectionsGenerics/Dictionary/SortedDictionary.h"

struct SortedDictionaryOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::SortedDictionary<int, int> *dic;

	SortedDictionaryOOPTemplate()
	{
		dic = new ADSLibrary::DataStructures::CollectionsGenerics::Dictionary::SortedDictionary<int, int>();
	}

	~SortedDictionaryOOPTemplate()
	{
		delete dic;
	}
};
TEST_F(SortedDictionaryOOPTemplate, SortedDictionaryOOPTemplateTest)
{
	dic->Add(2, 1);
	dic->Add(1, 4);
	dic->Add(3, 5);
}



SortedDictionaryTest::SortedDictionaryTest()
{
}


SortedDictionaryTest::~SortedDictionaryTest()
{
}