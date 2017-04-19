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
				* HashSet je NEuspoøádaná množina realizována jako hashtable bez mapovaných hodnot.
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
					* @param Key klíè vkládaného prvku, tento klíè se pøed vložením zhašuje
					*/
					void Add(const T& Key) const;

					/**
					* Metoda pro získání hodnoty HashNode podle daného klíèe
					* @param Key klíè, podle kterého se vyhledává prvek
					* @return vrací generickou hodnotu HashNode
					*/
					bool Contains(const T& Key);

					/**
					* Metoda pro odebrání prvku ze slovníku
					* @param Key klíè, dle kterého se odebírá
					*/
					void Remove(const T& Key);

					/**
					* Metoda pro odspoèítání prvkù v množinì
					* @return vrací poèet prvkù
					*/
					int Count();

					/**
					* Metoda pro zjištìní, zda je množina prázdná
					* @return vrací true pokud je prázdná, jinak false
					*/
					bool IsEmpty();

					/**
					* Metoda pro prùnik dvou množin. Postupnì porovnává, zda obì množiny obsahují danou hodnotu. Pøeskakuje uzly NULL a prochází všechny uzly v dané pøihrádce hašovací tabulky.
					* @param set je množina, se kterou se provádí prùnik
					* @param newTable je nová výstupní množina s prùnikem
					*/
					void Intersect(const HashSet* set, const HashSet* newTable);

					/**
					* Metoda pro sjednocení dvou množin. Projde napøed jednu, pak druhou množinu a vloží do nové výstupní.
					* @param set je množina, se kterou se provádí prùnik
					* @param newTable je nová výstupní množina s prùnikem
					*/
					void Union(const HashSet* set, const HashSet* newTable);

					/**
					* Pomocná metoda pro výpis
					*/
					void Report();

				private:

					/**
					* Promìnná reprezentující poèet pøihrádek v hashtable
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
					HashNode<T>** table;
				};

				template<typename T> HashSet<T>::HashSet()
				{
					table = new HashNode<T>*[mSize];
					for (int i = 0; i < mSize; i++)
						table[i] = nullptr;
				}

				template<typename T> HashSet<T>::~HashSet()
				{
					for (int i = 0; i < mSize; ++i)
					{
						HashNode<T>* entry = table[i];
						while (entry != nullptr)
						{
							HashNode<T>* prev = entry;
							entry = entry->Next;
							delete prev;
						}
					}
					delete[] table;
				}

				template<typename T> int HashSet<T>::HashFunc(const T& Key) const
				{
					return std::hash<T>()(Key) % mSize;
				}

				template<typename T> void HashSet<T>::Add(const T& Key) const
				{
					int hash = HashFunc(Key);
					HashNode<T> *prev = nullptr;
					HashNode<T> *entry = table[hash];

					while (entry != nullptr && entry->Key != Key)
					{
						prev = entry;
						entry = entry->Next;
					}

					if (entry == nullptr)
					{
						entry = new HashNode<T>(Key);
						if (prev == nullptr) table[hash] = entry;
						else prev->Next = entry;
					}
					else entry->Key = Key;
				}

				template<typename T> void HashSet<T>::Remove(const T& Key)
				{
					int hash = HashFunc(Key);
					if (table[hash] != nullptr) {
						HashNode<T>* prev = nullptr;
						HashNode<T>* entry = table[hash];
						while (entry->Next != nullptr && entry->Key != Key) {
							prev = entry;
							entry = entry->Next;
						}
						if (entry->Key == Key) {
							if (prev == nullptr) {
								HashNode<T>* nextEntry = entry->Next;
								delete entry;
								table[hash] = nextEntry;
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
					HashNode<T>* entry = table[hash];
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
					HashNode<T>* entry = table[0];
					for (int i = 0; i < mSize; i++)
					{
						entry = table[i];
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
						if (table[i] != nullptr) 
						{
							isEmpty = false;
							break;
						}
					}
					return isEmpty;
				}

				template<typename T> void HashSet<T>::Intersect(const HashSet* set, const HashSet* newTable)
				{
					HashNode<T>* entry = nullptr;
					for(int i = 0; i < mSize; i++)
					{
						for (int j = 0; j < set->mSize; j++)
						{
							if (table[i] != nullptr)
							{
								if (set->table[j] == nullptr) continue;
								if(set->table[j]->Key == table[i]->Key)
								{
									newTable->Add(table[i]->Key);
									entry = table[i];
									while (entry != nullptr)
									{
										newTable->Add(entry->Key);
										entry = entry->Next;
									}
									entry = set->table[j];
									while (entry != nullptr)
									{
										newTable->Add(entry->Key);
										entry = entry->Next;
									}
									break;
								}
							}
						}
					}
				}

				template<typename T> void HashSet<T>::Union(const HashSet* set, const HashSet* newTable)
				{
					HashNode<T>* entry = table[0];
					for (int i = 0; i < mSize; i++)
					{
						entry = table[i];
						while (entry != nullptr)
						{
							newTable->Add(entry->Key);
							entry = entry->Next;
						}
					}
					entry = set->table[0];
					for (int j = 0; j < mSize; j++)
					{
						entry = set->table[j];
						while (entry != nullptr)
						{
							newTable->Add(entry->Key);
							entry = entry->Next;
						}
					}
				}

				template<typename T> void HashSet<T>::Report()
				{
					for (int i = 0; i < mSize; i++)
					{
						if (table[i] != nullptr) std::cout << table[i]->Key << " NEXT:" << table[i]->Next << std::endl;
					}
				}
				
			}
		}
	}
}
