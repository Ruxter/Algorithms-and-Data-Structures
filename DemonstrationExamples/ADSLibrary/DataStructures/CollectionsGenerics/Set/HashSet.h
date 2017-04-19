#pragma once
#include <memory>
#include <iostream>

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Set
			{
				/**
				* Struktura reprezentuj�c� vnit�n� strukturu prvku v mno�in�
				*/
				template <typename T>
				struct HashNode {

					T Key;
					HashNode * Next;

					HashNode(T Key) {
						this->Key = Key;
						this->Next = nullptr;
					}
				};

				/**
				* HashSet je NEuspo��dan� mno�ina realizov�na jako hashmTable bez mapovan�ch hodnot.
				*/
				template <class T> class HashSet
				{
				public:

					/**
					* Konstruktor
					*/
					HashSet();

					/**
					* Destruktor
					*/
					~HashSet();

					/**
					* Metoda pro vlo�en� prvku do slovn�ku
					* 
					* @param Key kl�� vkl�dan�ho prvku, tento kl�� se p�ed vlo�en�m zha�uje
					*/
					void Add(const T& Key) const;

					/**
					* Metoda pro z�sk�n� hodnoty HashNode podle dan�ho kl��e
					* 
					* @param Key kl��, podle kter�ho se vyhled�v� prvek
					* @return vrac� generickou hodnotu HashNode
					*/
					bool Contains(const T& Key);

					/**
					* Metoda pro odebr�n� prvku ze slovn�ku
					* 
					* @param Key kl��, dle kter�ho se odeb�r�
					*/
					void Remove(const T& Key);

					/**
					* Metoda pro odspo��t�n� prvk� v mno�in�
					* 
					* @return vrac� po�et prvk�
					*/
					int Count();

					/**
					* Metoda pro zji�t�n�, zda je mno�ina pr�zdn�
					* 
					* @return vrac� true pokud je pr�zdn�, jinak false
					*/
					bool IsEmpty();

					/**
					* Metoda pro pr�nik dvou mno�in. Postupn� porovn�v�, zda ob� mno�iny obsahuj� danou hodnotu. P�eskakuje uzly NULL a proch�z� v�echny uzly v dan� p�ihr�dce ha�ovac� tabulky.
					* 
					* @param set je mno�ina, se kterou se prov�d� pr�nik
					* @param NewmTable je nov� v�stupn� mno�ina s pr�nikem
					*/
					void Intersect(const HashSet* set, const HashSet* NewmTable);

					/**
					* Metoda pro sjednocen� dvou mno�in. Projde nap�ed jednu, pak druhou mno�inu a vlo�� do nov� v�stupn�.
					* 
					* @param set je mno�ina, se kterou se prov�d� pr�nik
					* @param NewmTable je nov� v�stupn� mno�ina s pr�nikem
					*/
					void Union(const HashSet* set, const HashSet* NewmTable);

					/**
					* Pomocn� metoda pro v�pis
					*/
					void Report();

				private:

					/**
					* Prom�nn� reprezentuj�c� po�et p�ihr�dek v hashmTable
					*/
					int mSize = 128;

					/**
					* Metoda pro zha�ov�n� kl��e prvku
					* @param Key ha�ovan� kl��
					* @return vrac� zha�ovan� kl��
					*/
					int HashFunc(const T& Key) const;

					/**
					* Reprezentuje ha�ovac� tabulku
					*/
					HashNode<T>** mTable;
				};

				template<typename T> HashSet<T>::HashSet()
				{
					mTable = new HashNode<T>*[mSize];
					for (int i = 0; i < mSize; i++)
						mTable[i] = nullptr;
				}

				template<typename T> HashSet<T>::~HashSet()
				{
					for (int i = 0; i < mSize; ++i)
					{
						HashNode<T>* entry = mTable[i];
						while (entry != nullptr)
						{
							HashNode<T>* prev = entry;
							entry = entry->Next;
							delete prev;
						}
					}
					delete[] mTable;
				}

				template<typename T> int HashSet<T>::HashFunc(const T& Key) const
				{
					return std::hash<T>()(Key) % mSize;
				}

				template<typename T> void HashSet<T>::Add(const T& Key) const
				{
					int hash = HashFunc(Key);
					HashNode<T> *prev = nullptr;
					HashNode<T> *entry = mTable[hash];

					while (entry != nullptr && entry->Key != Key)
					{
						prev = entry;
						entry = entry->Next;
					}

					if (entry == nullptr)
					{
						entry = new HashNode<T>(Key);
						if (prev == nullptr) mTable[hash] = entry;
						else prev->Next = entry;
					}
					else entry->Key = Key;
				}

				template<typename T> void HashSet<T>::Remove(const T& Key)
				{
					int hash = HashFunc(Key);
					if (mTable[hash] != nullptr) {
						HashNode<T>* prev = nullptr;
						HashNode<T>* entry = mTable[hash];
						while (entry->Next != nullptr && entry->Key != Key) {
							prev = entry;
							entry = entry->Next;
						}
						if (entry->Key == Key) {
							if (prev == nullptr) {
								HashNode<T>* nextEntry = entry->Next;
								delete entry;
								mTable[hash] = nextEntry;
							}
							else {
								HashNode<T>* next = entry->Next;
								delete entry;
								prev->Next = next;
							}
						}
					}
				}

				template<typename T> bool HashSet<T>::Contains(const T& Key)
				{
					int hash = HashFunc(Key);
					HashNode<T>* entry = mTable[hash];
					while (entry != nullptr)
					{
						if (entry->Key == Key)
						{
							return true;
						}
						entry = entry->Next;
					}
					return false;
				}

				template<typename T> int HashSet<T>::Count()
				{
					int count = 0;
					HashNode<T>* entry = mTable[0];
					for (int i = 0; i < mSize; i++)
					{
						entry = mTable[i];
						while (entry != nullptr)
						{
							count++;
							entry = entry->Next;
						}
					}
					return count;
				}

				template<typename T> bool HashSet<T>::IsEmpty()
				{
					bool isEmpty = true;
					for (int i = 0; i < mSize; i++)
					{
						if (mTable[i] != nullptr) 
						{
							isEmpty = false;
							break;
						}
					}
					return isEmpty;
				}

				template<typename T> void HashSet<T>::Intersect(const HashSet* set, const HashSet* NewTable)
				{
					HashNode<T>* entry = nullptr;
					for(int i = 0; i < mSize; i++)
					{
						for (int j = 0; j < set->mSize; j++)
						{
							if (mTable[i] != nullptr)
							{
								if (set->mTable[j] == nullptr) continue;
								if(set->mTable[j]->Key == mTable[i]->Key)
								{
									NewTable->Add(mTable[i]->Key);
									entry = mTable[i];
									while (entry != nullptr)
									{
										NewTable->Add(entry->Key);
										entry = entry->Next;
									}
									entry = set->mTable[j];
									while (entry != nullptr)
									{
										NewTable->Add(entry->Key);
										entry = entry->Next;
									}
									break;
								}
							}
						}
					}
				}

				template<typename T> void HashSet<T>::Union(const HashSet* set, const HashSet* NewTable)
				{
					HashNode<T>* entry = mTable[0];
					for (int i = 0; i < mSize; i++)
					{
						entry = mTable[i];
						while (entry != nullptr)
						{
							NewTable->Add(entry->Key);
							entry = entry->Next;
						}
					}
					entry = set->mTable[0];
					for (int j = 0; j < mSize; j++)
					{
						entry = set->mTable[j];
						while (entry != nullptr)
						{
							NewTable->Add(entry->Key);
							entry = entry->Next;
						}
					}
				}

				template<typename T> void HashSet<T>::Report()
				{
					for (int i = 0; i < mSize; i++)
					{
						if (mTable[i] != nullptr) std::cout << mTable[i]->Key << " NEXT:" << mTable[i]->Next << std::endl;
					}
				}
				
			}
		}
	}
}
