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
				* T��da reprezentuj�c� prvek ve mno�in�
				*/
				template <typename T>
				struct HashNode {

					T Key;
					HashNode * Next;

					HashNode(T Key) {
						this->Key = Key;
						this->Next = nullptr;
					}

					T getKey() {
						return this->Key;
					}

					HashNode* getNext()
					{
						return this->Next;
					}
				};

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
					* @param Key kl�� vkl�dan�ho prvku, tento kl�� se p�ed vlo�en�m zha�uje
					*/
					void Add(const T& Key) const;

					/**
					* Metoda pro z�sk�n� hodnoty HashNode podle dan�ho kl��e
					* @param Key kl��, podle kter�ho se vyhled�v� prvek
					* @return vrac� generickou hodnotu HashNode
					*/
					bool Contains(const T& Key);

					/**
					* Metoda pro odebr�n� prvku ze slovn�ku
					* @param Key kl��, dle kter�ho se odeb�r�
					*/
					void Remove(const T& Key);

					/**
					* Metoda pro odspo��t�n� prvk� v mno�in�
					* @return vrac� po�et prvk�
					*/
					int Count();

					/**
					* Metoda pro zji�t�n�, zda je mno�ina pr�zdn�
					* @return vrac� true pokud je pr�zdn�, jinak false
					*/
					bool IsEmpty();

					/**
					* Metoda pro pr�nik dvou mno�in. Postupn� porovn�v�, zda ob� mno�iny obsahuj� danou hodnotu. P�eskakuje uzly NULL a proch�z� v�echny uzly v dan� p�ihr�dce ha�ovac� tabulky.
					* @param set je mno�ina, se kterou se prov�d� pr�nik
					* @param newTable je nov� v�stupn� mno�ina s pr�nikem
					*/
					void Intersect(const HashSet* set, const HashSet* newTable);

					/**
					* Metoda pro sjednocen� dvou mno�in. Projde nap�ed jednu, pak druhou mno�inu a vlo�� do nov� v�stupn�.
					* @param set je mno�ina, se kterou se prov�d� pr�nik
					* @param newTable je nov� v�stupn� mno�ina s pr�nikem
					*/
					void Union(const HashSet* set, const HashSet* newTable);

					/**
					* Pomocn� metoda pro v�pis
					*/
					void Report();

				private:

					/**
					* Prom�nn� reprezentuj�c� po�et p�ihr�dek v hashtable
					*/
					int m_size = 128;

					/**
					* Metoda pro zha�ov�n� kl��e prvku
					* @param Key ha�ovan� kl��
					* @return vrac� zha�ovan� kl��
					*/
					int HashFunc(const T& Key) const;

					HashNode<T>** table;
				};

				template<typename T> HashSet<T>::HashSet()
				{
					table = new HashNode<T>*[m_size];
					for (int i = 0; i < m_size; i++)
						table[i] = nullptr;
				}

				template<typename T> HashSet<T>::~HashSet()
				{
					for (int i = 0; i < m_size; ++i)
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
					return std::hash<T>()(Key) % m_size;
				}

				template<typename T> void HashSet<T>::Add(const T& Key) const
				{
					int hash = HashFunc(Key);
					HashNode<T> *prev = nullptr;
					HashNode<T> *entry = table[hash];

					while (entry != nullptr && entry->getKey() != Key)
					{
						prev = entry;
						entry = entry->getNext();
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
					if (table[hash] != NULL) {
						HashNode<T>* prevEntry = nullptr;
						HashNode<T>* entry = table[hash];
						while (entry->getNext() != NULL && entry->getKey() != Key) {
							prevEntry = entry;
							entry = entry->getNext();
						}
						if (entry->getKey() == Key) {
							if (prevEntry == nullptr) {
								HashNode<T>* nextEntry = entry->getNext();
								delete entry;
								table[hash] = nextEntry;
							}
							else {
								HashNode<T>* next = entry->getNext();
								delete entry;
								prevEntry->Next = next;
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
					for (int i = 0; i < m_size; i++)
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
					for (int i = 0; i < m_size; i++)
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
					for(int i = 0; i < m_size; i++)
					{
						for (int j = 0; j < set->m_size; j++)
						{
							if (table[i] != nullptr)
							{
								if (set->table[j] == nullptr) continue;
								if(set->table[j]->getKey() == table[i]->getKey())
								{
									newTable->Add(table[i]->getKey());
									entry = table[i];
									while (entry != nullptr)
									{
										newTable->Add(entry->getKey());
										entry = entry->Next;
									}
									entry = set->table[j];
									while (entry != nullptr)
									{
										newTable->Add(entry->getKey());
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
					for (int i = 0; i < m_size; i++)
					{
						entry = table[i];
						while (entry != nullptr)
						{
							newTable->Add(entry->getKey());
							entry = entry->Next;
						}
					}
					entry = set->table[0];
					for (int j = 0; j < m_size; j++)
					{
						entry = set->table[j];
						while (entry != nullptr)
						{
							newTable->Add(entry->getKey());
							entry = entry->Next;
						}
					}
				}

				template<typename T> void HashSet<T>::Report()
				{
					for (int i = 0; i < m_size; i++)
					{
						if (table[i] != nullptr) std::cout << table[i]->getKey() << " NEXT:" << table[i]->getNext() << std::endl;
					}
				}
				
			}
		}
	}
}
