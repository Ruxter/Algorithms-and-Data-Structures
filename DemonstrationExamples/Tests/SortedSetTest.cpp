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
	set->Insert(5);
	set->Insert(4);
	set->Insert(6);
	set->Insert(3);
	set->Insert(7);
	EXPECT_EQ(true, set->Contains(4));
	EXPECT_EQ(5, set->Size());
	EXPECT_EQ(false, set->IsEmpty());
	set->Clear();
	EXPECT_EQ(true, set->IsEmpty());	
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateTestOrders)
{
	set->Insert(30);
	set->Insert(10);
	set->Insert(20);
	set->Insert(40);
	set->Insert(50);

	set->InOrder();
	std::cout << "\n";
	set->PreOrder();
	std::cout << "\n";
	set->PostOrder();
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateTestRemove)
{
	set->Insert(50);
	set->Insert(40);
	set->Insert(45);
	set->Insert(42);
	set->Insert(35);
	set->Insert(55);
	set->Insert(52);
	set->Insert(100);
	set->Insert(72);
	set->Insert(37);
	set->Insert(34);
	set->Insert(101);

	set->Remove(40);
	EXPECT_EQ(11, set->Size());
	EXPECT_EQ(false, set->Contains(40));
	EXPECT_EQ(true, set->Contains(50));
	set->Clear();
	EXPECT_EQ(true, set->IsEmpty());
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateTestRemove2)
{
	set->Insert(50);
	set->Insert(40);
	set->Insert(45);
	set->Insert(42);
	set->Insert(35);
	set->Insert(55);
	set->Insert(52);
	set->Insert(100);
	set->Insert(72);
	set->Insert(37);
	set->Insert(34);
	set->Insert(101);

	set->Remove(50);
	set->Remove(55);

	set->Insert(51);
	set->Insert(48);
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateNotIntTest)
{
	set2->Insert("M");
	set2->Insert("G");
	set2->Insert("R");
	set2->Insert("B");
	set2->Insert("I"); 
	set2->Insert("H");
	set2->Insert("X");

	set2->Remove("M");
}


SortedSetTest::SortedSetTest()
{
}


SortedSetTest::~SortedSetTest()
{
}