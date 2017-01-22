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
				 * \brief Struktura reprezentuj�c� polo�ku v seznamu {@link #ADSLibrary::DataStructures::LinkedStructures::Procedural::List}
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
				 * \brief Seznam implementovan� pomoc� spojov�ch struktur procedur�ln�m zp�sobem
				 *
				 * Implementace obousm�rn�ho seznamu pomoc� spojov�ch struktur.
				 * V seznamu je implementov�n jednoduch� iter�tor.
				 *
				 * @author	Ji�� Dvorsk� <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				struct List
				{
					/**
					 * Hlava seznamu tj. ukazatel na prvn� polo�ku seznamu.
					 */
					ListItem* Head;
					/**
					 * Ukazatel na aktu�ln� polo�ku p�i iteraci seznamem.
					 */
					ListItem* Current;
				};

				/**
				 * Inicializace seznamu.
				 *
				 * @param L Inicializovan� seznam
				 */
				void Init(List& L);

				/**
				 * Smaz�n� cel�ho seznamu.
				 *
				 * @param L Seznam
				 */
				void Clear(List& L);

				/**
				 * Vlo�en� prvku do seznamu. Prvek je vlo�en p�ed sou�asnou hlavu seznamu tj. stane se novou hlavou seznamu.
				 *
				 * @param L Seznam
				 * @param X Vkl�dan� prvek
				 */
				void Insert(List& L, const int X);

				/**
				 * Odebr�n� prvku ze seznamu. Prvek X je nejprve v seznamu nalezen a pot� je odpov�daj�c� polo�ka ze seznamu vymaz�na.
				 *
				 * @param L Seznam
				 * @param X Odeb�ran� prvek
				 */
				void Delete(List& L, const int X);

				/**
				 * Hled�n� prvku v seznamu.
				 *
				 * @param L Seznam
				 * @param X Hledan� prvek
				 * @return Funkce vrac� true v p��pad�, �e je prvek X nalezen, jinak vrac� false.
				 */
				bool Search(const List& L, const int X);

				/**
				 * Test je-li seznam pr�zdn�.
				 *
				 * @param L Seznam
				 * @return Funkce vrac� true pokud je seznam pr�zdn�, jinak false.
				 */
				bool IsEmpty(const List& L);

				/**
				 * Funkce vrac� po�et prvk� v seznamu.
				 *
				 * @param L Seznam
				 * @return Po�et prvk� v seznamu.
				 */
				int Count(const List& L);

				/**
				 * Reset iter�toru. Ukazatel na aktu�ln� polo�ku seznamu bude ukazovat na hlavu seznamu.
				 *
				 * @param L Seznam
				 */
				void Reset(List& L);

				/**
				 * Test ukon�en� �innosti iter�toru.
				 *
				 * @param L Seznam
				 * @return Funkce vrac� true pokud je iterace seznamem ukon�ena, jinak false.
				 */
				bool IsEnd(const List& L);

				/**
				 * Posun ukazatele aktu�ln� polo�ky na dal�� polo�ku v seznamu.
				 *
				 * @param L Seznam
				 */
				void MoveNext(List& L);

				/**
				 * Vr�cen� prvku z aktu�ln� polo�ky seznamu p�i iteraci.
				 *
				 * @param L Seznam
				 * @return Funkce vrac� prvek z aktu�ln� polo�ky seznamu p�i iteraci.
				 */
				int Current(const List& L);

				/**
				 * Pomocn� funkce, kter� zobrazuje vnit�n� strukturu seznamu.
				 *
				 * @param L Seznam
				 */
				void Report(const List& L);
			}
		}
	}
}