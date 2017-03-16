#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				/**
				 * \brief Fronta implementovaná pomocí spojových struktur s využitím %OOP.
				 */
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
					void Enqueue(const int X);

					/**
					 * Odebrání prvku z èela fronty.
					 *
					 * @return Prvek z èela fronty
					 */
					int Dequeue();

					/**
					 * Prvek na èele fronty.
					 * Prvek není z èela fronty odstranìn, jedná se o nedestruktivní variantu metody #Dequeue
					 *
					 * @return Prvek z èela fronty
					 */
					int Peek() const;

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

					/**
					 * Pomocná funkce, která zobrazuje vnitøní strukturu fronty.
					 */
					void Report() const;

				private:
					/**
					 * \brief Struktura reprezentující položku ve frontì.
					 */
					struct QueueItem
					{
						/**
						 * Hodnota obsažená v položce.
						 */
						int Value;
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
			}
		}
	}
}
