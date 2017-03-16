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
				 * \brief Fronta implementovan� pomoc� spojov�ch struktur s vyu�it�m %OOP.
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
					 * Vlo�en� prvku na konec fronty.
					 *
					 * @param X Vkl�dan� prvek
					 */
					void Enqueue(const int X);

					/**
					 * Odebr�n� prvku z �ela fronty.
					 *
					 * @return Prvek z �ela fronty
					 */
					int Dequeue();

					/**
					 * Prvek na �ele fronty.
					 * Prvek nen� z �ela fronty odstran�n, jedn� se o nedestruktivn� variantu metody #Dequeue
					 *
					 * @return Prvek z �ela fronty
					 */
					int Peek() const;

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

					/**
					 * Pomocn� funkce, kter� zobrazuje vnit�n� strukturu fronty.
					 */
					void Report() const;

				private:
					/**
					 * \brief Struktura reprezentuj�c� polo�ku ve front�.
					 */
					struct QueueItem
					{
						/**
						 * Hodnota obsa�en� v polo�ce.
						 */
						int Value;
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
			}
		}
	}
}
