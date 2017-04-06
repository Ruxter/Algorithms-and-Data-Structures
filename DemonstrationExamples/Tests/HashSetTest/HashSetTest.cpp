#include <gtest/gtest.h>
#include "HashSetTest.h"
#include "../../ADSLibrary/DataStructures/CollectionsGenerics/Set/HashSet.h"

/*
* Soubor sloužící k testování neuspoøádané množiny
*/

/*
* Pomocná struktura pro testování
*/
struct HashSetOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::CollectionsGenerics::Set::HashSet<int> *set;
	ADSLibrary::DataStructures::CollectionsGenerics::Set::HashSet<std::string> *set2;
	ADSLibrary::DataStructures::CollectionsGenerics::Set::HashSet<int> *set3;
	ADSLibrary::DataStructures::CollectionsGenerics::Set::HashSet<int> *setout;

	HashSetOOPTemplate()
	{
		set = new ADSLibrary::DataStructures::CollectionsGenerics::Set::HashSet<int>();
		set2 = new ADSLibrary::DataStructures::CollectionsGenerics::Set::HashSet<std::string>();
		set3 = new ADSLibrary::DataStructures::CollectionsGenerics::Set::HashSet<int>();
		setout = new ADSLibrary::DataStructures::CollectionsGenerics::Set::HashSet<int>();
	}

	~HashSetOOPTemplate()
	{
		delete set;
		delete set2;
		delete set3;
		delete setout;
	}
};

TEST_F(HashSetOOPTemplate, HashSetOOPTemplateTest)
{
	EXPECT_EQ(false, set->Contains(5));
	EXPECT_EQ(true, set->IsEmpty());
	set->Add(5);
	set->Add(6);
	set->Add(7);
	set->Add(8);
	set->Add(5);

	EXPECT_EQ(false, set->IsEmpty());
	EXPECT_EQ(4, set->Count());
	EXPECT_EQ(true, set->Contains(5));
	EXPECT_EQ(true, set->Contains(7));
	EXPECT_EQ(false, set->Contains(150));
	//set->Report();
}

TEST_F(HashSetOOPTemplate, HashSetOOPTemplateTest2)
{
	EXPECT_EQ(true, set->IsEmpty());
	EXPECT_EQ(false, set->Contains(5));
	set->Add(45);
	EXPECT_EQ(false, set->IsEmpty());
	set->Add(963);
	set->Add(5);
	set->Add(1);
	set->Add(172);
	set->Add(458);
	set->Add(69);
	set->Add(4);
	set->Add(6);
	set->Add(-1);
	EXPECT_EQ(10, set->Count());
	EXPECT_EQ(true, set->Contains(5));
	EXPECT_EQ(true, set->Contains(-1));
	EXPECT_EQ(true, set->Contains(69));
	EXPECT_EQ(false, set->Contains(150));

	set->Remove(69);
	EXPECT_EQ(false, set->Contains(69));
	EXPECT_EQ(false, set->IsEmpty());
	set->Add(69);
	set->Add(169);
	EXPECT_EQ(true, set->Contains(69));
	EXPECT_EQ(true, set->Contains(169));
	set->Report();
}

TEST_F(HashSetOOPTemplate, HashSetOOPTemplateTestIntersection)
{
	set->Add(1);
	set->Add(2);
	set->Add(3);
	set->Add(4);
	set->Add(5);
	set->Add(6);
	set->Add(7);
	set->Add(8);
	set->Add(9);
	set->Add(10);
	set->Add(365);

	set3->Add(2);
	set3->Add(4);
	set3->Add(6);
	set3->Add(365);
	set3->Add(8);
	set3->Add(10);
	
	set->Intersect(set3, setout);
	setout->Report();
	EXPECT_EQ(true, setout->Contains(365));
	EXPECT_EQ(6, setout->Count());
}

TEST_F(HashSetOOPTemplate, HashSetOOPTemplateTestUnion)
{
	set->Add(1);
	set->Add(2);
	set->Add(3);
	set->Add(4);
	set->Add(5);
	set->Add(6);
	set->Add(7);
	set->Add(8);
	set->Add(9);
	set->Add(10);

	set3->Add(2);
	set3->Add(4);
	set3->Add(6);
	set3->Add(8);
	set3->Add(10);
	set3->Add(125);
	set3->Add(365);
	set3->Add(89);

	set->Union(set3, setout);
	EXPECT_EQ(true, set3->Contains(365));
	setout->Report();
	EXPECT_EQ(true, setout->Contains(365));
	EXPECT_EQ(13, setout->Count());
}

HashSetTest::HashSetTest()
{
}


HashSetTest::~HashSetTest()
{
}