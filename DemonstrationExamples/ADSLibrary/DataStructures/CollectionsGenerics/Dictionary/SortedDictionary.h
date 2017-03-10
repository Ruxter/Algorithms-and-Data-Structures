#pragma once
namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Dictionary
			{				
				template <class K, class V> class SortedDictionary
				{
				public:
					/**
					* SortedDictionary je uspoøádaný slovník/mapa realizován/a jako binární vyhledávací strom.
					* Jeden element nazván Pair v sobì nese nejen klíè, ale i hodnotu, proto SortedDictionary<K, V>
					*/

					/**
					 * Konstruktor
					 */
					SortedDictionary();

					/**
					* Kopírovací konstruktor
					*/
					SortedDictionary(const SortedDictionary& dic);

					/**
					* Destruktor
					*/
					~SortedDictionary();

					/**
					* Metoda pro vkládání prvku do slovníku
					* @param Key klíè elementu
					* @param Value hodnota elementu
					*/
					void Add(const K& Key, const V& Value);

					/**
					* Metoda pro odebrání elementu ze slovníku
					* @param Key hodnota odebíraného elementu
					*/
					void Remove(const K& Key);

					/**
					* Metoda pro zjištìní velikosti slovníku
					* @return poèet elementù
					*/
					int Size();

					/**
					* Metoda pro zjištìní existence daného elementu ve slovníku
					* @param Key klíè vyhledávaného elementu
					* @return true pokud existuje, jinak false
					*/
					bool Contains(const K& Key);

					/**
					* Metoda pro zjištìní, zda je slovník prázdný
					* @return true pokud ano, jinak false
					*/
					bool IsEmpty() const;

					/**
					* Metoda pro dealokaci slovníku
					*/
					void Clear();

					/**
					* Metoda pro vypsání slovníku v poøadí inorder
					*/
					void InOrder();

					/**
					* Metoda pro vypsání slovníku v poøadí preorder
					*/
					void PreOrder();

					/**
					* Metoda pro vypsání slovníku v poøadí postorder
					*/
					void PostOrder();
					

				private:
					
					struct Pair
					{
						K Key;

						V Value;

						Pair* Left;

						Pair* Right;
					};

					/**
					* Koøen stromu
					*/
					Pair* m_root;

					/**
					* Privátní rekurzivní metoda pro vložení elementu na správné místo ve slovníku
					* @param pair element, který se rekurzivnì pøedává
					* @param Key reprezentuje klíè prvku
					* @param Value reprezentuje hodnotu prvku
					*/
					Pair* Add(Pair*& pair, const K& Key, const V& Value);

					/**
					* Privátní rekurzivní metoda pro zkopírování slovníku
					* @param newNode reprezentuje nový element
					* @param sourceNode reprezentuje zdrojový element
					*/
					void CopyTree(Pair*&newNode, Pair*& sourceNode);

					/**
					* Privátní rekurzivní metoda pro odebrání prvku ze slovníku a nahrazení tohoto místa vhodným prvkem
					* @param pair reprezentuje element, který se rekurzivnì pøedává
					* @param Key reprezentuje hodnotu prvku
					* @return Node* vrací výsledný prvek, který se dále rekurzivnì pøedává
					*/
					Pair* Remove(Pair* pair, const K& Key);

					/**
					* Privátní rekurzivní metoda pro korektní odebrání všech elementù ze slovníku a jejich dealokace
					* @param pair reprezentuje element, který se rekurzivnì pøedává jeden po druhém
					*/
					void Clear(const Pair* pair);

					/**
					* Privátní rekurzivní metoda pro spoèítání elementù ve slovníku
					* @param pair reprezentuje element, který se rekurzivnì poèítá jeden po druhém
					* @return poèet prvkù
					*/
					int Size(const Pair* pair);

					/**
					* Privátní rekurzivní metoda pro zjištìní existence elementu ve slovníku
					* @param pair reprezentuje element, který se rekurzivnì prochází jeden po druhém
					* @param Key klíè prvku ve slovníku
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool Contains(const Pair* pair, const K& Key);

					/**
					* Privátní rekurzivní metoda pro zjištìní nejpravìjšího prvku v levém podstromu
					* @param pair reprezentuje element, který se rekurzivnì prochází jeden po druhém
					* @return prvek nutný pro další rekurze
					*/
					Pair* FindMax(Pair* pair);

					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat ze slovníku v poøadí inorder
					* @param pair reprezentuje element, který se rekurzivnì prochází jeden po druhém
					*/
					void InOrder(const Pair* pair);
					
					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat ze slovníku v poøadí preoder
					* @param pair reprezentuje element, který se rekurzivnì prochází jeden po druhém
					*/
					void PreOrder(const Pair* pair);

					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat ze slovníku v poøadí postorder
					* @param pair reprezentuje element, který se rekurzivnì prochází jeden po druhém
					*/
					void PostOrder(const Pair* pair);

				};

				template<typename K, typename V> SortedDictionary<K, V>::SortedDictionary()
				{
					m_root = NULL;
				}

				template<typename K, typename V> SortedDictionary<K, V>::SortedDictionary(const SortedDictionary& dic)
				{
					if (dic->m_root == nullptr) m_root = NULL;
					else CopyTree(this->m_root, dic->m_root);
				}

				template<typename K, typename V> void SortedDictionary<K, V>::CopyTree(Pair*& newNode, Pair*& sourceNode)
				{
					if (sourceNode == nullptr) newNode = NULL;
					else
					{
						newNode = new Pair();
						newNode->Key = sourceNode->Key;
						newNode->Value = sourceNode->Value;
						CopyTree(newNode->Left, sourceNode->Left);
						CopyTree(newNode->Right, sourceNode->Right);
					}
				}

				template<typename K, typename V> SortedDictionary<K, V>::~SortedDictionary()
				{
					Clear();
				}

				template<typename K, typename V> void SortedDictionary<K, V>::Add(const K& Key, const V& Value)
				{
					if (m_root != nullptr)
						Add(m_root, Key, Value);
					else
					{
						m_root = new Pair();
						m_root->Key = Key;
						m_root->Value = Value;
						m_root->Left = NULL;
						m_root->Right = NULL;
					}
				}

				template<typename K, typename V> typename SortedDictionary<K, V>::Pair* SortedDictionary<K, V>::Add(Pair*& pair, const K& Key, const V& Value)
				{
					if (pair == nullptr) {
						pair = new Pair();
						pair->Key = Key;
						pair->Value = Value;
						pair->Left = pair->Right = NULL;
					}
					else if (Key == pair->Key) return pair;
					else if (Key < pair->Key) {
						pair->Left = Add(pair->Left, Key, Value);
					}
					else {
						pair->Right = Add(pair->Right, Key, Value);
					}
					return pair;
				}

				template<typename K, typename V> void SortedDictionary<K, V>::Remove(const K& Key)
				{
					Remove(m_root, Key);
				}

				template<typename K, typename V> typename SortedDictionary<K, V>::Pair* SortedDictionary<K, V>::Remove(Pair* pair, const K& Key)
				{
					if (pair == nullptr) return pair;
					if (Key < pair->Key) pair->Left = Remove(pair->Left, Key);
					else if (Key > pair->Key) pair->Right = Remove(pair->Right, Key);
					else {
						if (pair->Right == NULL && pair->Left == NULL) // Bez potomka
						{
							delete pair;
							pair = NULL;
						}
						else if (pair->Right == NULL) // Jen levý potomek
						{
							Pair* temp = pair;
							pair = pair->Left;
							delete temp;
						}
						else if (pair->Left == NULL) // Jen pravý potomek
						{
							Pair* temp = pair;
							pair = pair->Right;
							delete temp;
						}
						else
						{ // Oba potomci
							Pair* temp = FindMax(pair->Left);
							pair->Key = temp->Key;
							pair->Left = Remove(pair->Left, temp->Key);
						}
					}
					return pair;
				}

				template <typename K, typename V> typename SortedDictionary<K, V>::Pair* SortedDictionary<K, V>::FindMax(Pair* root)
				{
					if (root == nullptr) return nullptr;
					while (root->Right != NULL)
					{
						root = root->Right;
					}
					return root;
				}

				template<typename K, typename V> bool SortedDictionary<K, V>::Contains(const K& Key)
				{
					return Contains(m_root, Key);
				}

				template<typename K, typename V> bool SortedDictionary<K, V>::Contains(const Pair* pair, const K& Key)
				{
					if (pair == nullptr) return false;
					if (Key == pair->Key) return true;
					if (Key < pair->Key)  return Contains(pair->Left, Key);
					return Contains(pair->Right, Key);
				}

				template<typename K, typename V> int SortedDictionary<K, V>::Size()
				{
					return Size(m_root);
				}

				template<typename K, typename V> int SortedDictionary<K, V>::Size(const Pair* pair)
				{
					if (pair == nullptr) return 0;
					return 1 + Size(pair->Left) + Size(pair->Right);
				}

				template<typename K, typename V> bool SortedDictionary<K, V>::IsEmpty() const
				{
					return m_root == nullptr;
				}

				template<typename K, typename V> void SortedDictionary<K, V>::Clear()
				{
					Clear(m_root);
					m_root = NULL;
				}

				template<typename K, typename V> void SortedDictionary<K, V>::Clear(const Pair* pair)
				{
					if (pair != nullptr)
					{
						Clear(pair->Left);
						Clear(pair->Right);
						delete pair;
					}
				}

				template <typename K, typename V> void SortedDictionary<K, V>::InOrder()
				{
					InOrder(m_root);
				}

				template <typename K, typename V> void SortedDictionary<K, V>::InOrder(const Pair* node)
				{
					if (node) {
						InOrder(node->Left);
						std::cout << node->Key << " : " << node->Value << std::endl;
						InOrder(node->Right);
					}
				}

				template <typename K, typename V> void SortedDictionary<K, V>::PreOrder()
				{
					PreOrder(m_root);
				}

				template <typename K, typename V> void SortedDictionary<K, V>::PreOrder(const Pair* node)
				{
					if (node) {
						std::cout << node->Key << " : " << node->Value << std::endl;
						PreOrder(node->Left);
						PreOrder(node->Right);
					}
				}

				template <typename K, typename V> void SortedDictionary<K, V>::PostOrder()
				{
					PostOrder(m_root);
				}

				template <typename K, typename V> void SortedDictionary<K, V>::PostOrder(const Pair* node)
				{
					if (node) {
						PostOrder(node->Left);
						PostOrder(node->Right);
						std::cout << node->Key << " : " << node->Value << std::endl;
					}
				}
			}
		}
	}
}

