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
			namespace Procedural
			{
				/**
				 * \brief Struktura reprezentující položku v seznamu {@link #ADSLibrary::DataStructures::LinkedStructures::Procedural::List}
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
				 * \brief Seznam implementovaný pomocí spojových struktur procedurálním zpùsobem
				 *
				 * Implementace obousmìrného seznamu pomocí spojových struktur.
				 * V seznamu je implementován jednoduchý iterátor.
				 *
				 * @author	Jiøí Dvorský <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				struct List
				{
					/**
					 * Hlava seznamu tj. ukazatel na první položku seznamu.
					 */
					ListItem* Head;
					/**
					 * Ukazatel na aktuální položku pøi iteraci seznamem.
					 */
					ListItem* Current;
				};

				/**
				 * Inicializace seznamu.
				 *
				 * @param L Inicializovaný seznam
				 */
				void Init(List& L);

				/**
				 * Smazání celého seznamu.
				 *
				 * @param L Seznam
				 */
				void Clear(List& L);

				/**
				 * Vložení prvku do seznamu. Prvek je vložen pøed souèasnou hlavu seznamu tj. stane se novou hlavou seznamu.
				 *
				 * @param L Seznam
				 * @param X Vkládaný prvek
				 */
				void Insert(List& L, const int X);

				/**
				 * Odebrání prvku ze seznamu. Prvek X je nejprve v seznamu nalezen a poté je odpovídající položka ze seznamu vymazána.
				 *
				 * @param L Seznam
				 * @param X Odebíraný prvek
				 */
				void Delete(List& L, const int X);

				/**
				 * Hledání prvku v seznamu.
				 *
				 * @param L Seznam
				 * @param X Hledaný prvek
				 * @return Funkce vrací true v pøípadì, že je prvek X nalezen, jinak vrací false.
				 */
				bool Search(const List& L, const int X);

				/**
				 * Test je-li seznam prázdný.
				 *
				 * @param L Seznam
				 * @return Funkce vrací true pokud je seznam prázdný, jinak false.
				 */
				bool IsEmpty(const List& L);

				/**
				 * Funkce vrací poèet prvkù v seznamu.
				 *
				 * @param L Seznam
				 * @return Poèet prvkù v seznamu.
				 */
				int Count(const List& L);

				/**
				 * Reset iterátoru. Ukazatel na aktuální položku seznamu bude ukazovat na hlavu seznamu.
				 *
				 * @param L Seznam
				 */
				void Reset(List& L);

				/**
				 * Test ukonèení èinnosti iterátoru.
				 *
				 * @param L Seznam
				 * @return Funkce vrací true pokud je iterace seznamem ukonèena, jinak false.
				 */
				bool IsEnd(const List& L);

				/**
				 * Posun ukazatele aktuální položky na další položku v seznamu.
				 *
				 * @param L Seznam
				 */
				void MoveNext(List& L);

				/**
				 * Vrácení prvku z aktuální položky seznamu pøi iteraci.
				 *
				 * @param L Seznam
				 * @return Funkce vrací prvek z aktuální položky seznamu pøi iteraci.
				 */
				int Current(const List& L);

				/**
				 * Pomocná funkce, která zobrazuje vnitøní strukturu seznamu.
				 *
				 * @param L Seznam
				 */
				void Report(const List& L);
			}
		}
	}
}