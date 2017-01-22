#pragma once
#include <iostream>

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOPTemplate
			{
				/**
				 * \brief Zásobník implementovaný v poli jako šablona (template) %OOP
				 *
				 * @author	Jiøí Dvorský <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				template <typename T>
				class Stack
				{
				public:
					/**
					 * Konstruktor. Velikost zásobníku bude nastavena na výchozí velikost.
					 */
					Stack();

					/**
					 * Konstruktor. Velikost zásobníku lze zvolit.
					 *
					 * @param StackSize Velikost zásobníku
					 */
					Stack(const int StackSize);

					/**
					 * Destruktor
					 */
					~Stack();

					/**
					 * Vložení prvku na vrchol zásobníku.
					 *
					 * @param X Vkládaný prvek
					 */
					void Push(const T X);

					/**
					 * Odebrání prvku z vrcholu zásobníku.
					 *
					 * @return Prvek z vrcholu zásobníku
					 */
					T Pop();

					/**
					* Prvek na vrcholu zásobníku.
					* Prvek není ze zásobníku odstranìn, jedná se tedy o nedestruktivní variantu funkce #Pop.
					*
					* @return Prvek z vrcholu zásobníku
					*/
					T Top() const;

					/**
					 * Test je-li zásobník prázdný.
					 *
					 * @return Funkce vrací true pokud je zásobník prázdný, jinak false.
					 */
					bool IsEmpty() const;

					/**
					 * Test, je-li zásobník zaplnìný.
					 *
					 * @return Funkce vrací true pokud je zásobník zaplnìný, jinak false.
					 */
					bool IsFull() const;

					/**
					 * Smazání celého obsahu zásobníku.
					 */
					void Clear();

				private:
					/**
					 * Pole obsahující data uložená do zásobníku.
					 */
					T* Items;

					/**
					 * Velikost zásobníku.
					 */
					int StackSize;

					/**
					 * Ukazatel zásobníku.
					 */
					int StackPointer;

					/**
					 * Výchozí (default) velikost zásobníku.
					 */
					static const int DefaultStackSize = 100;
				};


				template <typename T> Stack<T>::Stack()
				{
					/*
					 * Uprava konstruktoru. StackSize.
					 */
					this->StackSize = DefaultStackSize;
					this->Items = new T[DefaultStackSize];
					this->StackPointer = 0;
				}

				template <typename T> Stack<T>::Stack(const int StackSize)
				{
					this->StackSize = StackSize <= 0 ? DefaultStackSize : StackSize;
					this->Items = new char[this->StackSize];
					this->StackPointer = 0;
				}

				template <typename T> Stack<T>::~Stack()
				{
					delete[] this->Items;
				}

				template <typename T> void Stack<T>::Push(const T X)
				{
					this->Items[this->StackPointer] = X;
					this->StackPointer += 1;
				}

				template <typename T> T Stack<T>::Pop()
				{
					this->StackPointer -= 1;
					return this->Items[this->StackPointer];
				}

				template <typename T> T Stack<T>::Top() const
				{					
					return this->Items[this->StackPointer - 1];
				}

				template <typename T> bool Stack<T>::IsEmpty() const
				{
					return this->StackPointer == 0;
				}

				template <typename T> bool Stack<T>::IsFull() const
				{
					return this->StackPointer == this->StackSize;
				}

				template <typename T> void Stack<T>::Clear()
				{
					this->StackPointer = 0;
				}
			}
		}
	}
}
