#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOPTemplate
			{
				/**
				 * \brief Z�sobn�k implementovan� pomoc� spojov�ch struktur jako �ablona (template) %OOP.
				 *
				 * @author	Ji�� Dvorsk� <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				template <typename T>
				class Stack
				{
				public:
					/**
					 * Konstruktor.
					 */
					Stack();

					/**
					 * Destruktor.
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
					 * Prvek nen� za z�sobn�ku odstran�n, jedn� se tedy o nedestruktivn� variantu funkce #Pop.
					 *
					 * @return Prvek z vrcholu z�sobn�ku
					 */
					T Top() const;

					/**
					 * Test, je-li z�sobn�k pr�zdn�.
					 *
					 * @return Funkce vrac� true pokud je z�sobn�k pr�zdn�, jinak false.
					 */
					bool IsEmpty() const;
				
					/**
					 * Smaz�n� cel�ho obsahu z�sobn�ku.
					 */
					void Clear();

					T getValue()
					{
						return Item.Value;
					}

				private:
					/**
					 * \brief Struktura reprezentuj�c� polo�ku v z�sobn�ku.
					 */
					struct StackItem
					{
						/**
						 * Hodnota obsa�en� v polo�ce.
						 */
						T Value;
						/**
						 * Ukazatel na p�edchoz� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu nullptr.
						 */
						StackItem* Prev;
					}Item;

					/**
					 * Ukazatel z�sobn�ku.
					 */
					StackItem* StackPointer;
				};


				template <typename T> Stack<T>::Stack()
				{
					this->StackPointer = nullptr;
				}

				template <typename T> Stack<T>::~Stack()
				{
					Clear();
				}

				template <typename T> void Stack<T>::Push(const T X)
				{
					StackItem* n = new StackItem();
					n->Value = X;
					n->Prev = this->StackPointer;
					this->StackPointer = n;
				}

				template <typename T> T Stack<T>::Pop()
				{
					StackItem* d = this->StackPointer;
					T result = d->Value;
					this->StackPointer = this->StackPointer->Prev;
					delete d;
					return result;
				}

				template <typename T> T Stack<T>::Top() const
				{
					return this->StackPointer->Value;
				}

				template <typename T> bool Stack<T>::IsEmpty() const
				{
					return this->StackPointer == nullptr;
				}

				template <typename T> void Stack<T>::Clear()
				{
					while (!this->IsEmpty())
					{
						this->Pop();
					}
				}
			}
		}
	}
}