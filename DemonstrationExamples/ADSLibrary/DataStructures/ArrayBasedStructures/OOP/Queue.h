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
				 * \brief Fronta implementovaná v poli s využitím %OOP
				 *
				 * Implementace fronty v poli jako kruhový buffer.
				 * Implementace v poli znamená, že ukazatel je v tomto pøípadì realizován jako èíslo typu int
				 * a ukazatel je tudíž bìžný index v poli.
				 * 
				 */
				class Queue
				{
				public:

					/**
					 * Konstruktor. Velikost fronty bude nastavena na výchozí velikost.
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
					 * Vložení prvku na konec fronty.
					 *
					 * @param X Vkládaný prvek
					 */
					void Enqueue(const int X);

					/**
					 * Vyjmutí prvku z èela fronty.
					 *
					 * @return Prvek z hlavy fronty
					 */
					int Dequeue();

					/**
					 * Prvek na èele fronty.
					 * Prvek není z èela fronty odstranìn, jedná se o nedestruktivní variantu metody #Dequeue
					 *
					 * @return Prvek z hlavy fronty
					 */
					int Peek();

					/**
					 * Test je-li fronta prázdná.
					 *
					 * @return Funkce vrací true pokud je fronta prázdná, jinak false.
					 */
					bool IsEmpty();

					/**
					 * Test je-li fronta plná, tj. nelze vložit další prvek.
					 *
					 * @return Funkce vrací true pokud je fronta plná, jinak false
					 */
					bool IsFull();

					/**
					 * Smazání celého obsahu fronty.
					 */
					void Clear();
					
					/**
					 * Pomocná funkce, která zobrazuje vnitøní strukturu fronty.
					 */
					void Report();

				private:
					/**
					 * Velikost fronty.
					 */
					int QueueSize;

					/**
					 * Pole obsahující data uložená do fronty.
					 */
					int* Items;

					/**
					 * Hlava fronty tj. ukazatel na první prvek fronty v poli {@link #mData\endlink}.
					 */
					int Head;

					/**
					 * Ocas fronty tj. ukazatel na první volný prvek za koncem fronty v poli {@link #mData\endlink}.
					 */
					int Tail;

					/**
					 * Výchozí (default) velikost fronty.
					 */
					const int DefaultQueueSize = 5;
				};
			}
		}
	}
}