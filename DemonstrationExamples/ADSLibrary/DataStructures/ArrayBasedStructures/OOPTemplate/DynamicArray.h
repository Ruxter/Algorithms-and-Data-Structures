#pragma once

// Waiting: r-val overload operator[]
// Done?: Copy ctor, Sort (except: number of elements for different alg?), BinarySearch, Reverse, Insert, RemoveAt
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
					* Kop�rovac� konstruktor
					*/
					DynamicArray(const DynamicArray& array);

					/**
					* Destuktor
					*/
					~DynamicArray();

					/**
					 * P�et�en� oper�toru []
					 */
					const T& operator[](const int index);	
					// chyb� pro r-value
					
					/**
					 * Metoda pro vlo�en� prvku na konec posloupnosti v poli.
					 */
					void Add(const T& Item);

					/**
					* Metoda pro vlo�en� prvku do pole na ur�en� index.
					*/
					void InsertAt(const int index, const T& Item);

					/**
					 * Metoda pro zji�t�n� velikosti datov� struktury
					 * @return vrac� velikost pole
					 */
					int Size() const;

					/**
					* Vyhled� dan� prvek.
					* @return true pokud je prvek nalezen
					*/
					bool Contains(const T& value) const;

					/**
					* Vyhled� a odstran� dan� prvek.
					*/
					void Remove(const T& value);
										
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
					* Metoda pro spo��t�n� prvk� v poli.
					* @return vrac� po�et prvk� v poli
					*/
					int Count() const;

					/**
					* Metoda pro sort pole, vyb�r� dva r�zn� �ad�c� algoritmy podle velikosti dat.
					*/
					void Sort();

					/**
					* Metoda pro vyhled�v�n� prvku v poli
					* @param startIndex lev� hranice(index) pro vyhled�v�n� v poli
					* @param endIndex prav� hranice(index) pro vyhled�v�n� v poli
					* @param item vyhled�van� prvek
					*/
					int BinarySearch(int startIndex, int endIndex, const T& item);

					void Reverse();

					bool RemoveAt(int index);

					/**
					* Metoda pro v�pis 
					*/
					void Report();
															
					/**
					* Tyto prvky jsou zat�m v r�mci testov�n� v bloku public, pozd�ji p�ijdou do bloku private
					*/
					T* m_array;
					int m_size;
					int m_count;

				private:
					/**
					* Metoda pou��van� pro roz�i�ov�n�, �i redukci velikosti pole
					*/
					void Resize(int size);

					/**
					* Seznam bude m�t v�dy tuto minim�ln� velikost
					*/
					const int DefaultMinimalSize = 10;

					/**
					* Prom�nn� pou��van� p�i roz�i�ov�n�, �i redukci velikosti pole
					*/
					const int AllocationDelta = 16;

					/**
					* �ad�c� algoritmus Insertion Sort
					*/
					void InsertionSort();

					/**
					* �ad�c� algoritmus Quick Sort. Pivot je nastaven implicitn� na nult� prvek pole
					* @param left lev� hranice(index) pro set��d�n�
					* @param right prav� hranice(index) pro set��d�n�
					*/
					void QuickSort(int left, int right);

					/**
					* Pomocn� metoda pro Quick Sort, prohod� dva prvky
					*/
					void Swap(T m_array[], int left, int right);										
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

				template<typename T> void DynamicArray<T>::Add(const T& Item)
				{
					if (m_count == m_size) Resize(m_size + AllocationDelta);
					m_array[m_count++] = Item;
				}

				template<typename T> void DynamicArray<T>::InsertAt(const int index, const T& Item)
				{
					T* newArray = new T[m_size];
					if (index <= m_count)
					{
						m_count++;
						if (m_count <= m_size - AllocationDelta) Resize(m_size - AllocationDelta);
						for (int i = 0; i <= m_count; ++i)
						{
							if (i < index)newArray[i] = m_array[i];
							if (i == index)newArray[i] = Item;
							if (i > index) newArray[i] = m_array[i - 1];
						}
						delete[] m_array;
						m_array = newArray;
					}
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
					return m_count;
				}

				template <class T> void DynamicArray<T>::Sort() 
				{				
					//InsertionSort();
					QuickSort(0, m_count);
				}

				template <class T> void DynamicArray<T>::InsertionSort()
				{
					T temp;
					int j;
					for (int i = 1; i <= (m_count - 1); i++) {
						temp = m_array[i];
						j = i - 1;
						while ((j >= 0) && (m_array[j] > temp)) {
							m_array[j + 1] = m_array[j];
							j--;
						}
						m_array[j + 1] = temp;
					}
				}

				template<class T> void DynamicArray<T>::Swap(T m_array[], int left, int right)
				{
					int tmp = m_array[right];
					m_array[right] = m_array[left];
					m_array[left] = tmp;
				}
					
				template <class T> void DynamicArray<T>::QuickSort(int left, int right)
				{
					if (left < right) {
						int pivot = left;
						for (int i = left + 1; i < right; i++) {
							if (m_array[i] < m_array[left]) {
								Swap(m_array, i, ++pivot);
							}
						}
						Swap(m_array, left, pivot);
						QuickSort(left, pivot);
						QuickSort(pivot + 1, right);
					}
				}

				template <class T> int DynamicArray<T>::BinarySearch(int startIndex, int endIndex, const T& item)
				{
					Sort();						
					if (startIndex > endIndex)
					{
						return -1;
					}
					const int middle = startIndex + ((endIndex - startIndex) / 2);

					if (m_array[middle] == item)
					{
						return middle;
					}
					if (m_array[middle] > item)
					{
						return BinarySearch(startIndex, middle-1, item);
					}
					return BinarySearch(middle + 1, endIndex, item);
				}

				template<class T> void DynamicArray<T>::Reverse()
				{
					T temp;
					int i;
					for (i = 0; i < m_count / 2; ++i) {
						temp = m_array[m_count - i - 1];
						m_array[m_count - i - 1] = m_array[i];
						m_array[i] = temp;
					}
				}

				template<class T> bool DynamicArray<T>::RemoveAt(int index)
				{
					if(!IsEmpty() && index<=m_count)
					{
						m_array[index] = NULL;
						for (int i = index; i < m_count; i++)
						{
							m_array[i] = m_array[i + 1];
						}
						m_count--;
						if (m_count <= m_size - AllocationDelta) Resize(m_size - AllocationDelta);
						return true;
					}
					return false;
				}

				template <class T> void DynamicArray<T>::Report()
				{
					for(int i = 0; i < m_count; i++)
					{
						cout << m_array[i] << endl;
					}
				}
			}
		}
	}
}


