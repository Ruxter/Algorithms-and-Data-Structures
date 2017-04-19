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
				* Struktura reprezentující vnitøní strukturu prvku v množinì
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
				* HashSet je NEuspoøádaná množina realizována jako hashmTable bez mapovaných hodnot.
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
					* Metoda pro vložení prvku do slovníku
					* 
					* @param Key klíè vkládaného prvku, tento klíè se pøed vložením zhašuje
					*/
					void Add(const T& Key) const;

					/**
					* Metoda pro získání hodnoty HashNode podle daného klíèe
					* 
					* @param Key klíè, podle kterého se vyhledává prvek
					* @return vrací generickou hodnotu HashNode
					*/
					bool Contains(const T& Key);

					/**
					* Metoda pro odebrání prvku ze slovníku
					* 
					* @param Key klíè, dle kterého se odebírá
					*/
					void Remove(const T& Key);

					/**
					* Metoda pro odspoèítání prvkù v množinì
					* 
					* @return vrací poèet prvkù
					*/
					int Count();

					/**
					* Metoda pro zjištìní, zda je množina prázdná
					* 
					* @return vrací true pokud je prázdná, jinak false
					*/
					bool IsEmpty();

					/**
					* Metoda pro prùnik dvou množin. Postupnì porovnává, zda obì množiny obsahují danou hodnotu. Pøeskakuje uzly NULL a prochází všechny uzly v dané pøihrádce hašovací tabulky.
					* 
					* @param set je množina, se kterou se provádí prùnik
					* @param NewmTable je nová výstupní množina s prùnikem
					*/
					void Intersect(const HashSet* set, const HashSet* NewmTable);

					/**
					* Metoda pro sjednocení dvou množin. Projde napøed jednu, pak druhou množinu a vloží do nové výstupní.
					* 
					* @param set je množina, se kterou se provádí prùnik
					* @param NewmTable je nová výstupní množina s prùnikem
					*/
					void Union(const HashSet* set, const HashSet* NewmTable);

					/**
					* Pomocná metoda pro výpis
					*/
					void Report();

				private:

					/**
					* Promìnná reprezentující poèet pøihrádek v hashmTable
					*/
					int mSize = 128;

					/**
					* Metoda pro zhašování klíèe prvku
					* @param Key hašovaný klíè
					* @return vrací zhašovaný klíè
					*/
					int HashFunc(const T& Key) const;

					/**
					* Reprezentuje hašovací tabulku
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
