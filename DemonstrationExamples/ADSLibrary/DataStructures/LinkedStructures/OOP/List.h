#pragma once

#include <cstdlib>
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
				 * \brief Seznam implementovaný pomocí spojových struktur s využitím %OOP
				 *
				 * Implementace obousmìrného seznamu pomocí spojových struktur.
				 * V seznamu je implementován jednoduchý iterátor.
				 */
				class List
				{
				public:
					/**
					 * Konstruktor
					 */
					List();

					/**
					 * Destruktor
					 */
					~List();

					/**
					 * Smazání celého seznamu.
					 */
					void Clear();

					/**
					 * Vložení prvku do seznamu. Prvek je vložen pøed souèasnou hlavu seznamu tj. stane se novou hlavou seznamu.
					 * @param X Vkládaný prvek
					 */
					void Insert(const int X);

					/**
					 * Odebrání prvku ze seznamu. Prvek X je nejprve v seznamu nalezen a poté je odpovídající položka ze seznamu vymazána.
					 * @param X Odebíraný prvek
					 */
					void Delete(const int X);

					/**
					 * Hledání prvku v seznamu.
					 * @param X Hledaný prvek
					 * @return Funkce vrací true v pøípadì, že je prvek X nalezen, jinak vrací false.
					 */
					bool Search(const int X);

					/**
					 * Test je-li seznam prázdný.
					 * @return Funkce vrací true pokud je seznam prázdný, jinak false.
					 */
					bool IsEmpty();

					/**
					 * Funkce vrací poèet prvkù v seznamu.
					 * @return Poèet prvkù v seznamu.
					 */
					int Count();

					/**
					 * Reset iterátoru. Ukazatel na aktuální položku seznamu bude ukazovat na hlavu seznamu.
					 */
					void Reset();

					/**
					 * Test ukonèení èinnosti iterátoru.
					 * @return Funkce vrací true pokud je iterace seznamem ukonèena, jinak false.
					 */
					bool IsEnd();

					/**
					 * Posun ukazatele aktuální položky na další položku v seznamu.
					 */
					void MoveNext();

					/**
					 * Vrácení prvku z aktuální položky seznamu pøi iteraci.
					 * @return Funkce vrací prvek z aktuální položky seznamu pøi iteraci.
					 */
					int Current();

					/**
					 * Pomocná funkce, která zobrazuje vnitøní strukturu seznamu.
					 */
					void Report();

				private:
					/**
					 * \brief Struktura reprezentující položku v seznamu.
					 */
					struct ListItem
					{
						/**
						 * Hodnota obsažená v položce.
						 */
						int Value;
						/**
						 * Ukazatel na pøedchozí položku. Pokud taková položka neexistuje ukazatel má hodnotu NULL.
						 */
						ListItem* Prev;
						/**
						 * Ukazatel na následující  položku. Pokud taková položka neexistuje ukazatel má hodnotu NULL.
						 */
						ListItem* Next;
					};

					/**
					 * Hlava seznamu tj. ukazatel na první položku seznamu.
					 */
					ListItem* mHead;

					/**
					 * Ukazatel na aktuální položku pøi iteraci seznamem.
					 */
					ListItem* mCurrent;
				};
			}
		}
	}
}