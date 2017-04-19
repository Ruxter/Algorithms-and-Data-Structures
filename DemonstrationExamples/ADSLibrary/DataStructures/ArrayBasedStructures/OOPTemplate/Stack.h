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
				 * \brief Z�sobn�k implementovan� v poli jako �ablona (template) %OOP
				 */
				template <typename T>
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
					void Push(const T X);

					/**
					 * Odebr�n� prvku z vrcholu z�sobn�ku.
					 *
					 * @return Prvek z vrcholu z�sobn�ku
					 */
					T Pop();

					/**
					* Prvek na vrcholu z�sobn�ku.
					* Prvek nen� ze z�sobn�ku odstran�n, jedn� se tedy o nedestruktivn� variantu funkce #Pop.
					*
					* @return Prvek z vrcholu z�sobn�ku
					*/
					T Top() const;

					/**
					 * Test je-li z�sobn�k pr�zdn�.
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
					* Metoda pro zji�t�n� velikosti z�sobn�ku
					*
					* @return Funkce vrac� po�et v�ech slot� v z�sobn�ku.
					*/
					int Size() const;

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

					/**
					* P�et�en� oper�toru []
					*/
					T& operator[](const int index);

					/**
					* P�et�en� oper�toru [] pro r-value
					*/
					const T& operator[](const int index) const;

				private:
					/**
					 * Pole obsahuj�c� data ulo�en� do z�sobn�ku.
					 */
					T* mItems;

					/**
					 * Velikost z�sobn�ku.
					 */
					int mStackSize;

					/**
					 * Ukazatel z�sobn�ku.
					 */
					int mStackPointer;					

					/**
					 * V�choz� (default) velikost z�sobn�ku.
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
