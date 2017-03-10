#pragma once
namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Dictionary
			{
				/**
				 * Tøída reprezentující prvek v Dictionary
				 */
				template <typename K, typename V>
				struct HashNode {

					K Key;
					V Value;
					HashNode * Next;

					HashNode(K Key, V Value) {
						this->Key = Key;
						this->Value = Value;
						this->Next = NULL;
					}

					K getKey() {
						return this->Key;
					}

					V getValue() {
						return this->Value;
					}

					HashNode* getNext()
					{
						return this->Next;
					}
				};

				/**
				 * Dictionary reprezentovaný skrze HashTable
				 */
				template <class K, class V> class Dictionary
				{
				public:
					/**
					 * Konstruktor
					 */
					Dictionary();

					/**
					 * Destruktor
					 */
					~Dictionary();

					/**
					 * Metoda pro vložení prvku do slovníku
					 * @param Key klíè vkládaného prvku, tento klíè se pøed vložením zhašuje
					 * @param Value Hodnota vkládaného prvku
					 */
					void Insert(const K& Key, const V& Value);

					
					/**
					 * Metoda pro získání hodnoty HashNode podle daného klíèe
					 * @param Key klíè, podle kterého se vyhledává prvek
					 * @return vrací generickou hodnotu HashNode
					 */
					V Get(const K& Key);

					/**
					 * Metoda pro odebrání prvku ze slovníku
					 * @param Key klíè, dle kterého se odebírá
					 */
					void Remove(const K& Key);

					/**
					* Metoda pro spoèítání prvkù ve slovníku
					* @return vrací poèet prvkù
					*/
					int Count();

					/**
					* Metoda pro zjištìní, zda je množina prázdná
					* @return vrací true pokud je prázdná, jinak false
					*/
					bool IsEmpty();

					/**
					 * Pomocná metoda pro výpis
					 */
					void Report();
					
				private:

					/**
					 * Promìnná reprezentující poèet pøihrádek v hashtable
					 */
					int m_size = 128;

					/**
					* Metoda pro zhašování klíèe prvku
					* @param Key hašovaný klíè
					* @return vrací zhašovaný klíè
					*/
					int HashFunc(const K& Key);

					HashNode<K, V>** table;
				};	

				template<typename K, typename V> Dictionary<K, V>::Dictionary()
				{
					table = new HashNode<K, V>*[m_size];
					for (int i = 0; i < m_size; i++)
						table[i] = NULL;
				}

				template<typename K, typename V> Dictionary<K, V>::~Dictionary()
				{
					for (int i = 0; i < m_size; ++i)
					{
						HashNode<K,V>* entry = table[i];
						while (entry != nullptr)
						{
							HashNode<K, V>* prev = entry;
							entry = entry->Next;
							delete prev;
						}
					}
					delete[] table;
				}	
				
				template<typename K, typename V> int Dictionary<K, V>::HashFunc(const K& Key)
				{
					return std::hash<K>()(Key) % m_size; 
				}

				template<typename K, typename V> void Dictionary<K, V>::Insert(const K& Key, const V& Value)
				{
					int hash = HashFunc(Key);
					HashNode<K, V> *prev = nullptr;
					HashNode<K, V> *entry = table[hash];

					while (entry != nullptr && entry->getKey() != Key) 
					{
						prev = entry;
						entry = entry->getNext();
					}

					if (entry == nullptr) 
					{
						entry = new HashNode<K, V>(Key, Value);
						if (prev == nullptr) table[hash] = entry;
						else prev->Next = entry;						
					}
					else entry->Value = Value;
				}

				template<typename K, typename V> V Dictionary<K, V>::Get(const K& Key) 
				{
					int hash = HashFunc(Key);
					HashNode<K, V>* entry = table[hash];
					while (entry != nullptr)
					{
						if (entry->Key == Key)
						{					
							return entry->Value;
						}
						entry = entry->Next;
					}
					return -1;
				}

				template<typename K, typename V> void Dictionary<K, V>::Remove(const K& Key)
				{
					int hash = HashFunc(Key);
					if (table[hash] != NULL) {
						HashNode<K, V>* prevEntry = nullptr;
						HashNode<K, V>* entry = table[hash];
						while (entry->getNext() != NULL && entry->getKey() != Key) {
							prevEntry = entry;
							entry = entry->getNext();
						}
						if (entry->getKey() == Key) {
							if (prevEntry == nullptr) {
								HashNode<K, V>* nextEntry = entry->getNext();
								delete entry;
								table[hash] = nextEntry;
							}
							else {
								HashNode<K, V>* next = entry->getNext();
								delete entry;
								prevEntry->Next = next;
							}
						}
					}
				}

				template<typename K, typename V> int Dictionary<K, V>::Count()
				{
					int count = 0;
					HashNode<K, V>* entry = table[0];
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

				template<typename K, typename V> bool Dictionary<K, V>::IsEmpty()
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

				template<typename K, typename V> void Dictionary<K, V>::Report()
				{
					for(int i = 0; i < m_size; i++)
					{
						if(table[i] != nullptr) std::cout << table[i]->getKey() << " : " << table[i]->getValue() << " : " << table[i]->getNext() << std::endl;
					}
				}
			}
		}
	}
}
