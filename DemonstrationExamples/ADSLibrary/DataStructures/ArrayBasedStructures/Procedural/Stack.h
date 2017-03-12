#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace Procedural
			{
				/**
				 * Velikost z�sobn�ku.
				 */
				const int StackSize = 10;
				
				/**
				 * \brief Z�sobn�k implementovan� v poli procedur�ln�m zp�sobem.
				 */
				struct Stack
				{
					/**
					 * Pole obsahuj�c� polo�ky z�sobn�ku.
					 */
					char Items[StackSize];
					/**
					 * Ukazatel z�sobn�ku.
					 * Ukazatel z�sobn�ku ukazuje na prvn� volnou pozici v poli #Items.
					 */
					int StackPointer;
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
				 * Test, je-li z�sobn�k zapln�n�.
				 *
				 * @param S Z�sobn�k
				 * @return Funkce vrac� true pokud je z�sobn�k zapln�n�, jinak false.
				 */
				bool IsFull(const Stack& S);

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