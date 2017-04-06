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
				 * DynamicArray je generick� dynamick� pole, kter� se redukuje �i expanduje na z�klad� po�tu prvk� v n�m.
				 */
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
					T& operator[](const int index);

					/**
					* P�et�en� oper�toru [] pro r-value
					*/
					const T& operator[](const int index) const;

					/**
					* Metoda pro vlo�en� prvku na konec posloupnosti v poli.
					*/
					void Add(const T& Item);

					/**
					* Metoda pro vlo�en� prvku do pole na ur�en� index.
					*/
					void InsertAt(const int index, const T& Item);

					/**
					* Metoda pro zji�t�n� velikosti datov� struktury.
					* 
					* @return vrac� velikost pole
					*/
					int Size() const;

					/**
					* Vyhled� dan� prvek.
					* 
					* @return true pokud je prvek nalezen
					*/
					bool Contains(const T& Item) const;

					/**
					* Vyhled� a odstran� dan� prvek.
					*/
					void Remove(const T& Item);

					/**
					* Vyhled� a odstran� prvek na dan�m indexu.
					*/
					bool RemoveAt(int index);

					/**
					* Metoda pro vymaz�n� prvk� z pole.
					*/
					void Clear();

					/**
					* Metoda pro zji�t�n� zda je struktura pr�zdn�.
					* 
					* @return vrac� true pokud je pr�zdn�
					*/
					bool IsEmpty() const;

					/**
					* Metoda pro spo��t�n� prvk� v poli.
					* 
					* @return vrac� po�et prvk� v poli
					*/
					int Count() const;

					/**
					* Metoda pro sort pole, vyb�r� dva r�zn� �ad�c� algoritmy podle velikosti dat.
					*/
					void Sort();

					/**
					* Metoda pro vyhled�v�n� prvku v poli. Pole MUS� b�t p�ed zavol�n�m BinarySearch set��zen� pomoc� Sort().
					* 
					* @param startIndex lev� hranice(index) pro vyhled�v�n� v poli
					* @param endIndex prav� hranice(index) pro vyhled�v�n� v poli
					* @param Item vyhled�van� prvek
					* @return -1 pokud dan� prvek neexistuje, jinak index v poli
					*/
					int BinarySearch(int startIndex, int endIndex, const T& Item);

					/**
					* Metoda pro "p�eklopen�" pole. 
					*/
					void Reverse();

					/**
					* Metoda pro v�pis.
					*/
					void Report();

				private:

					/**
					* Reprezentuje pole.
					*/
					T* mArray;

					/**
					* Prom�nn� reprezentuj�c� kapacitu seznamu.
					*/
					int mSize;

					/**
					* Prom�nn� reprezentuj�c� po�et prvk� v seznamu.
					*/

					int mCount;
					/**
					* Metoda pou��van� pro roz�i�ov�n�, �i redukci velikosti pole.
					*/
					void Resize(int size);

					/**
					* Pole bude m�t v�dy tuto minim�ln� velikost.
					*/
					const int DefaultMinimalSize = 10;

					/**
					* Prom�nn� pou��van� p�i roz�i�ov�n�, �i redukci velikosti pole.
					*/
					const int AllocationDelta = 16;

					/**
					* �ad�c� algoritmus Insertion Sort.
					*/
					void InsertionSort();

					/**
					* �ad�c� algoritmus Quick Sort. Pivot je nastaven implicitn� na nult� prvek pole.
					* 
					* @param left lev� hranice(index) pro set��d�n�
					* @param right prav� hranice(index) pro set��d�n�
					*/
					void QuickSort(int left, int right);

					/**
					* Pomocn� metoda pro Quick Sort, prohod� dva prvky.
					* 
					* @param mArray pole, kter� je proch�zeno quicksortem
					* @param left
					* @param right
					*/
					void Swap(T mArray[], int left, int right);
				};

				template<typename T> DynamicArray<T>::DynamicArray() :mCount(0)
				{
					mSize = DefaultMinimalSize;
					mArray = new T[mSize];
				}
				template<typename T> DynamicArray<T>::DynamicArray(const int size) : mCount(0)
				{
					if (size > DefaultMinimalSize) mSize = size;
					else mSize = DefaultMinimalSize;
					mArray = new T[mSize];
				}

				template<typename T> DynamicArray<T>::DynamicArray(const DynamicArray& array) :mCount(array.mCount)
				{
					mSize = array.mSize;
					T* newArray = new T[mSize];
					for (int i = 0; i < mCount; i++)
					{
						newArray[i] = array[i];
					}

					mArray = newArray;
				}

				template<typename T> DynamicArray<T>::~DynamicArray()
				{
					delete[] mArray;
				}

				template <class T> T& DynamicArray<T>::operator[] (const int index)
				{
					return mArray[index];
				}

				template <class T> const T& DynamicArray<T>::operator[] (const int index) const
				{
					return mArray[index];
				}

				template<typename T> void DynamicArray<T>::Add(const T& Item)
				{
					if (mCount == mSize) Resize(mSize + AllocationDelta);
					mArray[mCount++] = Item;
				}

				template<typename T> void DynamicArray<T>::InsertAt(const int index, const T& Item)
				{					
					T* newArray = new T[mSize];
					mCount++;
					if (mCount == mSize) Resize(mSize + AllocationDelta);					
					for (int i = 0; i <= mCount; ++i)
					{
						if (i < index)newArray[i] = mArray[i];
						if (i == index)newArray[i] = Item;
						if (i > index) newArray[i] = mArray[i - 1];
					}
					delete[] mArray;
					mArray = newArray;					
				}

				template <class T> int DynamicArray<T>::Size() const
				{
					return mSize;
				}

				template <class T> bool DynamicArray<T>::Contains(const T& Item) const
				{
					for (int i = 0; i < mCount; i++)
					{
						if (mArray[i] == Item)
						{
							return true;
						}
					}
					return false;
				}

				template <class T> void DynamicArray<T>::Remove(const T& Item)
				{
					int position = 0;
					if (!IsEmpty())
					{
						for (position; position < mCount; position++)
						{
							if (mArray[position] == Item) break;
						}
						for (int i = position; i < mCount; i++)
						{
							mArray[i] = mArray[i + 1];
						}
						mCount--;
						if (mCount <= mSize - AllocationDelta) Resize(mSize - AllocationDelta);
					}
				}

				template<class T> bool DynamicArray<T>::RemoveAt(int index)
				{
					if (!IsEmpty() && index <= mCount)
					{
						for (int i = index; i < mCount; i++)
						{
							mArray[i] = mArray[i + 1];
						}
						mCount--;
						if (mCount <= mSize - AllocationDelta) Resize(mSize - AllocationDelta);
						return true;
					}
					return false;
				}

				template<typename T> void DynamicArray<T>::Resize(int size)
				{
					T* newArray = new T[size];
					int n = (mCount <= mSize) ? mCount : mSize;
					while (n--)
					{
						newArray[n] = mArray[n];
					}
					delete[] mArray;
					mArray = newArray;
					mSize = size;
				}

				template<class T> void DynamicArray<T>::Clear()
				{
					mCount = 0;
					mSize = DefaultMinimalSize;
					Resize(mSize);
				}

				template <class T> bool DynamicArray<T>::IsEmpty() const
				{
					return mCount == 0;
				}

				template <class T> int DynamicArray<T>::Count() const
				{
					return mCount;
				}

				template <class T> void DynamicArray<T>::Sort()
				{
					if (mCount <= 10)InsertionSort();
					else QuickSort(0, mCount);
				}

				template <class T> void DynamicArray<T>::InsertionSort()
				{
					T temp;
					int j;
					for (int i = 1; i <= (mCount - 1); i++) {
						temp = mArray[i];
						j = i - 1;
						while ((j >= 0) && (mArray[j] > temp)) {
							mArray[j + 1] = mArray[j];
							j--;
						}
						mArray[j + 1] = temp;
					}
				}

				template<class T> void DynamicArray<T>::Swap(T mArray[], int left, int right)
				{
					T tmp = mArray[right];
					mArray[right] = mArray[left];
					mArray[left] = tmp;
				}

				template <class T> void DynamicArray<T>::QuickSort(int left, int right)
				{
					if (left < right) {
						int pivot = left;
						for (int i = left + 1; i < right; i++) {
							if (mArray[i] < mArray[left]) {
								Swap(mArray, i, ++pivot);
							}
						}
						Swap(mArray, left, pivot);
						QuickSort(left, pivot);
						QuickSort(pivot + 1, right);
					}
				}

				template <class T> int DynamicArray<T>::BinarySearch(int startIndex, int endIndex, const T& Item)
				{
					if (startIndex > endIndex) return -1;

					const int middle = startIndex + ((endIndex - startIndex) / 2);

					if (mArray[middle] == Item)
					{
						return middle;
					}
					if (mArray[middle] > Item)
					{
						return BinarySearch(startIndex, middle - 1, Item);
					}
					return BinarySearch(middle + 1, endIndex, Item);
				}

				template<class T> void DynamicArray<T>::Reverse()
				{
					T temp;
					int i;
					for (i = 0; i < mCount / 2; ++i) {
						temp = mArray[mCount - i - 1];
						mArray[mCount - i - 1] = mArray[i];
						mArray[i] = temp;
					}
				}				

				template <class T> void DynamicArray<T>::Report()
				{
					for (int i = 0; i < mCount; i++)
					{
						std::cout << i << " : " << mArray[i] << std::endl;
					}
				}
			}
		}
	}
}


