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
				 * \brief Fronta implementovan� v poli jako �ablona (template) %OOP
				 *
				 * Implementace fronty v poli jako kruhov� buffer.
				 * Implementace v poli znamen�, �e ukazatel je v tomto p��pad� realizov�n jako ��slo typu int
				 * a ukazatel je tud� b�n� index v poli.
				 *
				 * @author	Ji�� Dvorsk� <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				template <typename T>
				class Queue
				{
				public:
					/**
					 * Konstruktor. Velikost fronty bude nastavena na v�choz� velikost.
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
					 * Vlo�en� prvku na konec fronty.
					 *
					 * @param X Vkl�dan� prvek
					 */
					void Enqueue(const T X);

					/**
					 * Vyjmut� prvku z �ela fronty.
					 *
					 * @return Prvek z hlavy fronty
					 */
					T Dequeue();

					/**
					 * Prvek na �ele fronty.
					 * Prvek nen� z �ela fronty odstran�n, jedn� se o nedestruktivn� variantu metody #Dequeue
					 *
					 * @return Prvek z hlavy fronty
					 */
					T Peek();

					/**
					 * Test je-li fronta pr�zdn�.
					 *
					 * @return Funkce vrac� true pokud je fronta pr�zdn�, jinak false.
					 */
					bool IsEmpty();

					/**
					 * Test je-li fronta pln�, tj. nelze vlo�it dal�� prvek.
					 *
					 * @return Funkce vrac� true pokud je fronta pln�, jinak false.
					 */
					bool IsFull();

					/**
					 * Smaz�n� cel�ho obsahu fronty.
					 */
					void Clear();

				private:
					/**
					 * Velikost fronty.
					 */
					int QueueSize;

					/**
					 * Pole obsahuj�c� data ulo�en� do fronty.
					 */
					T* Items;

					/**
					 * Hlava fronty tj. ukazatel na prvn� prvek fronty v poli {@link #mData}.
					 */
					int Head;

					/**
					 * Ocas fronty tj. ukazatel na prvn� voln� prvek za koncem fronty v poli {@link #mData}.
					 */
					int Tail;

					/**
					 * V�choz� (default) velikost fronty.
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