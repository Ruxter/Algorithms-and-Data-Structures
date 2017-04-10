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
* Unit test LinkedStructures::OOPTemplate::AVLTree pro int
* Insert
* @param AVLTreeOOPTemplate n�zev struktury,
* @param AVLTreeOOPTemplateTestOfBalancingInsertAndDeleteRotation n�zev unit testu
*/
TEST_F(AVLTreeOOPTemplate, AVLTreeOOPTemplateTestOfBalancingInsertAndDeleteRotation)
{
	avltree->Insert(9);
	avltree->Insert(1);
	avltree->Insert(0);
	avltree->Insert(-1);
	avltree->Insert(5);
	avltree->Insert(2);	
	avltree->Insert(6);
	avltree->Insert(10);

	avltree->Delete(2);
}