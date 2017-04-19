#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOPTemplate
			{
				/**
				 * \brief Zásobník implementovaný v poli jako šablona (template) %OOP
				 */
				template <typename T>
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
					void Push(const T X);

					/**
					 * Odebrání prvku z vrcholu zásobníku.
					 *
					 * @return Prvek z vrcholu zásobníku
					 */
					T Pop();

					/**
					* Prvek na vrcholu zásobníku.
					* Prvek není ze zásobníku odstranìn, jedná se tedy o nedestruktivní variantu funkce #Pop.
					*
					* @return Prvek z vrcholu zásobníku
					*/
					T Top() const;

					/**
					 * Test je-li zásobník prázdný.
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
					* Metoda pro zjištìní velikosti zásobníku
					*
					* @return Funkce vrací poèet všech slotù v zásobníku.
					*/
					int Size() const;

					/**
					* Metoda pro zjištìní poètu prvkù v zásobníku
					*
					* @return Funkce vrací poèet všech prvk§ v zásobníku.
					*/
					int Count() const;

					/**
					 * Smazání celého obsahu zásobníku.
					 */
					void Clear();

					/**
					* Pøetížení operátoru []
					*/
					T& operator[](const int index);

					/**
					* Pøetížení operátoru [] pro r-value
					*/
					const T& operator[](const int index) const;

				private:
					/**
					 * Pole obsahující data uložená do zásobníku.
					 */
					T* mItems;

					/**
					 * Velikost zásobníku.
					 */
					int mStackSize;

					/**
					 * Ukazatel zásobníku.
					 */
					int mStackPointer;					

					/**
					 * Výchozí (default) velikost zásobníku.
					 */
					static const int mDefaultStackSize = 100;
				};

				template <typename T> Stack<T>::Stack()
				{					
					this->mStackSize = mDefaultStackSize;
					this->mItems = new T[mDefaultStackSize];
					this->mStackPointer = 0;
				}

				template <typename T> Stack<T>::Stack(const int StackSize)
				{
					this->mStackSize = StackSize <= 0 ? mDefaultStackSize : StackSize;
					this->mItems = new char[this->mStackSize];
					this->mStackPointer = 0;
				}

				template <typename T> Stack<T>::~Stack()
				{
					delete[] this->mItems;
				}

				template <typename T> void Stack<T>::Push(const T X)
				{
					this->mItems[this->mStackPointer] = X;
					this->mStackPointer += 1;
				}

				template <typename T> T Stack<T>::Pop()
				{
					this->mStackPointer -= 1;
					return this->mItems[this->mStackPointer];
				}

				template <typename T> T Stack<T>::Top() const
				{					
					return this->mItems[this->mStackPointer - 1];
				}

				template <typename T> int Stack<T>::Size() const
				{
					return this->mStackSize;
				}

				template <typename T> int Stack<T>::Count() const
				{
					return this->mStackPointer;
				}

				template <typename T> bool Stack<T>::IsEmpty() const
				{
					return this->mStackPointer == 0;
				}

				template <typename T> bool Stack<T>::IsFull() const
				{
					return this->mStackPointer == this->mStackSize;
				}

				template <typename T> void Stack<T>::Clear()
				{
					this->mStackPointer = 0;
				}
				
				template <class T> T& Stack<T>::operator[] (const int index)
				{
					return mItems[index];
				}

				template <class T> const T& Stack<T>::operator[] (const int index) const
				{
					return mItems[index];
				}

			}
		}
	}
}
