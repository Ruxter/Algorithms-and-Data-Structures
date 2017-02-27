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
					 * Metoda pro zhašování klíèe prvku
					 * @param Key hašovaný klíè
					 * @return vrací zhašovaný klíè
					 */
					int HashFunc(const K& Key);

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
					 * Pomocná metoda pro výpis
					 */
					void Report();
					
				private:

					/**
					 * Promìnná reprezentující poèet pøihrádek v hashtable
					 */
					int m_size = 128;

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
						while (entry != NULL)
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
					int hashValue = HashFunc(Key);
					if (table[hashValue] == NULL)
						table[hashValue] = new HashNode<K, V>(Key, Value);
					else {
						HashNode<K, V> *entry = table[hashValue];
						while (entry->getNext() != NULL)
							entry = entry->getNext();
						if (entry->getKey() == Key)
							entry->Value = Value;
						else
							entry->Next = new HashNode<K, V>(Key, Value);
					}
				}

				template<typename K, typename V> V Dictionary<K, V>::Get(const K& Key) 
				{
					int hashValue = HashFunc(Key);
					HashNode<K, V>* entry = table[hashValue];
					while (entry != NULL)
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
					int hashValue = HashFunc(Key);
					if (table[hashValue] != NULL) {
						HashNode<K, V>* prevEntry = NULL;
						HashNode<K, V>* entry = table[hashValue];
						while (entry->getNext() != NULL && entry->getKey() != Key) {
							prevEntry = entry;
							entry = entry->getNext();
						}
						if (entry->getKey() == Key) {
							if (prevEntry == NULL) {
								HashNode<K, V>* nextEntry = entry->getNext();
								delete entry;
								table[hashValue] = nextEntry;
							}
							else {
								HashNode<K, V>* next = entry->getNext();
								delete entry;
								prevEntry->Next = next;
							}
						}
					}
				}

				template<typename K, typename V> void Dictionary<K, V>::Report()
				{
					for(int i = 0; i < m_size; i++)
					{
						//Adresy pøihrádek
						std::cout << table[i] <<std::endl;
					}
				}
			}
		}
	}
}
