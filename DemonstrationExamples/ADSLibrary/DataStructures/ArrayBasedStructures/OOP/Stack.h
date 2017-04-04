#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOP
			{
				/**
				 * \brief Zásobník implementovaný v poli s využitím %OOP
				 */
				class Stack
				{
				public:

					/**
					 * Konstruktor. Velikost zásobníku bude nastavena na výchozí velikost.
					 */
					Stack();

					/**
					 * Konstruktor. Velikost zásobníku lze zvolit.
					 *
					 * @param StackSize Velikost zásobníku
					 */
					Stack(const int StackSize);

					/**
					 * Destruktor
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
					* Prvek není ze zásobníku odstranìn, jedná se tedy o nedestruktivní variantu funkce #Pop.
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
					 * Test, je-li zásobník zaplnìný.
					 *
					 * @return Funkce vrací true pokud je zásobník zaplnìný, jinak false.
					 */
					bool IsFull() const;

					/**
					* Metoda pro zjištìní poètu prvkù v zásobníku
					*
					* @return Funkce vrací poèet všech prvkù v zásobníku.
					*/
					int Count() const;

					/**
					 * Smazání celého obsahu zásobníku.
					 */
					void Clear();

				private:
					/**
					 * Pole obsahující data uložená do zásobníku.
					 */
					char* Items;

					/**
					 * Velikost zásobníku.
					 */
					int StackSize;

					/**
					 * Ukazatel zásobníku (stack pointer).
					 */
					int StackPointer;

					/**
					 * Výchozí (default) velikost zásobníku.
					 */
					static const int DefaultStackSize = 100;
				};
			}
		}
	}
}
