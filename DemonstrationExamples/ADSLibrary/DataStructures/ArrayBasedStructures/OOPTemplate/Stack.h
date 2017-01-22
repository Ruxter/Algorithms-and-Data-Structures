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
				 * \brief Z�sobn�k implementovan� v poli jako �ablona (template) %OOP
				 *
				 * @author	Ji�� Dvorsk� <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				template <typename T>
				class Stack
				{
				public:
					/**
					 * Konstruktor. Velikost z�sobn�ku bude nastavena na v�choz� velikost.
					 */
					Stack();

					/**
					 * Konstruktor. Velikost z�sobn�ku lze zvolit.
					 *
					 * @param StackSize Velikost z�sobn�ku
					 */
					Stack(const int StackSize);

					/**
					 * Destruktor
					 */
					~Stack();

					/**
					 * Vlo�en� prvku na vrchol z�sobn�ku.
					 *
					 * @param X Vkl�dan� prvek
					 */
					void Push(const T X);

					/**
					 * Odebr�n� prvku z vrcholu z�sobn�ku.
					 *
					 * @return Prvek z vrcholu z�sobn�ku
					 */
					T Pop();

					/**
					* Prvek na vrcholu z�sobn�ku.
					* Prvek nen� ze z�sobn�ku odstran�n, jedn� se tedy o nedestruktivn� variantu funkce #Pop.
					*
					* @return Prvek z vrcholu z�sobn�ku
					*/
					T Top() const;

					/**
					 * Test je-li z�sobn�k pr�zdn�.
					 *
					 * @return Funkce vrac� true pokud je z�sobn�k pr�zdn�, jinak false.
					 */
					bool IsEmpty() const;

					/**
					 * Test, je-li z�sobn�k zapln�n�.
					 *
					 * @return Funkce vrac� true pokud je z�sobn�k zapln�n�, jinak false.
					 */
					bool IsFull() const;

					/**
					 * Smaz�n� cel�ho obsahu z�sobn�ku.
					 */
					void Clear();

				private:
					/**
					 * Pole obsahuj�c� data ulo�en� do z�sobn�ku.
					 */
					T* Items;

					/**
					 * Velikost z�sobn�ku.
					 */
					int StackSize;

					/**
					 * Ukazatel z�sobn�ku.
					 */
					int StackPointer;

					/**
					 * V�choz� (default) velikost z�sobn�ku.
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
