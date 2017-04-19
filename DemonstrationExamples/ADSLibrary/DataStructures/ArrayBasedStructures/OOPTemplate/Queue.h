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
					int mQueueSize;

					/**
					 * Pole obsahuj�c� data ulo�en� do fronty.
					 */
					T* mItems;

					/**
					 * Hlava fronty tj. ukazatel na prvn� prvek fronty v poli {@link #mData}\endlink.
					 */
					int mHead;

					/**
					 * Ocas fronty tj. ukazatel na prvn� voln� prvek za koncem fronty v poli {@link #mData}\endlink.
					 */
					int mTail;

					/**
					 * V�choz� (default) velikost fronty.
					 */
					const int mDefaultQueueSize = 5;
				};


				template<typename T> Queue<T>::Queue()
				{
					this->mQueueSize = this->mDefaultQueueSize;
					this->mItems = new T[this->mDefaultQueueSize];
					this->mHead = 0;
					this->mTail = 0;
				}

				template<typename T> Queue<T>::Queue(const int QueueSize)
				{
					if (QueueSize <= 0)
					{
						this->mQueueSize = this->mDefaultQueueSize;
					}
					else
					{
						this->mQueueSize = QueueSize;
					}
					this->mItems = new T[this->mQueueSize];
					this->mHead = 0;
					this->mTail = 0;
				}

				template<typename T> Queue<T>::~Queue()
				{
					delete[] this->mItems;
				}

				template<typename T> void Queue<T>::Enqueue(const T X)
				{
					this->mItems[this->mTail] = X;
					this->mTail = (this->mTail + 1) % this->mQueueSize;
					this->mHead = (this->mHead) % this->mQueueSize;
				}

				template<typename T> T Queue<T>::Dequeue()
				{
					T x = this->mItems[this->mHead];
					this->mHead = (this->mHead + 1) % this->mQueueSize;
					return x;
				}

				template<typename T> T Queue<T>::Peek()
				{
					return this->mItems[this->mHead];
				}

				template<typename T> bool Queue<T>::IsEmpty()
				{
					return this->mHead == this->mTail;
				}

				template<typename T> bool Queue<T>::IsFull()
				{
					return this->mHead == (this->mTail) % this->mQueueSize;
				}

				template<typename T> void Queue<T>::Clear()
				{
					this->mHead = 0;
					this->mTail = 0;
				}
			}
		}
	}
}