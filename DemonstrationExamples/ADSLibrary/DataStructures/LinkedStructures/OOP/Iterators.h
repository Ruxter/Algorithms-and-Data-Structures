#pragma once
#include "BinarySearchTree.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				/**
				 * Abstraktn� t��da reprezentuj�c� iter�tor v bin�rn�m stromu.
				 * Iter�tor je zalo�en na vyu�it� z�sobn�ku, kter� simuluje rekurz�vn� pr�chod stromem Inorder.
				 * Na rozd�l od rekurze jsme ale v tomto p��pad� vykon�v�n� pr�chodu stromem schopni
				 * "pozdr�et", vr�tit data z aktu�ln�ho uzlu a potom pokra�ovat d�le v pr�chodu stromem.
				 *
				 */
				class BinaryTreeIteratorBase
				{
				public:
					/**
					 * Konstruktor.
					 * @param Tree Strom, p�es kter� se bude iterovat
					 */
					BinaryTreeIteratorBase(BinarySearchTree* Tree);

					/**
					 * Reset iter�toru. Potomci, p�ekr�vaj�c� tuto metodu mus� odpov�daj�c�m zp�sobem inicializovat iter�tor (naplnit z�sobn�k uzly stromu)
					 */
					virtual void Reset() = 0;

					/**
					 * Test ukon�en� �innosti iter�toru. Tento test je pro v�echny iter�tory shodn�.
					 * @return Funkce vrac� true pokud je iterace stromem ukon�ena, jinak false.
					 */
					bool IsEnd() const;

					/**
					 * Posun na dal�� uzel stromu ve sm�ru iterace.
					 */
					virtual void MoveNext() = 0;

					/**
					 * Vr�cen� kl��e z aktu�ln�ho uzlu ve stromu.
					 * @return Funkce vrac� kl�� z aktu�ln�ho uzlu ve stromu.
					 */
					string Current() const;

				protected:
					/**
					 * Jednoduch� implementace z�sobn�ku v poli pevn� d�lky. V�znam jednotliv�ch metod je pops�n v p��kladu specializovan�m na implementaci z�sobn�ku.
					 */
					class Stack
					{
					public:
						Stack();
						void Clear();
						void Push(BinarySearchTree::Node* n);
						BinarySearchTree::Node* Pop();
						BinarySearchTree::Node* Top() const;
						bool IsEmpty() const;
					private:
						static const int StackSize = 100;
						BinarySearchTree::Node* mData[StackSize];
						int mSP;
					};

					/**
					 * Ukazatel na strom p�es kter� iterujeme.
					 */
					BinarySearchTree* mTree;

					/**
					 * Z�sobn�k, kam jsou vkl�d�ny rozpracovan� uzly stromu.
					 * Na vrcholu z�sobn�ku je v�dy uzel stromu, kter� je p�ipraven na zpracov�n� tj. vr�cen� u�ivateli prost�ednictv�m metody Current. Po proveden� metody MoveNext se uzly
					 * v z�sobn�ku p�eskl�daj� tak, aby op�t byl na vrcholu dal�� prvek p�ipraven� na zpracov�n�.
					 * Na konci iterace je z�sobn�k pr�zdn�.
					 */
					Stack mStack;
				};


				/**
				 * T��da implementuj�c� iter�tor v bin�rn�m stromu.
				 * Iterace prob�h� podle uspo��d�n� prvk� ve stromu, jinak �e�eno prvky jsou iterov�ny od nejmen��ho prvku ve stromu k nejv�t��mu.
				 */
				class BinaryTreeIterator : public BinaryTreeIteratorBase
				{
				public:
					/**
					 * Konstruktor.
					 * @param Tree Strom, p�es kter� se bude iterovat
					 */
					BinaryTreeIterator(BinarySearchTree* Tree);

					/**
					 * Reset iter�toru. Do z�sobn�ku jsou naskl�d�ny uzly le��c� na cest� od ko�ene k nejlev�j��mu uzlu.
					 */
					virtual void Reset();

					/**
					 * Posun na dal�� uzel stromu ve sm�ru iterace. V tomto p��pad� si vyzvedneme ji� zpracovan� uzel na vrcholu z�sobn�ku a hled�me nejlev�j�� uzel v jeho prav�m podstromu.
					 * Jinak �e�eno: v prav�m podstromu jsou v�echny prvky v�t�� ne� ve vyzvednut�m uzlu a pokud vezmeme jeho nejlev�j��ho potomka, dostaneme se na uzel obsahuj�c� nejbli��� v�t�� prvek.
					 */
					virtual void MoveNext();
				};


				/**
				 * T��da implementuj�c� iter�tor v bin�rn�m stromu.
				 * Iterace prob�h� proti sm�ru uspo��d�n� prvk� ve stromu, jinak �e�eno prvky jsou iterov�ny od nejv�t��ho prvku ve stromu k nejmen��mu.
				 * Iter�tor pracuje zrcadlov� v��i iter�toru BinaryTreeIterator.
				 */
				class BinaryTreeReverseIterator : public BinaryTreeIteratorBase
				{
				public:
					/**
					 * Konstruktor.
					 * @param Tree Strom, p�es kter� se bude iterovat
					 */
					BinaryTreeReverseIterator(BinarySearchTree* Tree);

					/**
					 * Reset iter�toru. Do z�sobn�ku jsou naskl�d�ny uzly le��c� na cest� od ko�ene k nejprav�j��mu uzlu.
					 */
					virtual void Reset();

					/**
					 * Posun na dal�� uzel stromu ve sm�ru iterace. V tomto p��pad� si vyzvedneme ji� zpracovan� uzel na vrcholu z�sobn�ku a hled�me nejprav�j�� uzel v jeho lev�m podstromu.
					 * Jinak �e�eno: v lev�m podstromu jsou v�echny prvky men�� ne� ve vyzvednut�m uzlu a pokud vezmeme jeho nejprav�j��ho potomka, dostaneme se na uzel obsahuj�c� nejbli��� men�� prvek.
					 */
					virtual void MoveNext();
				};


				inline BinaryTreeIteratorBase::BinaryTreeIteratorBase(BinarySearchTree* Tree)
				{
					mTree = Tree;
				}

				inline bool BinaryTreeIteratorBase::IsEnd() const
				{
					return mStack.IsEmpty();
				}

				inline string BinaryTreeIteratorBase::Current() const
				{
					return mStack.Top()->Key;
				}

				inline BinaryTreeIteratorBase::Stack::Stack()
				{
					mSP = 0;
				}

				inline void BinaryTreeIteratorBase::Stack::Clear()
				{
					mSP = 0;
				}

				inline void BinaryTreeIteratorBase::Stack::Push(BinarySearchTree::Node* n)
				{
					mData[mSP] = n;
					mSP += 1;
				}

				inline BinarySearchTree::Node* BinaryTreeIteratorBase::Stack::Pop()
				{
					mSP -= 1;
					return mData[mSP];
				}

				inline BinarySearchTree::Node* BinaryTreeIteratorBase::Stack::Top() const
				{
					return mData[mSP - 1];
				}

				inline bool BinaryTreeIteratorBase::Stack::IsEmpty() const
				{
					return mSP == 0;
				}

				inline BinaryTreeIterator::BinaryTreeIterator(BinarySearchTree* Tree)
					: BinaryTreeIteratorBase(Tree)
				{
				}

				inline BinaryTreeReverseIterator::BinaryTreeReverseIterator(BinarySearchTree* Tree)
					: BinaryTreeIteratorBase(Tree)
				{
				}

			}
		}
	}
}