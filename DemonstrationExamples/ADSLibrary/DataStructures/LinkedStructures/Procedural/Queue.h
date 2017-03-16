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
			namespace Procedural
			{
				/**
				 * \brief Struktura reprezentující položku ve frontì {@link #ADSLibrary::DataStructures::LinkedStructures::Procedural::Queue}
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
				 * \brief Fronta implementovaná pomocí spojových struktur procedurálním zpùsobem.
				 */
				struct Queue
				{
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

				/**
				 * Inicializace fronty.
				 *
				 * @param Q Inicializovaná fronta
				 */
				void Init(Queue& Q);

				/**
				 * Vložení prvku na konec fronty.
				 *
				 * @param Q Fronta
				 * @param X Vkládaný prvek
				 */
				void Enqueue(Queue& Q, const int X);

				/**
				 * Odebrání prvku z èela fronty.
				 *
				 * @param Q Fronta
				 * @return Prvek z èela fronty
				 */
				int Dequeue(Queue& Q);

				/**
				 * Prvek na èele fronty.
				 * Prvek není z èela fronty odstranìn, jedná se o nedestruktivní variantu metody #Dequeue
				 *
				 * @param Q Fronta
				 * @return Prvek z èela fronty
				 */
				int Peek(Queue& Q);

				/**
				 * Test, je-li fronta prázdná.
				 *
				 * @param Q Fronta
				 * @return Funkce vrací true pokud je fronta prázdná, jinak false.
				 */
				bool IsEmpty(const Queue& Q);

				/**
				 * Smazání celého obsahu fronty.
				 *
				 * @param Q Fronta
				 */
				void Clear(Queue& Q);

				/**
				 * Pomocná funkce, která zobrazuje vnitøní strukturu fronty.
				 *
				 * @param Q Fronta
				 */
				void Report(const Queue& Q);
			}
		}
	}
}