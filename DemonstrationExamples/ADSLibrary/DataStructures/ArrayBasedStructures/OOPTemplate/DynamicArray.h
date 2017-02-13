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
					 * Pøetížení operátoru []
					 */
					T& operator[](const int index);	
					
					/**
					 * Metoda pro vložení prvku
					 */
					void Insert(const T Item);

					/**
					 * Metoda pro zjištìní velikosti datové struktury
					 * @return vrací velikost pole
					 */
					int Size() const;

					/**
					* Vyhledá daný prvek.
					* @return true pokud je prvek nalezen
					*/
					bool Search(T value) const;

					/**
					* Vyhledá a odstraní daný prvek.
					*/
					void Remove(T value);

					/**					 
					 * Metoda pro zjištìní posledního vloženého prvku.
					 * @return vrací poslední vložený prvek
					 */
					T LastItem();

					/**
					 * Metoda pro vymazání prvkù z pole.
					 */
					void Clear();

					/**
					 * Metoda pro zjištìní zda je struktura prázdná.
					 * @return vrací true pokud je prázdná
					 */
					bool IsEmpty() const;

					/**
					* Metoda pro zjištìní zda je struktura plná.
					* @return prakticky vrací vždy false, jelikož plného stavu nemùže takøka dosáhnout
					*/
					bool IsFull() const;

					/**
					* Tyto prvky jsou zatím v rámci testování v bloku public, pozdìji pøijdou do bloku private
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


