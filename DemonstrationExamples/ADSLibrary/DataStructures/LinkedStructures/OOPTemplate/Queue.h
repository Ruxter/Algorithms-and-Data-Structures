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
				 * \brief Fronta implementovan� pomoc� spojov�ch struktur jako �ablona (template) %OOP.
				 */
				template <typename T>
				class Queue
				{
				public:
					/**
					 * Konstruktor
					 */
					Queue();

					/**
					 * Destuktor
					 */
					~Queue();

					/**
					 * Vlo�en� prvku na konec fronty.
					 *
					 * @param X Vkl�dan� prvek
					 */
					void Enqueue(const T X);

					/**
					 * Odebr�n� prvku z �ela fronty.
					 *
					 * @return Prvek z �ela fronty
					 */
					T Dequeue();

					/**
					 * Prvek na �ele fronty.
					 * Prvek nen� z �ela fronty odstran�n, jedn� se o nedestruktivn� variantu metody #Dequeue
					 *
					 * @return Prvek z �ela fronty
					 */
					T Peek() const;

					/**
					 * Test, je-li fronta pr�zdn�.
					 *
					 * @return Funkce vrac� true pokud je fronta pr�zdn�, jinak false.
					 */
					bool IsEmpty() const;

					/**
					 * Smaz�n� cel�ho obsahu fronty.
					 *
					 */
					void Clear();

				private:
					/**
					 * \brief Struktura reprezentuj�c� polo�ku ve front�.
					 */
					struct QueueItem
					{
						/**
						 * Hodnota obsa�en� v polo�ce.
						 */
						T Value;
						/**
						 * Ukazatel na p�edchoz� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu nullptr.
						 */
						QueueItem* Prev;
					};

					/**
					 * Hlava fronty. Hlava fronty ukazuje na prvn� prvek fronty.
					 * Prvn� prvek fronty naz�v�me tak� �elo fronty.
					 */
					QueueItem* Head;

					/**
					 * Ocas fronty. Tento ukazatel b�n� ukazuje na posledn� prvek ve front�.
					 */
					QueueItem* Tail;
				};


				template<typename T> Queue<T>::Queue()
				{
					this->Head = nullptr;
					this->Tail = nullptr;
				}

				template<typename T> Queue<T>::~Queue()
				{
					while (this->IsEmpty() && this->Head != nullptr)
					{
						this->Dequeue();
					}
					this->Head = nullptr;
					this->Tail = nullptr;
				}

				template<typename T> void Queue<T>::Enqueue(const T X)
				{
					QueueItem* n = new QueueItem();
					n->Value = X;
					n->Prev = nullptr;
					if (this->IsEmpty())
					{
						this->Head = n;
					}
					else
					{
						this->Tail->Prev = n;
					}
					this->Tail = n;
				}

				template<typename T> T Queue<T>::Dequeue()
				{
					QueueItem* d = this->Head;
					T result = d->Value;
					this->Head = this->Head->Prev;
					delete d;
					return result;
				}

				template<typename T> T Queue<T>::Peek() const
				{
					return this->Head->Value;
				}

				template<typename T> bool Queue<T>::IsEmpty() const
				{
					return this->Head == nullptr;
				}

				template<typename T> void Queue<T>::Clear()
				{
					while (this->IsEmpty())
					{
						this->Dequeue();
					}
					this->Head = nullptr;
					this->Tail = nullptr;
				}
			}
		}
	}
}
