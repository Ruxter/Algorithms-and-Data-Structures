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
				 * Velikost kruhového bufferu ve kterém je fronta implementována.
				 */
				const int CircularBufferSize = 5;

				/**
				 * Maximální velikost fronty.
				 */
				const int MaxQueueSize = CircularBufferSize - 1;

				/**
				 * \brief Fronta implementovaná v poli jako kruhový buffer
				 *
				 * Implementace fronty v poli.
				 * Implementace v poli znamená, že ukazatel je v tomto pøípadì realizován jako èíslo typu int
				 * a ukazatel je tudíž bìžný index v poli.
				 *
				 * @author	Jiøí Dvorský <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				struct Queue
				{
					/**
					 * Pole, kruhový buffer, obsahující data uložená do fronty.
					 */
					int Items[CircularBufferSize];
					/**
					 * Hlava fronty. Hlava fronty ukazuje na první prvek fronty.
					 * První prvek fronty nazýváme také èelo fronty.
					 */
					int Head;
					/**
					 * Ocas fronty. Tento ukazatel bìžnì ukazuje na poslední prvek ve frontì.
					 * Pøi implementaci pomocí kruhového bufferu v poli, je výhodnìjší, aby tento
					 * ukazatel ukazoval až za poslední prvek ve frontì. Ocas fronty bude tak ukazovat
					 * na první volný prvek v poli {@link #Data}.
					 */
					int Tail;
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
				 * Test, je-li fronta plná, tj. nelze vložit další prvek.
				 *
				 * @param Q Fronta
				 * @return Funkce vrací true pokud je fronta plná, jinak false.
				 */
				bool IsFull(const Queue& Q);

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