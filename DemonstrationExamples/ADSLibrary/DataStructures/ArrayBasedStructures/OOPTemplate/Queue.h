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
					int mQueueSize;

					/**
					 * Pole obsahující data uložená do fronty.
					 */
					T* mItems;

					/**
					 * Hlava fronty tj. ukazatel na první prvek fronty v poli {@link #mData}\endlink.
					 */
					int mHead;

					/**
					 * Ocas fronty tj. ukazatel na první volný prvek za koncem fronty v poli {@link #mData}\endlink.
					 */
					int mTail;

					/**
					 * Výchozí (default) velikost fronty.
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