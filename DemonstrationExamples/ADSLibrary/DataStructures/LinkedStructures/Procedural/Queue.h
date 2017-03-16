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
				 * \brief Struktura reprezentuj�c� polo�ku ve front� {@link #ADSLibrary::DataStructures::LinkedStructures::Procedural::Queue}
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
				 * \brief Fronta implementovan� pomoc� spojov�ch struktur procedur�ln�m zp�sobem.
				 */
				struct Queue
				{
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

				/**
				 * Inicializace fronty.
				 *
				 * @param Q Inicializovan� fronta
				 */
				void Init(Queue& Q);

				/**
				 * Vlo�en� prvku na konec fronty.
				 *
				 * @param Q Fronta
				 * @param X Vkl�dan� prvek
				 */
				void Enqueue(Queue& Q, const int X);

				/**
				 * Odebr�n� prvku z �ela fronty.
				 *
				 * @param Q Fronta
				 * @return Prvek z �ela fronty
				 */
				int Dequeue(Queue& Q);

				/**
				 * Prvek na �ele fronty.
				 * Prvek nen� z �ela fronty odstran�n, jedn� se o nedestruktivn� variantu metody #Dequeue
				 *
				 * @param Q Fronta
				 * @return Prvek z �ela fronty
				 */
				int Peek(Queue& Q);

				/**
				 * Test, je-li fronta pr�zdn�.
				 *
				 * @param Q Fronta
				 * @return Funkce vrac� true pokud je fronta pr�zdn�, jinak false.
				 */
				bool IsEmpty(const Queue& Q);

				/**
				 * Smaz�n� cel�ho obsahu fronty.
				 *
				 * @param Q Fronta
				 */
				void Clear(Queue& Q);

				/**
				 * Pomocn� funkce, kter� zobrazuje vnit�n� strukturu fronty.
				 *
				 * @param Q Fronta
				 */
				void Report(const Queue& Q);
			}
		}
	}
}