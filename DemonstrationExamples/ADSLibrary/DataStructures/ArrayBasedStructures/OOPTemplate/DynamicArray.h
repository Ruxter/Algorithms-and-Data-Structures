#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOPTemplate
			{
				template <class T> class DynamicArray
				{
				public:
					/**
					 * Konstruktor
					 */
					DynamicArray();
					/**
					* Konstruktor s parametrem size
					*/
					DynamicArray(int size);
					/**
					* Destuktor
					*/
					~DynamicArray();
					/**
					 * P�et�en� oper�toru []
					 */
					T& operator[](const int index);					
					/**
					 * Metoda pro vlo�en� prvku
					 */
					void Insert(const T Item);
					/**
					 *Vrac� velikost pole
					 */
					int Size() const;
					/**
					 * Metoda pro zji�t�n� posledn�ho vlo�en�ho prvku
					 */
					T LastItem();
					/**
					 * Metoda pro vymaz�n� prvk�, av�ak bez destrukce struktury
					 */
					void Clear();
					/**
					 * Metoda pro zji�t�n� zda je struktura pr�zdn�
					 */
					bool IsEmpty() const;
					/**
					* Metoda pro zji�t�n� zda je struktura pln�
					*/
					bool IsFull() const;

					/**
					* Tyto prvky jsou zat�m v r�mci testov�n� v bloku public, pozd�ji p�ijdou do bloku private
					*/
					T* m_list;
					int m_size;
					int m_count;

				private:
					void Resize(int size);
				};

				template<typename T> DynamicArray<T>::DynamicArray()
				{					
					m_count = 0;
					m_size = 0;
					m_list = new T[m_size];
				}
				template<typename T> DynamicArray<T>::DynamicArray(int size) : m_count(0)
				{
					if (size > 0) m_size = size;
					m_list = new T[m_size];
				}
				
				template<typename T> DynamicArray<T>::~DynamicArray()
				{
					delete[] m_list;
				}

				template <class T> T& DynamicArray<T>::operator[] (const int index)
				{
					return m_list[index];
				}

				template<typename T> void DynamicArray<T>::Insert(const T Item)
				{
					if (m_count == m_size) Resize(m_size + 10);
					m_list[m_count++] = Item;
				}

				template <class T> int DynamicArray<T>::Size() const
				{
					return m_size;
				}

				template<typename T> void DynamicArray<T>::Resize(int size)
				{			
					T* newlist = new T[size];
					int n = (m_count <= m_size) ? m_count : m_size;
					while (n--)
					{
						newlist[n] = m_list[n];
					}
					delete[] m_list;
					m_list = newlist;
					m_size = size;
				}

				template <class T> T DynamicArray<T>::LastItem()
				{					
					if (IsEmpty()) return NULL;
					return m_list[m_count - 1];
				}

				template<class T> void DynamicArray<T>::Clear()
				{
					m_count = 0;
					Resize(m_count);
				}

				template <class T> bool DynamicArray<T>::IsEmpty() const
				{
					return m_count == 0;
				}

				template <class T> bool DynamicArray<T>::IsFull() const
				{
					return m_count == m_size;
				}
			}
		}
	}
}


