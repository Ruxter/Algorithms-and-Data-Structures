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
				 * \brief Seznam implementovan� pomoc� spojov�ch struktur s vyu�it�m %OOP
				 *
				 * Implementace obousm�rn�ho seznamu pomoc� spojov�ch struktur.
				 * V seznamu je implementov�n jednoduch� iter�tor.
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
					 * Smaz�n� cel�ho seznamu.
					 */
					void Clear();

					/**
					 * Vlo�en� prvku do seznamu. Prvek je vlo�en p�ed sou�asnou hlavu seznamu tj. stane se novou hlavou seznamu.
					 * @param X Vkl�dan� prvek
					 */
					void Insert(const int X);

					/**
					 * Odebr�n� prvku ze seznamu. Prvek X je nejprve v seznamu nalezen a pot� je odpov�daj�c� polo�ka ze seznamu vymaz�na.
					 * @param X Odeb�ran� prvek
					 */
					void Delete(const int X);

					/**
					 * Hled�n� prvku v seznamu.
					 * @param X Hledan� prvek
					 * @return Funkce vrac� true v p��pad�, �e je prvek X nalezen, jinak vrac� false.
					 */
					bool Search(const int X);

					/**
					 * Test je-li seznam pr�zdn�.
					 * @return Funkce vrac� true pokud je seznam pr�zdn�, jinak false.
					 */
					bool IsEmpty();

					/**
					 * Funkce vrac� po�et prvk� v seznamu.
					 * @return Po�et prvk� v seznamu.
					 */
					int Count();

					/**
					 * Reset iter�toru. Ukazatel na aktu�ln� polo�ku seznamu bude ukazovat na hlavu seznamu.
					 */
					void Reset();

					/**
					 * Test ukon�en� �innosti iter�toru.
					 * @return Funkce vrac� true pokud je iterace seznamem ukon�ena, jinak false.
					 */
					bool IsEnd();

					/**
					 * Posun ukazatele aktu�ln� polo�ky na dal�� polo�ku v seznamu.
					 */
					void MoveNext();

					/**
					 * Vr�cen� prvku z aktu�ln� polo�ky seznamu p�i iteraci.
					 * @return Funkce vrac� prvek z aktu�ln� polo�ky seznamu p�i iteraci.
					 */
					int Current();

					/**
					 * Pomocn� funkce, kter� zobrazuje vnit�n� strukturu seznamu.
					 */
					void Report();

				private:
					/**
					 * \brief Struktura reprezentuj�c� polo�ku v seznamu.
					 */
					struct ListItem
					{
						/**
						 * Hodnota obsa�en� v polo�ce.
						 */
						int Value;
						/**
						 * Ukazatel na p�edchoz� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu NULL.
						 */
						ListItem* Prev;
						/**
						 * Ukazatel na n�sleduj�c�  polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu NULL.
						 */
						ListItem* Next;
					};

					/**
					 * Hlava seznamu tj. ukazatel na prvn� polo�ku seznamu.
					 */
					ListItem* mHead;

					/**
					 * Ukazatel na aktu�ln� polo�ku p�i iteraci seznamem.
					 */
					ListItem* mCurrent;
				};
			}
		}
	}
}