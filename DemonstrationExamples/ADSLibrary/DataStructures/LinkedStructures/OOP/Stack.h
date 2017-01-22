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
				 * \brief Zásobník implementovaný pomocí spojových struktur s využitím %OOP.
				 *
				 * @author	Jiøí Dvorský <jiri.dvorsky@vsb.cz>
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
					 * Vložení prvku na vrchol zásobníku.
					 *
					 * @param X Vkládaný prvek
					 */
					void Push(const char X);

					/**
					 * Odebrání prvku z vrcholu zásobníku.
					 *
					 * @return Prvek z vrcholu zásobníku
					 */
					char Pop();

					/**
					 * Prvek na vrcholu zásobníku.
					 * Prvek není za zásobníku odstranìn, jedná se tedy o nedestruktivní variantu funkce #Pop.
					 *
					 * @return Prvek z vrcholu zásobníku
					 */
					char Top() const;

					/**
					 * Test, je-li zásobník prázdný.
					 *
					 * @return Funkce vrací true pokud je zásobník prázdný, jinak false.
					 */
					bool IsEmpty() const;
				
					/**
					 * Smazání celého obsahu zásobníku.
					 */
					void Clear();

				private:
					/**
					 * \brief Struktura reprezentující položku v zásobníku.
					 */
					struct StackItem
					{
						/**
						 * Hodnota obsažená v položce.
						 */
						char Value;
						/**
						 * Ukazatel na pøedchozí položku. Pokud taková položka neexistuje ukazatel má hodnotu nullptr.
						 */
						StackItem* Prev;
					};

					/**
					 * Ukazatel zásobníku.
					 */
					StackItem* StackPointer;
				};
			}
		}
	}
}