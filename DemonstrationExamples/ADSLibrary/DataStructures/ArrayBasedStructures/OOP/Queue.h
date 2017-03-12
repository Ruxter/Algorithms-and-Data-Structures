#pragma once

#include <iomanip>

using namespace std;

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOP
			{
				/**
				 * \brief Fronta implementovan� v poli s vyu�it�m %OOP
				 *
				 * Implementace fronty v poli jako kruhov� buffer.
				 * Implementace v poli znamen�, �e ukazatel je v tomto p��pad� realizov�n jako ��slo typu int
				 * a ukazatel je tud� b�n� index v poli.
				 * 
				 */
				class Queue
				{
				public:

					/**
					 * Konstruktor. Velikost fronty bude nastavena na v�choz� velikost.
					 */
					Queue();

					/**
					 * Konstruktor.
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
					void Enqueue(const int X);

					/**
					 * Vyjmut� prvku z �ela fronty.
					 *
					 * @return Prvek z hlavy fronty
					 */
					int Dequeue();

					/**
					 * Prvek na �ele fronty.
					 * Prvek nen� z �ela fronty odstran�n, jedn� se o nedestruktivn� variantu metody #Dequeue
					 *
					 * @return Prvek z hlavy fronty
					 */
					int Peek();

					/**
					 * Test je-li fronta pr�zdn�.
					 *
					 * @return Funkce vrac� true pokud je fronta pr�zdn�, jinak false.
					 */
					bool IsEmpty();

					/**
					 * Test je-li fronta pln�, tj. nelze vlo�it dal�� prvek.
					 *
					 * @return Funkce vrac� true pokud je fronta pln�, jinak false
					 */
					bool IsFull();

					/**
					 * Smaz�n� cel�ho obsahu fronty.
					 */
					void Clear();
					
					/**
					 * Pomocn� funkce, kter� zobrazuje vnit�n� strukturu fronty.
					 */
					void Report();

				private:
					/**
					 * Velikost fronty.
					 */
					int QueueSize;

					/**
					 * Pole obsahuj�c� data ulo�en� do fronty.
					 */
					int* Items;

					/**
					 * Hlava fronty tj. ukazatel na prvn� prvek fronty v poli {@link #mData\endlink}.
					 */
					int Head;

					/**
					 * Ocas fronty tj. ukazatel na prvn� voln� prvek za koncem fronty v poli {@link #mData\endlink}.
					 */
					int Tail;

					/**
					 * V�choz� (default) velikost fronty.
					 */
					const int DefaultQueueSize = 5;
				};
			}
		}
	}
}