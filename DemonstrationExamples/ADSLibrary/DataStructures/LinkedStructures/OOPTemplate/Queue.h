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
				 * \brief Fronta implementovaná pomocí spojových struktur jako šablona (template) %OOP.
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
					 * Vložení prvku na konec fronty.
					 *
					 * @param X Vkládaný prvek
					 */
					void Enqueue(const T X);

					/**
					 * Odebrání prvku z èela fronty.
					 *
					 * @return Prvek z èela fronty
					 */
					T Dequeue();

					/**
					 * Prvek na èele fronty.
					 * Prvek není z èela fronty odstranìn, jedná se o nedestruktivní variantu metody #Dequeue
					 *
					 * @return Prvek z èela fronty
					 */
					T Peek() const;

					/**
					 * Test, je-li fronta prázdná.
					 *
					 * @return Funkce vrací true pokud je fronta prázdná, jinak false.
					 */
					bool IsEmpty() const;

					/**
					 * Smazání celého obsahu fronty.
					 *
					 */
					void Clear();

				private:
					/**
					 * \brief Struktura reprezentující položku ve frontì.
					 */
					struct QueueItem
					{
						/**
						 * Hodnota obsažená v položce.
						 */
						T Value;
						/**
						 * Ukazatel na pøedchozí položku. Pokud taková položka neexistuje ukazatel má hodnotu nullptr.
						 */
						QueueItem* Prev;
					};

					/**
					 * Hlava fronty. Hlava fronty ukazuje na první prvek fronty.
					 * První prvek fronty nazýváme také èelo fronty.
					 */
					QueueItem* Head;

					/**
					 * Ocas fronty. Tento ukazatel bìžnì ukazuje na poslední prvek ve frontì.
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
