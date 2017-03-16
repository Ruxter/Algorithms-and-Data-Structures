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
				 * Implementace bin�rn�ho vyhled�vac�ho stromu.
				 * Strom je implementov�n jako nevyv�en�, tud� m��e zdegenerovat do seznamu.
				 * Ve stromu je maxim�ln� vyu�ito rekurze, ve�ejn� metody tvo�� v�t�inou jen "ob�lku" pro vol�n� priv�tn�ch rekurz�vn�ch metod.
				 * Tyto ve�ejn� "ob�lky" jsou proto implementov�ny jako inline.
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
					 * Vlo�en� kl��e do stromu.
					 * @param Key Vkl�dan� kl��
					 */
					void Insert(const string Key);

					/**
					 * Odebr�n� kl��e ze stromu.
					 * @param Key Odeb�ran� kl��
					 */
					void Delete(const string Key);

					/**
					 * Hled�n� kl��e ve stromu s vyu�it�m rekurze.
					 * @param Key Hledan� kl��
					 * @return Funkce vrac� true v p��pad�, �e je prvek Key nalezen, jinak vrac� false.
					 */
					bool Search(const string Key) const;

					/**
					 * Hled�n� prvku ve stromu s vyu�it�m cyklu.
					 * @param Key Hledan� kl��
					 * @return Funkce vrac� true v p��pad�, �e je kl�� Key nalezen, jinak vrac� false.
					 */
					bool SearchIterative(const string Key) const;

					/**
					 * Smaz�n� cel�ho stromu.
					 */
					void Clear();

					/**
					 * Test je-li strom pr�zdn�.
					 * @return Funkce vrac� true pokud je seznam pr�zdn�, jinak false.
					 */
					bool IsEmpty() const;

					/**
					 * Funkce vrac� po�et uzl� ve stromu.
					 * @return Po�et uzl� ve stromu.
					 */
					int Count() const;

					/**
					 * Pr�chod stromem zp�sobem in order. Metoda vol� priv�tn� demostra�n� funkci DoSomeAction.
					 */
					void InorderTraversal();

					/**
					 * Pr�chod stromem zp�sobem pre order. Metoda vol� priv�tn� demostra�n� funkci DoSomeAction.
					 */
					void PreorderTraversal();

					/**
					 * Pr�chod stromem zp�sobem post order. Metoda vol� priv�tn� demostra�n� funkci DoSomeAction.
					 */
					void PostorderTraversal();

					/**
					 * V�pis intern� struktury stromu.
					 * Strom je vypisov�n po "patrech", v�dy je vyps�n nejd��ve ko�en stromu, pak cel� jeho lev� podstrom a pak prav� podstrom.
					 * Jednotliv� "patra" jsou odsazov�na.
					 */
					void ReportStructure() const;


					/**
					 * Deklarace sp��telen�ch t��d, kter� implementuj� iter�tory.
					 * V tomto pr�klad� jsou iter�tory implementov�ny odd�len�, tud� lze pou��vat v�ce iter�tor� pro jeden strom sou�asn�. Ve�ker� data nutn� pro iterov�n� skrz strom si uchov�v� iter�tor.
					 * Deklarace t�chto t��d jako sp��telen�ch t��d znamen�, �e tyto t��dy maj� p��stup k priv�tn�m �len�m t��dy BinarySearchTree, ale sou�asn� nen� nutn� z t�chto priv�tn�ch �len� nic zve�ej�ovat.
					 */
					friend class BinaryTreeIteratorBase;
					friend class BinaryTreeIterator;
					friend class BinaryTreeReverseIterator;

				private:
					/**
					 * Struktura reprezentuj�c� uzel ve stromu.
					 */
					struct Node
					{
						/**
						 * Kl�� obsa�en� v uzlu.
						 */
						string Key;
						/**
						 * Ukazatel na lev� podstrom.
						 */
						Node* Left;
						/**
						 * Ukazatel na prav� podstrom.
						 */
						Node* Right;
					};

					/**
					 * Rekurz�vn� metoda pro vkl�d�n� kl��e do stromu.
					 * @param p Aktu�ln� uzel stromu.
					 * @param Key Vkl�dan� kl��.
					 */
					void InternalInsert(Node*& p, const string Key);

					/**
					 * Rekurz�vn� metoda pro smaz�n� kl��e ze stromu.
					 * @param p Aktu�ln� uzel stromu.
					 * @param Key Odeb�ran� kl��.
					 */
					void InternalDelete(Node*& p, const string Key);

					/**
					 * Rekurz�vn� metoda pro smaz�n� kl��e ze stromu, uzel q m� dva potomky, hled�me nejprav�j��ho potomka z lev�ho podstromu uzlu q.
					 * Jinak �e�eno hled�me nejbli��� men�� kl��.
					 * @param p Aktu�ln� uzel stromu.
					 * @param q Uzel kter� se bude ru�it.
					 */
					void InternalDeleteRightmostFromLeftSubtree(Node*& r, Node*& q);

					/**
					 * Rekurz�vn� metoda pro hled�n� kl��e ze stromu.
					 * @param p Aktu�ln� uzel stromu.
					 * @param Key Hledan� kl��.
					 */
					bool InternalSearch(const Node* p, const string Key) const;

					/**
					 * Rekurz�vn� metoda pro postupn� smaz�n� cel�ho stromu.
					 * @param p Aktu�ln� uzel stromu.
					 */
					void InternalClear(const Node* p);

					/**
					 * Rekurz�vn� metoda pro po��t�n� uzl� ve stromu.
					 * @param p Aktu�ln� uzel stromu.
					 * @return Funkce vrac� po�et uzl� ve stromu s ko�enem p.
					 */
					int InternalCount(const Node* p) const;

					/**
					 * Rekurz�vn� metoda pro pr�chod stromem zp�sobem in order.
					 * @param p Aktu�ln� uzel stromu.
					 */
					void InternalInorderTraversal(Node* p);

					/**
					 * Rekurz�vn� metoda pro pr�chod stromem zp�sobem pre order.
					 * @param p Aktu�ln� uzel stromu.
					 */
					void InternalPreorderTraversal(Node* p);

					/**
					 * Rekurz�vn� metoda pro pr�chod stromem zp�sobem post order.
					 * @param p Aktu�ln� uzel stromu.
					 */
					void InternalPostorderTraversal(Node* p);

					/**
					 * Rekurz�vn� metoda pro vypisov�n� intern� struktury stromu.
					 * @param p Aktu�ln� uzel stromu.
					 * @param Indentation Odsazen� od lev�ho okraje, po�et tabul�tor�.
					 */
					void InternalReportStructure(Node* p, const int Indentation) const;

					/**
					 * Metoda demonstruje akci prov�d�nou s uzlem p�i pr�chodu stromem. V tomto p��pad� vypisuje kl�� na standardn� v�stup.
					 * @param p Aktu�ln� uzel stromu
					 */
					void DoSomeAction(Node* p) const;

					/**
					 * Ukazatel na ko�en stromu.
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
