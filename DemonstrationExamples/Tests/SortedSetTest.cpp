#include "SortedSetTest.h"
#include <gtest/gtest.h>
#include "../ADSLibrary/DataStructures/CollectionsGenerics/Set/SortedSet.h"

struct SortedSetOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int> *set;

	SortedSetOOPTemplate()
	{
		set = new ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int>();
	}

	~SortedSetOOPTemplate()
	{
		delete set;
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

	set->Remove(50);
	
}


SortedSetTest::SortedSetTest()
{
}


SortedSetTest::~SortedSetTest()
{
}