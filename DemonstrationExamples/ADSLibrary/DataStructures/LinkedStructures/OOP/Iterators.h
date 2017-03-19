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
				 * Abstraktní tøída reprezentující iterátor v binárním stromu.
				 * Iterátor je založen na využití zásobníku, který simuluje rekurzívní prùchod stromem Inorder.
				 * Na rozdíl od rekurze jsme ale v tomto pøípadì vykonávání prùchodu stromem schopni
				 * "pozdržet", vrátit data z aktuálního uzlu a potom pokraèovat dále v prùchodu stromem.
				 *
				 */
				class BinaryTreeIteratorBase
				{
				public:
					/**
					 * Konstruktor.
					 * @param Tree Strom, pøes který se bude iterovat
					 */
					BinaryTreeIteratorBase(BinarySearchTree* Tree);

					/**
					 * Reset iterátoru. Potomci, pøekrývající tuto metodu musí odpovídajícím zpùsobem inicializovat iterátor (naplnit zásobník uzly stromu)
					 */
					virtual void Reset() = 0;

					/**
					 * Test ukonèení èinnosti iterátoru. Tento test je pro všechny iterátory shodný.
					 * @return Funkce vrací true pokud je iterace stromem ukonèena, jinak false.
					 */
					bool IsEnd() const;

					/**
					 * Posun na další uzel stromu ve smìru iterace.
					 */
					virtual void MoveNext() = 0;

					/**
					 * Vrácení klíèe z aktuálního uzlu ve stromu.
					 * @return Funkce vrací klíè z aktuálního uzlu ve stromu.
					 */
					string Current() const;

				protected:
					/**
					 * Jednoduchá implementace zásobníku v poli pevné délky. Význam jednotlivých metod je popsán v pøíkladu specializovaném na implementaci zásobníku.
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
					 * Ukazatel na strom pøes který iterujeme.
					 */
					BinarySearchTree* mTree;

					/**
					 * Zásobník, kam jsou vkládány rozpracované uzly stromu.
					 * Na vrcholu zásobníku je vždy uzel stromu, který je pøipraven na zpracování tj. vrácení uživateli prostøednictvím metody Current. Po provedení metody MoveNext se uzly
					 * v zásobníku pøeskládají tak, aby opìt byl na vrcholu další prvek pøipravený na zpracování.
					 * Na konci iterace je zásobník prázdný.
					 */
					Stack mStack;
				};


				/**
				 * Tøída implementující iterátor v binárním stromu.
				 * Iterace probíhá podle uspoøádání prvkù ve stromu, jinak øeèeno prvky jsou iterovány od nejmenšího prvku ve stromu k nejvìtšímu.
				 */
				class BinaryTreeIterator : public BinaryTreeIteratorBase
				{
				public:
					/**
					 * Konstruktor.
					 * @param Tree Strom, pøes který se bude iterovat
					 */
					BinaryTreeIterator(BinarySearchTree* Tree);

					/**
					 * Reset iterátoru. Do zásobníku jsou naskládány uzly ležící na cestì od koøene k nejlevìjšímu uzlu.
					 */
					virtual void Reset();

					/**
					 * Posun na další uzel stromu ve smìru iterace. V tomto pøípadì si vyzvedneme již zpracovaný uzel na vrcholu zásobníku a hledáme nejlevìjší uzel v jeho pravém podstromu.
					 * Jinak øeèeno: v pravém podstromu jsou všechny prvky vìtší než ve vyzvednutém uzlu a pokud vezmeme jeho nejlevìjšího potomka, dostaneme se na uzel obsahující nejbližší vìtší prvek.
					 */
					virtual void MoveNext();
				};


				/**
				 * Tøída implementující iterátor v binárním stromu.
				 * Iterace probíhá proti smìru uspoøádání prvkù ve stromu, jinak øeèeno prvky jsou iterovány od nejvìtšího prvku ve stromu k nejmenšímu.
				 * Iterátor pracuje zrcadlovì vùèi iterátoru BinaryTreeIterator.
				 */
				class BinaryTreeReverseIterator : public BinaryTreeIteratorBase
				{
				public:
					/**
					 * Konstruktor.
					 * @param Tree Strom, pøes který se bude iterovat
					 */
					BinaryTreeReverseIterator(BinarySearchTree* Tree);

					/**
					 * Reset iterátoru. Do zásobníku jsou naskládány uzly ležící na cestì od koøene k nejpravìjšímu uzlu.
					 */
					virtual void Reset();

					/**
					 * Posun na další uzel stromu ve smìru iterace. V tomto pøípadì si vyzvedneme již zpracovaný uzel na vrcholu zásobníku a hledáme nejpravìjší uzel v jeho levém podstromu.
					 * Jinak øeèeno: v levém podstromu jsou všechny prvky menší než ve vyzvednutém uzlu a pokud vezmeme jeho nejpravìjšího potomka, dostaneme se na uzel obsahující nejbližší menší prvek.
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