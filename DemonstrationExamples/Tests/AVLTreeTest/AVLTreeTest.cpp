#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/LinkedStructures/OOPTemplate/AVLTree.h"

/*
* Soubor slou��c� k testov�n� obousm�rn�ho seznamu
*/

/*
* Pomocn� struktura pro testov�n�
*/
struct AVLTreeOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::AVLTree<int> *avltree;


	AVLTreeOOPTemplate()
	{
		avltree = new ADSLibrary::DataStructures::LinkedStructures::OOPTemplate::AVLTree<int>();
	}

	~AVLTreeOOPTemplate()
	{
		delete avltree;
	}

};

/*
* Unit test LinkedStructures::OOPTemplate::AVLTree pro int, pr�ce v debug mode, zda funguji rotace p�i Insert a Delete
* Tak� v�pis grafu
* Insert, Delete, InOrder, PreOrder, PostOrder, Contains, Size
* @param AVLTreeOOPTemplate n�zev struktury,
* @param AVLTreeOOPTemplateTestOfBalancingInsertAndDeleteRotation n�zev unit testu
*/
TEST_F(AVLTreeOOPTemplate, AVLTreeOOPTemplateTestOfBalancingInsertAndDeleteRotation)
{
	EXPECT_EQ(true, avltree->IsEmpty());
	EXPECT_EQ(false, avltree->Contains(2));
	avltree->Insert(9);
	EXPECT_EQ(false, avltree->IsEmpty());
	EXPECT_EQ(true, avltree->Contains(9));
	avltree->Insert(1);
	avltree->Insert(0);
	avltree->Insert(-1);
	avltree->Insert(5);
	avltree->Insert(2);	
	avltree->Insert(6);
	avltree->Insert(10);
	EXPECT_EQ(true, avltree->Contains(1));
	EXPECT_EQ(true, avltree->Contains(0));
	EXPECT_EQ(false, avltree->Contains(44));
	EXPECT_EQ(false, avltree->IsEmpty());

	avltree->InOrder(); std::cout << std::endl;
	avltree->PreOrder(); std::cout << std::endl;
	avltree->PostOrder(); std::cout << std::endl;

	avltree->Delete(2);
	EXPECT_EQ(false, avltree->IsEmpty());
	EXPECT_EQ(false, avltree->Contains(2));
}

/*
* Unit test LinkedStructures::OOPTemplate::AVLTree pro int, pr�ce v debug mode, zda funguji rotace p�i Insert a Delete
* Tak� v�pis grafu
* Insert, Delete, InOrder, PreOrder, PostOrder, Contains, Size
* @param AVLTreeOOPTemplate n�zev struktury,
* @param AVLTreeOOPTemplateTestOfBalancingInsertAndDeleteRotation2 n�zev unit testu
*/
TEST_F(AVLTreeOOPTemplate, AVLTreeOOPTemplateTestOfBalancingInsertAndDeleteRotation2)
{
	EXPECT_EQ(true, avltree->IsEmpty());
	EXPECT_EQ(0, avltree->Size());
	avltree->Insert(12);
	EXPECT_EQ(false, avltree->IsEmpty());
	EXPECT_EQ(true, avltree->Contains(12));
	avltree->Insert(4);
	avltree->Insert(30);
	avltree->Insert(2);
	avltree->Insert(8);
	avltree->Insert(20);
	EXPECT_EQ(6, avltree->Size());
	avltree->Insert(10);
	avltree->Insert(90);
	avltree->Insert(80);
	EXPECT_EQ(true, avltree->Contains(80));
	EXPECT_EQ(true, avltree->Contains(12));
	EXPECT_EQ(false, avltree->Contains(44));
	EXPECT_EQ(false, avltree->IsEmpty());

	avltree->InOrder(); std::cout << std::endl;
	avltree->PreOrder(); std::cout << std::endl;
	avltree->PostOrder(); std::cout << std::endl;

	avltree->Delete(2);
	EXPECT_EQ(false, avltree->IsEmpty());
	EXPECT_EQ(false, avltree->Contains(2));
	EXPECT_EQ(true, avltree->Contains(8));
}