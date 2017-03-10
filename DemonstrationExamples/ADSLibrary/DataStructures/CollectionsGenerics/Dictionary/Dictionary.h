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
					* Metoda pro spo��t�n� prvk� ve slovn�ku
					* @return vrac� po�et prvk�
					*/
					int Count();

					/**
					* Metoda pro zji�t�n�, zda je mno�ina pr�zdn�
					* @return vrac� true pokud je pr�zdn�, jinak false
					*/
					bool IsEmpty();

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
