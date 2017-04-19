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

					/**
					 * Kl��
					 */
					K Key;

					/**
					* Hodnota
					*/
					V Value;

					/**
					* Odkaz na dal�� prvek
					*/
					HashNode * Next;

					HashNode(K Key, V Value) {
						this->Key = Key;
						this->Value = Value;
						this->Next = NULL;
					}
				};

				/**
				* Dictionary je NEuspo��dan� slovn�k/mapa realizov�n/a jako hashmTable.
				* Jeden element nazv�n HashNode v sob� nese nejen kl��, ale i hodnotu, proto Dictionary<K, V>
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
					 * 
					 * @param Key kl�� vkl�dan�ho prvku, tento kl�� se p�ed vlo�en�m zha�uje
					 * @param Value Hodnota vkl�dan�ho prvku
					 */
					void Insert(const K& Key, const V& Value);
					
					/**
					 * Metoda pro z�sk�n� hodnoty HashNode podle dan�ho kl��e
					 * 
					 * @param Key kl��, podle kter�ho se vyhled�v� prvek
					 * @return vrac� generickou hodnotu HashNode
					 */
					V Get(const K& Key);

					/**
					 * Metoda pro odebr�n� prvku ze slovn�ku
					 * 
					 * @param Key kl��, dle kter�ho se odeb�r�
					 */
					void Remove(const K& Key);

					/**
					* Metoda pro spo��t�n� prvk� ve slovn�ku
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
					* 
					* @param Key ha�ovan� kl��
					* @return vrac� zha�ovan� kl��
					*/
					int HashFunc(const K& Key);

					/**
					* Reprezentuje ha�ovac� tabulku
					*/
					HashNode<K, V>** mTable;
				};	

				template<typename K, typename V> Dictionary<K, V>::Dictionary()
				{
					mTable = new HashNode<K, V>*[mSize];
					for (int i = 0; i < mSize; i++)
						mTable[i] = NULL;
				}

				template<typename K, typename V> Dictionary<K, V>::~Dictionary()
				{
					for (int i = 0; i < mSize; ++i)
					{
						HashNode<K,V>* entry = mTable[i];
						while (entry != nullptr)
						{
							HashNode<K, V>* prev = entry;
							entry = entry->Next;
							delete prev;
						}
					}
					delete[] mTable;
				}	
				
				template<typename K, typename V> int Dictionary<K, V>::HashFunc(const K& Key)
				{
					return std::hash<K>()(Key) % mSize; 
				}

				template<typename K, typename V> void Dictionary<K, V>::Insert(const K& Key, const V& Value)
				{
					int hash = HashFunc(Key);
					HashNode<K, V> *prev = nullptr;
					HashNode<K, V> *entry = mTable[hash];

					while (entry != nullptr && entry->Key != Key) 
					{
						prev = entry;
						entry = entry->Next;
					}

					if (entry == nullptr) 
					{
						entry = new HashNode<K, V>(Key, Value);
						if (prev == nullptr) mTable[hash] = entry;
						else prev->Next = entry;						
					}
					else entry->Value = Value;
				}

				template<typename K, typename V> V Dictionary<K, V>::Get(const K& Key) 
				{
					int hash = HashFunc(Key);
					HashNode<K, V>* entry = mTable[hash];
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
					if (mTable[hash] != NULL) {
						HashNode<K, V>* prevEntry = nullptr;
						HashNode<K, V>* entry = mTable[hash];
						while (entry->Next != NULL && entry->Key != Key) {
							prevEntry = entry;
							entry = entry->Next;
						}
						if (entry->Key == Key) {
							if (prevEntry == nullptr) {
								HashNode<K, V>* nextEntry = entry->Next;
								delete entry;
								mTable[hash] = nextEntry;
							}
							else {
								HashNode<K, V>* next = entry->Next;
								delete entry;
								prevEntry->Next = next;
							}
						}
					}
				}

				template<typename K, typename V> int Dictionary<K, V>::Count()
				{
					int count = 0;
					HashNode<K, V>* entry = mTable[0];
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

				template<typename K, typename V> bool Dictionary<K, V>::IsEmpty()
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

				template<typename K, typename V> void Dictionary<K, V>::Report()
				{
					for(int i = 0; i < mSize; i++)
					{
						if(mTable[i] != nullptr) std::cout << mTable[i]->Key << " : " << mTable[i]->Value << " : " << mTable[i]->Next << std::endl;
					}
				}
			}
		}
	}
}
