#pragma once

// Waiting: Insert, RemoveAt, BinarySearch, Sort, Reverse
// Done?: Copy ctor
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
					DynamicArray(const int size);

					/**
					* Kopírovací konstruktor
					*/
					DynamicArray(const DynamicArray& array);

					/**
					* Destuktor
					*/
					~DynamicArray();

					/**
					 * Pøetížení operátoru []
					 */
					const T& operator[](const int index);	
					// chybí pro r-value
					
					/**
					 * Metoda pro vložení prvku na konec posloupnosti v poli.
					 */
					void Add(const T Item);

					/**
					* Metoda pro vložení prvku na konec posloupnosti v poli.
					*/
					void Insert(const int index, const T Item);

					/**
					 * Metoda pro zjištìní velikosti datové struktury
					 * @return vrací velikost pole
					 */
					int Size() const;

					/**
					* Vyhledá daný prvek.
					* @return true pokud je prvek nalezen
					*/
					bool Contains(const T& value) const;

					/**
					* Vyhledá a odstraní daný prvek.
					*/
					void Remove(const T& value);
										
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
					* Metoda pro spoèítání prvkù v poli.
					* @return vrací poèet prvkù v poli
					*/
					int Count() const;
										
					/**
					* Tyto prvky jsou zatím v rámci testování v bloku public, pozdìji pøijdou do bloku private
					*/
					T* m_array;
					int m_size;
					int m_count;

				private:
					/**
					* Metoda používaná pro rozšiøování, èi redukci velikosti pole
					*/
					void Resize(int size);

					/**
					* Seznam bude mít vždy tuto minimální velikost
					*/
					const int DefaultMinimalSize = 10;

					/**
					* Promìnná používaná pøi rozšiøování, èi redukci velikosti pole
					*/
					const int AllocationDelta = 16;
				};

				template<typename T> DynamicArray<T>::DynamicArray() :m_count(0)
				{		
					m_size = DefaultMinimalSize;
					m_array = new T[m_size];
				}
				template<typename T> DynamicArray<T>::DynamicArray(const int size) : m_count(0)
				{
					if (size > DefaultMinimalSize) m_size = size;
					else m_size = DefaultMinimalSize;
					m_array = new T[m_size];
				}

				template<typename T> DynamicArray<T>::DynamicArray(const DynamicArray& array) :m_count(array.m_count)
				{
					m_size = array.m_size;
					T* newArray = new T[m_size];
					for(int i = 0; i < m_count; i++)
					{
						newArray[i] = array[i];
					}
					
					m_array = newArray;
				}
				
				template<typename T> DynamicArray<T>::~DynamicArray()
				{
					delete[] m_array;
				}

				template <class T> const T& DynamicArray<T>::operator[] (const int index)
				{
					return m_array[index];
				}

				template<typename T> void DynamicArray<T>::Add(const T Item)
				{
					if (m_count == m_size) Resize(m_size + AllocationDelta);
					m_array[m_count++] = Item;
				}

				template<typename T> void DynamicArray<T>::Insert(const int index, const T Item)
				{
					if (m_count == m_size) Resize(m_size + AllocationDelta);
					m_array[m_count++] = Item;
				}

				template <class T> int DynamicArray<T>::Size() const
				{
					return m_size;
				}

				template <class T> bool DynamicArray<T>::Contains(const T& value) const
				{
					for (int i = 0; i < m_count; i++)
					{
						if (m_array[i] == value)
						{
							return true;
						}
					}
					return false;
				}

				template <class T> void DynamicArray<T>::Remove(const T& value)
				{
					int position = 0;
					if(!IsEmpty())
					{
						for (position; position < m_count; position++)
						{
							if (m_array[position] == value) break;							
						}
						for(int i = position; i<m_count; i++)
						{
							m_array[i] = m_array[i + 1];
						}
						m_count--;
						if (m_count <= m_size - AllocationDelta) Resize(m_size - AllocationDelta);
					}					
				}

				template<typename T> void DynamicArray<T>::Resize(int size)
				{			
					T* newArray = new T[size];
					int n = (m_count <= m_size) ? m_count : m_size;
					while (n--)
					{
						newArray[n] = m_array[n];
					}
					delete[] m_array;
					m_array = newArray;
					m_size = size;
				}				

				template<class T> void DynamicArray<T>::Clear()
				{
					m_count = 0;
					m_size = DefaultMinimalSize;
					Resize(m_size);
				}

				template <class T> bool DynamicArray<T>::IsEmpty() const
				{
					return m_count == 0;
				}

				template <class T> int DynamicArray<T>::Count() const
				{					
					int count = 0;
					for(int i = 0; i < m_size; i++)
					{
						count++;
						if(i == NULL)
						{
							break;
						}
					}
					return count;
				}
			}
		}
	}
}


