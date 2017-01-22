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
					 *Vrací velikost pole
					 */
					int Size() const;
					/**
					 * Metoda pro zjištìní posledního vloženého prvku
					 */
					int LastItem() const;
					/**
					 * Tyto prvky jsou zatím v rámci testování v bloku public, pozdìji pøijdou do bloku private
					 */
					void Clear();
					T* m_list;
					int m_size;
					int m_count;

				private:
					void Resize(int size);
				};

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
					if (size <= 0) cout << "Invalid array size";
					if (size == m_size)	cout << "Size is OK";;
					T* newlist = new T[size];
					if (newlist == nullptr) cout << "Memory allocation error";;
					int n = (m_count <= m_size) ? m_count : m_size;
					while (n--)
					{
						newlist[n] = m_list[n];
					}
					delete[] m_list;
					m_list = newlist;
					m_size = size;
				}
				template <class T> int DynamicArray<T>::LastItem() const
				{
					int tmp = m_list[m_count - 1];
					return tmp;
				}

				template<class T> void DynamicArray<T>::Clear()
				{
					m_count = 0;
				}
			}
		}
	}
}


