#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				/**
				 * \brief Z�sobn�k implementovan� pomoc� spojov�ch struktur s vyu�it�m %OOP.
				 *
				 * @author	Ji�� Dvorsk� <jiri.dvorsky@vsb.cz>
				 * @date	2010 - 2015
				 */
				class Stack
				{
				public:
					/**
					 * Konstruktor.
					 */
					Stack();

					/**
					 * Destruktor.
					 */
					~Stack();

					/**
					 * Vlo�en� prvku na vrchol z�sobn�ku.
					 *
					 * @param X Vkl�dan� prvek
					 */
					void Push(const char X);

					/**
					 * Odebr�n� prvku z vrcholu z�sobn�ku.
					 *
					 * @return Prvek z vrcholu z�sobn�ku
					 */
					char Pop();

					/**
					 * Prvek na vrcholu z�sobn�ku.
					 * Prvek nen� za z�sobn�ku odstran�n, jedn� se tedy o nedestruktivn� variantu funkce #Pop.
					 *
					 * @return Prvek z vrcholu z�sobn�ku
					 */
					char Top() const;

					/**
					 * Test, je-li z�sobn�k pr�zdn�.
					 *
					 * @return Funkce vrac� true pokud je z�sobn�k pr�zdn�, jinak false.
					 */
					bool IsEmpty() const;
				
					/**
					 * Smaz�n� cel�ho obsahu z�sobn�ku.
					 */
					void Clear();

				private:
					/**
					 * \brief Struktura reprezentuj�c� polo�ku v z�sobn�ku.
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
					 * Ukazatel z�sobn�ku.
					 */
					StackItem* StackPointer;
				};
			}
		}
	}
}