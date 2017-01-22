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
			namespace Procedural
			{
				/**
				 * Velikost kruhov�ho bufferu ve kter�m je fronta implementov�na.
				 */
				const int CircularBufferSize = 5;

				/**
				 * Maxim�ln� velikost fronty.
				 */
				const int MaxQueueSize = CircularBufferSize - 1;

				/**
				 * \brief Fronta implementovan� v poli jako kruhov� buffer
				 *
				 * Implementace fronty v poli.
				 * Implementace v poli znamen�, �e ukazatel je v tomto p��pad� realizov�n jako ��slo typu int
				 * a ukazatel je tud� b�n� index v poli.
				 *
				 * @author	Ji�� Dvorsk� <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				struct Queue
				{
					/**
					 * Pole, kruhov� buffer, obsahuj�c� data ulo�en� do fronty.
					 */
					int Items[CircularBufferSize];
					/**
					 * Hlava fronty. Hlava fronty ukazuje na prvn� prvek fronty.
					 * Prvn� prvek fronty naz�v�me tak� �elo fronty.
					 */
					int Head;
					/**
					 * Ocas fronty. Tento ukazatel b�n� ukazuje na posledn� prvek ve front�.
					 * P�i implementaci pomoc� kruhov�ho bufferu v poli, je v�hodn�j��, aby tento
					 * ukazatel ukazoval a� za posledn� prvek ve front�. Ocas fronty bude tak ukazovat
					 * na prvn� voln� prvek v poli {@link #Data}.
					 */
					int Tail;
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
				 * Test, je-li fronta pln�, tj. nelze vlo�it dal�� prvek.
				 *
				 * @param Q Fronta
				 * @return Funkce vrac� true pokud je fronta pln�, jinak false.
				 */
				bool IsFull(const Queue& Q);

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