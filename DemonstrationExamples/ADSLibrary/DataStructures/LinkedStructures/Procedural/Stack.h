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
				 * \brief Struktura reprezentující položku v zásobníku {@link #ADSLibrary::DataStructures::LinkedStructures::Procedural::Stack}
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
				 * \brief Zásobník implementovaný pomocí spojových struktur procedurálním zpùsobem.
				 */
				struct Stack
				{
					/**
					 * Ukazatel zásobníku
					 */
					StackItem* StackPointer;
				};

				/**
				 * Inicializace zásobníku. Zásobník je po inicializaci prázdný.
				 *
				 * @param S Inicializovaný zásobník
				 */
				void Init(Stack& S);

				/**
				 * Vložení prvku na vrchol zásobníku.
				 *
				 * @param S Zásobník
				 * @param X Vkládaný prvek
				 */
				void Push(Stack& S, const char X);

				/**
				 * Odebrání prvku z vrcholu zásobníku.
				 *
				 * @param S Zásobník
				 * @return Prvek z vrcholu zásobníku
				 */
				char Pop(Stack& S);

				/**
				 * Prvek na vrcholu zásobníku.
				 * Prvek není ze zásobníku odstranìn, jedná se tedy o nedestruktivní variantu funkce #Pop.
				 *
				 * @param S Zásobník
				 * @return Prvek z vrcholu zásobníku
				 */
				char Top(Stack& S);

				/**
				 * Test, je-li zásobník prázdný.
				 *
				 * @param S Zásobník
				 * @return Funkce vrací true pokud je zásobník prázdný, jinak false.
				 */
				bool IsEmpty(const Stack& S);

				/**
				 * Smazání celého obsahu zásobníku.
				 *
				 * @param S Zásobník
				 */
				void Clear(Stack& S);
			}
		}
	}
}