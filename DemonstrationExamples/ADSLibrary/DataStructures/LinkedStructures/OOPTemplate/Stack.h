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
				 * \brief Zásobník implementovaný pomocí spojových struktur jako šablona (template) %OOP.
				 *
				 * @author	Jiøí Dvorský <jiri.dvorsky@vsb.cz>
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
					 * Prvek není za zásobníku odstranìn, jedná se tedy o nedestruktivní variantu funkce #Pop.
					 *
					 * @return Prvek z vrcholu zásobníku
					 */
					T Top() const;

					/**
					 * Test, je-li zásobník prázdný.
					 *
					 * @return Funkce vrací true pokud je zásobník prázdný, jinak false.
					 */
					bool IsEmpty() const;
				
					/**
					 * Smazání celého obsahu zásobníku.
					 */
					void Clear();

					T getValue()
					{
						return Item.Value;
					}

				private:
					/**
					 * \brief Struktura reprezentující položku v zásobníku.
					 */
					struct StackItem
					{
						/**
						 * Hodnota obsažená v položce.
						 */
						T Value;
						/**
						 * Ukazatel na pøedchozí položku. Pokud taková položka neexistuje ukazatel má hodnotu nullptr.
						 */
						StackItem* Prev;
					}Item;

					/**
					 * Ukazatel zásobníku.
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