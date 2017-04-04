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
				 * \brief Z�sobn�k implementovan� v poli s vyu�it�m %OOP
				 */
				class Stack
				{
				public:

					/**
					 * Konstruktor. Velikost z�sobn�ku bude nastavena na v�choz� velikost.
					 */
					Stack();

					/**
					 * Konstruktor. Velikost z�sobn�ku lze zvolit.
					 *
					 * @param StackSize Velikost z�sobn�ku
					 */
					Stack(const int StackSize);

					/**
					 * Destruktor
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
					* Prvek nen� ze z�sobn�ku odstran�n, jedn� se tedy o nedestruktivn� variantu funkce #Pop.
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
					 * Test, je-li z�sobn�k zapln�n�.
					 *
					 * @return Funkce vrac� true pokud je z�sobn�k zapln�n�, jinak false.
					 */
					bool IsFull() const;

					/**
					* Metoda pro zji�t�n� po�tu prvk� v z�sobn�ku
					*
					* @return Funkce vrac� po�et v�ech prvk� v z�sobn�ku.
					*/
					int Count() const;

					/**
					 * Smaz�n� cel�ho obsahu z�sobn�ku.
					 */
					void Clear();

				private:
					/**
					 * Pole obsahuj�c� data ulo�en� do z�sobn�ku.
					 */
					char* Items;

					/**
					 * Velikost z�sobn�ku.
					 */
					int StackSize;

					/**
					 * Ukazatel z�sobn�ku (stack pointer).
					 */
					int StackPointer;

					/**
					 * V�choz� (default) velikost z�sobn�ku.
					 */
					static const int DefaultStackSize = 100;
				};
			}
		}
	}
}
