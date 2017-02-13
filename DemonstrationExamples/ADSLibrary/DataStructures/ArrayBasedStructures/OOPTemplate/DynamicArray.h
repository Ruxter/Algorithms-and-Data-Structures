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
					 * Metoda pro zji�t�n� velikosti datov� struktury
					 * @return vrac� velikost pole
					 */
					int Size() const;

					/**
					* Vyhled� dan� prvek.
					* @return true pokud je prvek nalezen
					*/
					bool Search(T value) const;

					/**
					* Vyhled� a odstran� dan� prvek.
					*/
					void Remove(T value);

					/**					 
					 * Metoda pro zji�t�n� posledn�ho vlo�en�ho prvku.
					 * @return vrac� posledn� vlo�en� prvek
					 */
					T LastItem();

					/**
					 * Metoda pro vymaz�n� prvk� z pole.
					 */
					void Clear();

					/**
					 * Metoda pro zji�t�n� zda je struktura pr�zdn�.
					 * @return vrac� true pokud je pr�zdn�
					 */
					bool IsEmpty() const;

					/**
					* Metoda pro zji�t�n� zda je struktura pln�.
					* @return prakticky vrac� v�dy false, jeliko� pln�ho stavu nem��e tak�ka dos�hnout
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

				template <class T> bool DynamicArray<T>::Search(T value) const
				{
					if(!IsEmpty())
					{
						for (int i = 0; i < m_count; i++)
						{
							if (m_list[i] == value)
							{
								return true;
							}
						}
						return false;
					}	
					return false;
				}

				template <class T> void DynamicArray<T>::Remove(T value)
				{
					int position = 0;
					if(!IsEmpty())
					{
						for (position; position < m_count; position++)
						{
							if (m_list[position] == value) break;							
						}
						for(int i = position; i<m_count; i++)
						{
							m_list[i] = m_list[i + 1];
						}
						m_count--;
						if (m_count <= m_size - 10) Resize(m_size - 10);
					}					
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
					if (m_count == 0 && m_size == 0) return false;
					return m_count == m_size;
				}
			}
		}
	}
}


