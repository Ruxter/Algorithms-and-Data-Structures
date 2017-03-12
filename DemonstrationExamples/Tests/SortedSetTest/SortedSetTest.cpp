#include "SortedSetTest.h"
#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/CollectionsGenerics/Set/SortedSet.h"

struct SortedSetOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int> *set;
	ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<std::string> *set2;
	ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<std::string> *set4;
	ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int> *set3;
	ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int> *setout;
	ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<std::string> *setout2;

	SortedSetOOPTemplate()
	{
		set = new ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int>();
		set2 = new ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<std::string>();
		set4 = new ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<std::string>();
		set3 = new ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int>();
		setout = new ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<int>();
		setout2 = new ADSLibrary::DataStructures::CollectionsGenerics::Set::SortedSet<std::string>();
	}

	~SortedSetOOPTemplate()
	{
		delete set;
		delete set2;
		delete set3;
		delete set4;
		delete setout;
		delete setout2;
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

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateTest3)
{
	set->Add(40);
	set->Add(30);
	set->Add(50);
	set->Add(50);
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateIntersection)
{
	set->Add(10);
	set->Add(7);
	set->Add(4);
	set->Add(15);
	set->Add(5);
	set->Add(8);
	set->Add(11);
	set->Add(9);
	set->Add(14);
	set->Add(16);
	

	set3->Add(2);
	set3->Add(4);
	set3->Add(6);
	set3->Add(365);
	set3->Add(8);
	set3->Add(7);

	set->Intersect(set3, setout);
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateUnion)
{
	set->Add(1);
	set->Add(3);
	set->Add(5);


	set3->Add(1);
	set3->Add(2);
	set3->Add(4);

	set->Union(set3, setout);
}

TEST_F(SortedSetOOPTemplate, SortedSetOOPTemplateNotIntTest)
{
	set2->Add("A");
	set2->Add("B");
	set2->Add("C");

	set4->Add("Delta");
	set4->Add("E");
	set4->Add("Zed");

	set2->Union(set4, setout2);
}


SortedSetTest::SortedSetTest()
{
}


SortedSetTest::~SortedSetTest()
{
}