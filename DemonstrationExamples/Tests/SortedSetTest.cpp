#include "SortedSetTest.h"
#include <gtest/gtest.h>
#include "../ADSLibrary/DataStructures/CollectionsGenerics/Set/SortedSet.h"

struct SortedSetOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int> *set;
	ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<std::string> *set2;

	SortedSetOOPTemplate()
	{
		set = new ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int>();
		set2 = new ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<std::string>();
	}

	~SortedSetOOPTemplate()
	{
		delete set;
		delete set2;
	}
};
TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateTest)
{
	EXPECT_EQ(true, set->IsEmpty());
	EXPECT_EQ(false, set->Contains(4));
	set->Add(5);
	set->Add(4);
	set->Add(6);
	set->Add(3);
	set->Add(7);
	EXPECT_EQ(true, set->Contains(4));
	EXPECT_EQ(5, set->Size());
	EXPECT_EQ(false, set->IsEmpty());
	set->Clear();
	EXPECT_EQ(true, set->IsEmpty());	
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateTestOrders)
{
	set->Add(30);
	set->Add(10);
	set->Add(20);
	set->Add(40);
	set->Add(50);

	set->InOrder();
	std::cout << "\n";
	set->PreOrder();
	std::cout << "\n";
	set->PostOrder();
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateTestRemove)
{
	set->Add(50);
	set->Add(40);
	set->Add(45);
	set->Add(42);
	set->Add(35);
	set->Add(55);
	set->Add(52);
	set->Add(100);
	set->Add(72);
	set->Add(37);
	set->Add(34);
	set->Add(101);

	set->Remove(40);
	EXPECT_EQ(11, set->Size());
	EXPECT_EQ(false, set->Contains(40));
	EXPECT_EQ(true, set->Contains(50));
	set->Clear();
	EXPECT_EQ(true, set->IsEmpty());
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateTestRemove2)
{
	set->Add(50);
	set->Add(40);
	set->Add(45);
	set->Add(42);
	set->Add(35);
	set->Add(55);
	set->Add(52);
	set->Add(100);
	set->Add(72);
	set->Add(37);
	set->Add(34);
	set->Add(101);

	set->Remove(50);
	set->Remove(55);

	set->Add(51);
	set->Add(48);
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateNotIntTest)
{
	set2->Add("M");
	set2->Add("G");
	set2->Add("R");
	set2->Add("B");
	set2->Add("I"); 
	set2->Add("H");
	set2->Add("X");

	set2->Remove("M");
}


SortedSetTest::SortedSetTest()
{
}


SortedSetTest::~SortedSetTest()
{
}