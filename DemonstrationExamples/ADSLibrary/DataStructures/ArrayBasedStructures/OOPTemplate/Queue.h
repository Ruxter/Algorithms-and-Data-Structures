#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOPTemplate
			{
				/**
				 * \brief Fronta implementovaná v poli jako šablona (template) %OOP
				 *
				 * Implementace fronty v poli jako kruhový buffer.
				 * Implementace v poli znamená, že ukazatel je v tomto pøípadì realizován jako èíslo typu int
				 * a ukazatel je tudíž bìžný index v poli.
				 *
				 * @author	Jiøí Dvorský <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				template <typename T>
				class Queue
				{
				public:
					/**
					 * Konstruktor. Velikost fronty bude nastavena na výchozí velikost.
					 */
					Queue();

					/**
					 * Konstruktor
					 *
					 * @param QueueSize Velikost fronty
					 */
					Queue(const int QueueSize);

					/**
					 * Destruktor.
					 */
					~Queue();

					/**
					 * Vložení prvku na konec fronty.
					 *
					 * @param X Vkládaný prvek
					 */
					void Enqueue(const T X);

					/**
					 * Vyjmutí prvku z èela fronty.
					 *
					 * @return Prvek z hlavy fronty
					 */
					T Dequeue();

					/**
					 * Prvek na èele fronty.
					 * Prvek není z èela fronty odstranìn, jedná se o nedestruktivní variantu metody #Dequeue
					 *
					 * @return Prvek z hlavy fronty
					 */
					T Peek();

					/**
					 * Test je-li fronta prázdná.
					 *
					 * @return Funkce vrací true pokud je fronta prázdná, jinak false.
					 */
					bool IsEmpty();

					/**
					 * Test je-li fronta plná, tj. nelze vložit další prvek.
					 *
					 * @return Funkce vrací true pokud je fronta plná, jinak false.
					 */
					bool IsFull();

					/**
					 * Smazání celého obsahu fronty.
					 */
					void Clear();

				private:
					/**
					 * Velikost fronty.
					 */
					int QueueSize;

					/**
					 * Pole obsahující data uložená do fronty.
					 */
					T* Items;

					/**
					 * Hlava fronty tj. ukazatel na první prvek fronty v poli {@link #mData}.
					 */
					int Head;

					/**
					 * Ocas fronty tj. ukazatel na první volný prvek za koncem fronty v poli {@link #mData}.
					 */
					int Tail;

					/**
					 * Výchozí (default) velikost fronty.
					 */
					const int DefaultQueueSize = 5;
				};


				template<typename T> Queue<T>::Queue()
				{
					this->QueueSize = this->DefaultQueueSize;
					this->Items = new T[this->DefaultQueueSize];
					this->Head = 0;
					this->Tail = 0;
				}

				template<typename T> Queue<T>::Queue(const int QueueSize)
				{
					if (QueueSize <= 0)
					{
						this->QueueSize = this->DefaultQueueSize;
					}
					else
					{
						this->QueueSize = QueueSize;
					}
					this->Items = new T[this->QueueSize];
					this->Head = 0;
					this->Tail = 0;
				}

				template<typename T> Queue<T>::~Queue()
				{
					delete[] this->Items;
				}

				template<typename T> void Queue<T>::Enqueue(const T X)
				{
					this->Items[this->Tail] = X;
					this->Tail = (this->Tail + 1) % this->QueueSize;
					this->Head = (this->Head) % this->QueueSize;
				}

				template<typename T> T Queue<T>::Dequeue()
				{
					T x = this->Items[this->Head];
					this->Head = (this->Head + 1) % this->QueueSize;
					return x;
				}

				template<typename T> T Queue<T>::Peek()
				{
					return this->Items[this->Head];
				}

				template<typename T> bool Queue<T>::IsEmpty()
				{
					return this->Head == this->Tail;
				}

				template<typename T> bool Queue<T>::IsFull()
				{
					return this->Head == (this->Tail + 1) % this->QueueSize;
				}

				template<typename T> void Queue<T>::Clear()
				{
					this->Head = 0;
					this->Tail = 0;
				}
			}
		}
	}
}