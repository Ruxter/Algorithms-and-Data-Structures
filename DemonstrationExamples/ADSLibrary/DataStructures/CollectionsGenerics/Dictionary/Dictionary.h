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
				 * T��da reprezentuj�c� prvek v Dictionary
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
				 * Dictionary reprezentovan� skrze HashTable
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
					 * Metoda pro vlo�en� prvku do slovn�ku
					 * @param Key kl�� vkl�dan�ho prvku, tento kl�� se p�ed vlo�en�m zha�uje
					 * @param Value Hodnota vkl�dan�ho prvku
					 */
					void Insert(const K& Key, const V& Value);

					/**
					 * Metoda pro zha�ov�n� kl��e prvku
					 * @param Key ha�ovan� kl��
					 * @return vrac� zha�ovan� kl��
					 */
					int HashFunc(const K& Key);

					/**
					 * Metoda pro z�sk�n� hodnoty HashNode podle dan�ho kl��e
					 * @param Key kl��, podle kter�ho se vyhled�v� prvek
					 * @return vrac� generickou hodnotu HashNode
					 */
					V Get(const K& Key);

					/**
					 * Metoda pro odebr�n� prvku ze slovn�ku
					 * @param Key kl��, dle kter�ho se odeb�r�
					 */
					void Remove(const K& Key);

					/**
					 * Pomocn� metoda pro v�pis
					 */
					void Report();
					
				private:

					/**
					 * Prom�nn� reprezentuj�c� po�et p�ihr�dek v hashtable
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
						//Adresy p�ihr�dek
						std::cout << table[i] <<std::endl;
					}
				}
			}
		}
	}
}
