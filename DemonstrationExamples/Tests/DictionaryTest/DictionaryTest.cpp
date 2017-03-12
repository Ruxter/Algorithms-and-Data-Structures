#include <gtest/gtest.h>
#include "DictionaryTest.h"
#include "../../ADSLibrary/DataStructures/CollectionsGenerics/Dictionary/Dictionary.h"

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
	EXPECT_EQ(true, dic->IsEmpty());
	dic->Insert(50, 1000); //103
	dic->Insert(152, 2000); //45
	dic->Insert(457, 3000); //23
	dic->Insert(12, 40000); //89
	dic->Insert(488, 5000); //50
	dic->Insert(3565, 1000); //71
	dic->Insert(88552, 1000); //3
	EXPECT_EQ(false, dic->IsEmpty());
	dic->Insert(120, 1000); //13
	dic->Insert(4, 1000); //81
	dic->Insert(5, 1000); //64
	dic->Insert(6, 1000); //115
	dic->Insert(896, 1000); //52
	dic->Insert(756, 1000); //43
	dic->Insert(2443, 1000); //33
	dic->Insert(8566, 1000); //120
	dic->Insert(257, 1000); //79
	dic->Insert(4, 2000); //81
	EXPECT_EQ(false, dic->IsEmpty());
	EXPECT_EQ(16, dic->Count());
	EXPECT_EQ(2000, dic->Get(4)); 
	EXPECT_EQ(1000, dic->Get(257));
	EXPECT_EQ(2000, dic->Get(152));
	dic->Remove(257);
	EXPECT_EQ(-1, dic->Get(257));

	//dic->Report();	
}

TEST_F(DictionaryOOPTemplate, DictionarOOPTemplateTestString)
{
	dic2->Insert("Neco", 1000);
	dic2->Insert("Neco2", 4000);
	
	EXPECT_EQ(1000, dic2->Get("Neco"));

	EXPECT_EQ(-1, dic2->Get("Neconeco"));

	//dic2->Report();
}

TEST_F(DictionaryOOPTemplate, DictionarOOPTemplateTest2)
{
	dic->Insert(1, 1000);
	dic->Insert(2, 2000);
	dic->Insert(6, 6000);
	dic->Insert(8, 8000);
	dic->Insert(10, 10000);
	dic->Insert(125, 125000);
	dic->Insert(365, 365000);
	dic->Insert(89, 89000);

	EXPECT_EQ(6000, dic->Get(6));
	EXPECT_EQ(365000, dic->Get(365));
	EXPECT_EQ(8, dic->Count());

	dic->Report();
}


DictionaryTest::DictionaryTest()
{
}


DictionaryTest::~DictionaryTest()
{
}