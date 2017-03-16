#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				/**
				 * Implementace binárního vyhledávacího stromu.
				 * Strom je implementován jako nevyvážený, tudíž mùže zdegenerovat do seznamu.
				 * Ve stromu je maximálnì využito rekurze, veøejné metody tvoøí vìtšinou jen "obálku" pro volání privátních rekurzívních metod.
				 * Tyto veøejné "obálky" jsou proto implementovány jako inline.
				 */
				class BinarySearchTree
				{
				public:
					/**
					 * Konstruktor.
					 */
					BinarySearchTree();

					/**
					 * Destruktor.
					 */
					~BinarySearchTree();

					/**
					 * Vložení klíèe do stromu.
					 * @param Key Vkládaný klíè
					 */
					void Insert(const string Key);

					/**
					 * Odebrání klíèe ze stromu.
					 * @param Key Odebíraný klíè
					 */
					void Delete(const string Key);

					/**
					 * Hledání klíèe ve stromu s využitím rekurze.
					 * @param Key Hledaný klíè
					 * @return Funkce vrací true v pøípadì, že je prvek Key nalezen, jinak vrací false.
					 */
					bool Search(const string Key) const;

					/**
					 * Hledání prvku ve stromu s využitím cyklu.
					 * @param Key Hledaný klíè
					 * @return Funkce vrací true v pøípadì, že je klíè Key nalezen, jinak vrací false.
					 */
					bool SearchIterative(const string Key) const;

					/**
					 * Smazání celého stromu.
					 */
					void Clear();

					/**
					 * Test je-li strom prázdný.
					 * @return Funkce vrací true pokud je seznam prázdný, jinak false.
					 */
					bool IsEmpty() const;

					/**
					 * Funkce vrací poèet uzlù ve stromu.
					 * @return Poèet uzlù ve stromu.
					 */
					int Count() const;

					/**
					 * Prùchod stromem zpùsobem in order. Metoda volá privátní demostraèní funkci DoSomeAction.
					 */
					void InorderTraversal();

					/**
					 * Prùchod stromem zpùsobem pre order. Metoda volá privátní demostraèní funkci DoSomeAction.
					 */
					void PreorderTraversal();

					/**
					 * Prùchod stromem zpùsobem post order. Metoda volá privátní demostraèní funkci DoSomeAction.
					 */
					void PostorderTraversal();

					/**
					 * Výpis interní struktury stromu.
					 * Strom je vypisován po "patrech", vždy je vypsán nejdøíve koøen stromu, pak celý jeho levý podstrom a pak pravý podstrom.
					 * Jednotlivá "patra" jsou odsazována.
					 */
					void ReportStructure() const;


					/**
					 * Deklarace spøátelených tøíd, které implementují iterátory.
					 * V tomto príkladì jsou iterátory implementovány oddìlenì, tudíž lze používat více iterátorù pro jeden strom souèasnì. Veškerá data nutná pro iterování skrz strom si uchovává iterátor.
					 * Deklarace tìchto tøíd jako spøátelených tøíd znamená, že tyto tøídy mají pøístup k privátním èlenùm tøídy BinarySearchTree, ale souèasnì není nutné z tìchto privátních èlenù nic zveøejòovat.
					 */
					friend class BinaryTreeIteratorBase;
					friend class BinaryTreeIterator;
					friend class BinaryTreeReverseIterator;

				private:
					/**
					 * Struktura reprezentující uzel ve stromu.
					 */
					struct Node
					{
						/**
						 * Klíè obsažený v uzlu.
						 */
						string Key;
						/**
						 * Ukazatel na levý podstrom.
						 */
						Node* Left;
						/**
						 * Ukazatel na pravý podstrom.
						 */
						Node* Right;
					};

					/**
					 * Rekurzívní metoda pro vkládání klíèe do stromu.
					 * @param p Aktuální uzel stromu.
					 * @param Key Vkládaný klíè.
					 */
					void InternalInsert(Node*& p, const string Key);

					/**
					 * Rekurzívní metoda pro smazání klíèe ze stromu.
					 * @param p Aktuální uzel stromu.
					 * @param Key Odebíraný klíè.
					 */
					void InternalDelete(Node*& p, const string Key);

					/**
					 * Rekurzívní metoda pro smazání klíèe ze stromu, uzel q má dva potomky, hledáme nejpravìjšího potomka z levého podstromu uzlu q.
					 * Jinak øeèeno hledáme nejbližší menší klíè.
					 * @param p Aktuální uzel stromu.
					 * @param q Uzel který se bude rušit.
					 */
					void InternalDeleteRightmostFromLeftSubtree(Node*& r, Node*& q);

					/**
					 * Rekurzívní metoda pro hledání klíèe ze stromu.
					 * @param p Aktuální uzel stromu.
					 * @param Key Hledaný klíè.
					 */
					bool InternalSearch(const Node* p, const string Key) const;

					/**
					 * Rekurzívní metoda pro postupné smazání celého stromu.
					 * @param p Aktuální uzel stromu.
					 */
					void InternalClear(const Node* p);

					/**
					 * Rekurzívní metoda pro poèítání uzlù ve stromu.
					 * @param p Aktuální uzel stromu.
					 * @return Funkce vrací poèet uzlù ve stromu s koøenem p.
					 */
					int InternalCount(const Node* p) const;

					/**
					 * Rekurzívní metoda pro prùchod stromem zpùsobem in order.
					 * @param p Aktuální uzel stromu.
					 */
					void InternalInorderTraversal(Node* p);

					/**
					 * Rekurzívní metoda pro prùchod stromem zpùsobem pre order.
					 * @param p Aktuální uzel stromu.
					 */
					void InternalPreorderTraversal(Node* p);

					/**
					 * Rekurzívní metoda pro prùchod stromem zpùsobem post order.
					 * @param p Aktuální uzel stromu.
					 */
					void InternalPostorderTraversal(Node* p);

					/**
					 * Rekurzívní metoda pro vypisování interní struktury stromu.
					 * @param p Aktuální uzel stromu.
					 * @param Indentation Odsazení od levého okraje, poèet tabulátorù.
					 */
					void InternalReportStructure(Node* p, const int Indentation) const;

					/**
					 * Metoda demonstruje akci provádìnou s uzlem pøi prùchodu stromem. V tomto pøípadì vypisuje klíè na standardní výstup.
					 * @param p Aktuální uzel stromu
					 */
					void DoSomeAction(Node* p) const;

					/**
					 * Ukazatel na koøen stromu.
					 */
					Node* mRoot;
				};


				inline BinarySearchTree::BinarySearchTree()
				{
					mRoot = NULL;
				}

				inline BinarySearchTree::~BinarySearchTree()
				{
					Clear();
				}

				inline void BinarySearchTree::Insert(const string Key)
				{
					InternalInsert(mRoot, Key);
				}

				inline void BinarySearchTree::Delete(const string Key)
				{
					InternalDelete(mRoot, Key);
				}

				inline bool BinarySearchTree::Search(const string Key) const
				{
					return InternalSearch(mRoot, Key);
				}

				inline void BinarySearchTree::Clear()
				{
					InternalClear(mRoot);
					mRoot = NULL;
				}

				inline bool BinarySearchTree::IsEmpty() const
				{
					return mRoot == NULL;
				}

				inline int BinarySearchTree::Count() const
				{
					return InternalCount(mRoot);
				}

				inline void BinarySearchTree::InorderTraversal()
				{
					InternalInorderTraversal(mRoot);
				}

				inline void BinarySearchTree::PreorderTraversal()
				{
					InternalPreorderTraversal(mRoot);
				}

				inline void BinarySearchTree::PostorderTraversal()
				{
					InternalPostorderTraversal(mRoot);
				}

				inline void BinarySearchTree::ReportStructure() const
				{
					InternalReportStructure(mRoot, 0);
				}
			}
		}
	}
}
