#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace Procedural
			{
				/**
				 * \brief Struktura reprezentuj�c� polo�ku v z�sobn�ku {@link #ADSLibrary::DataStructures::LinkedStructures::Procedural::Stack}
				 */
				struct StackItem
				{
					/**
					 * Hodnota obsa�en� v polo�ce.
					 */
					char Value;
					/**
					 * Ukazatel na p�edchoz� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu nullptr.
					 */
					StackItem* Prev;
				};

				/**
				 * \brief Z�sobn�k implementovan� pomoc� spojov�ch struktur procedur�ln�m zp�sobem.
				 */
				struct Stack
				{
					/**
					 * Ukazatel z�sobn�ku
					 */
					StackItem* StackPointer;
				};

				/**
				 * Inicializace z�sobn�ku. Z�sobn�k je po inicializaci pr�zdn�.
				 *
				 * @param S Inicializovan� z�sobn�k
				 */
				void Init(Stack& S);

				/**
				 * Vlo�en� prvku na vrchol z�sobn�ku.
				 *
				 * @param S Z�sobn�k
				 * @param X Vkl�dan� prvek
				 */
				void Push(Stack& S, const char X);

				/**
				 * Odebr�n� prvku z vrcholu z�sobn�ku.
				 *
				 * @param S Z�sobn�k
				 * @return Prvek z vrcholu z�sobn�ku
				 */
				char Pop(Stack& S);

				/**
				 * Prvek na vrcholu z�sobn�ku.
				 * Prvek nen� ze z�sobn�ku odstran�n, jedn� se tedy o nedestruktivn� variantu funkce #Pop.
				 *
				 * @param S Z�sobn�k
				 * @return Prvek z vrcholu z�sobn�ku
				 */
				char Top(Stack& S);

				/**
				 * Test, je-li z�sobn�k pr�zdn�.
				 *
				 * @param S Z�sobn�k
				 * @return Funkce vrac� true pokud je z�sobn�k pr�zdn�, jinak false.
				 */
				bool IsEmpty(const Stack& S);

				/**
				 * Smaz�n� cel�ho obsahu z�sobn�ku.
				 *
				 * @param S Z�sobn�k
				 */
				void Clear(Stack& S);
			}
		}
	}
}