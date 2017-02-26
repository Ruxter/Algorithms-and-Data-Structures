#pragma once
#include <wchar.h>
namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Dictionary
			{				
				template <class K, class T> class SortedDictionary
				{
				public:

					/**
					 * Konstruktor
					 */
					SortedDictionary();

					/**
					* Destruktor
					*/
					~SortedDictionary();

					/**
					* Metoda pro pøidání prvku, jeden prvek nese klíè a hodnotu
					* @param Key klíè prvku
					* @param Value hodnota prvku
					*/
					void Add(const K& Key, const T& Value);

					/**
					* Metoda pro odebrání prvku do množiny
					* @param Key hodnota odebíraného prvku
					*/
					void Remove(const K& Key);

					/**
					* Metoda pro zjištìní velikosti množiny
					* @return poèet prvkù
					*/
					int Size();

					/**
					* Metoda pro zjištìní existence daného prvku v množinì
					* @param Key klíè vyhledávaného prvku
					* @return true pokud existuje, jinak false
					*/
					bool ContainsKey(const K& Key);

					/**
					* Metoda pro zjištìní, zda je množina prázdná
					* @return true pokud ano, jinak false
					*/
					bool IsEmpty() const;

					/**
					* Metoda pro dealokaci slovníku
					*/
					void Clear();

					/**
					* Metoda pro vypsání množiny v poøadí inorder
					*/
					void InOrder();

					/**
					* Metoda pro vypsání množiny v poøadí preorder
					*/
					void PreOrder();

					/**
					* Metoda pro vypsání množiny v poøadí postorder
					*/
					void PostOrder();
					

				private:
					
					struct Pair
					{
						K Key;

						T Value;

						Pair* Left;

						Pair* Right;
					};

					Pair* m_root;

					Pair* Add(Pair* pair, const K& Key, const T& Value);

					/**
					* Privátní rekurzivní metoda pro odebrání prvku z množiny a nahrazení tohoto místa vhodným prvkem
					* @param pair reprezentuje element, který se rekurzivnì pøedává
					* @param Key reprezentuje hodnotu prvku
					* @return Node* vrací výsledný prvek, který se dále rekurzivnì pøedává
					*/
					Pair* Remove(Pair* pair, const K& Key);

					/**
					* Privátní rekurzivní metoda pro korektní odebrání všech prkù z množiny a jejich dealokace
					* @param pair reprezentuje element, který se rekurzivnì pøedává jeden po druhém
					*/
					void Clear(const Pair* pair);

					/**
					* Privátní rekurzivní metoda pro spoèítání prvkù v množinì
					* @param pair reprezentuje element, který se rekurzivnì poèítá jeden po druhém
					* @return poèet prvkù
					*/
					int Size(const Pair* pair);

					/**
					* Privátní rekurzivní metoda pro zjištìní existence prvku v množinì
					* @param pair reprezentuje element, který se rekurzivnì prochází jeden po druhém
					* @param Key klíè prvku v množinì
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool ContainsKey(const Pair* pair, const K& Key);

					/**
					* Privátní rekurzivní metoda pro zjištìní nejpravìjšího prvku v levém podstromu
					* @param pair reprezentuje element, který se rekurzivnì prochází jeden po druhém
					* @return prvek nutný pro další rekurze
					*/
					Pair* FindMax(Pair* pair);

					void InOrder(const Pair* pair);

					void PreOrder(const Pair* pair);

					void PostOrder(const Pair* pair);

				};

				template<typename K, typename T> SortedDictionary<K, T>::SortedDictionary()
				{
					m_root = NULL;
				}

				template<typename K, typename T> SortedDictionary<K, T>::~SortedDictionary()
				{
					Clear();
				}

				template<typename K, typename T> void SortedDictionary<K, T>::Add(const K& Key, const T& Value)
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

				template<typename K, typename T> typename SortedDictionary<K, T>::Pair* SortedDictionary<K, T>::Add(Pair* pair, const K& Key, const T& Value)
				{
					if (pair == NULL) {
						pair = new Pair();
						pair->Key = Key;
						pair->Value = Value;
						pair->Left = pair->Right = NULL;
					}
					else if (Key <= pair->Key) {
						pair->Left = Add(pair->Left, Key, Value);
					}
					else {
						pair->Right = Add(pair->Right, Key, Value);
					}
					return pair;
				}

				template<typename K, typename T> void SortedDictionary<K, T>::Remove(const K& Key)
				{
					Remove(m_root, Key);
				}

				template<typename K, typename T> typename SortedDictionary<K, T>::Pair* SortedDictionary<K, T>::Remove(Pair* pair, const K& Key)
				{
					if (pair == NULL) return pair;
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

				template <typename K, typename T> typename SortedDictionary<K, T>::Pair* SortedDictionary<K, T>::FindMax(Pair* root)
				{
					if (root == NULL) return NULL;
					while (root->Right != NULL)
					{
						root = root->Right;
					}
					return root;
				}

				template<typename K, typename T> bool SortedDictionary<K, T>::ContainsKey(const K& Key)
				{
					return ContainsKey(m_root, Key);
				}

				template<typename K, typename T> bool SortedDictionary<K, T>::ContainsKey(const Pair* pair, const K& Key)
				{
					if (pair == nullptr) return false;
					if (Key == pair->Key) return true;
					if (Key < pair->Key)  return ContainsKey(pair->Left, Key);
					return ContainsKey(pair->Right, Key);
				}

				template<typename K, typename T> int SortedDictionary<K, T>::Size()
				{
					return Size(m_root);
				}

				template<typename K, typename T> int SortedDictionary<K, T>::Size(const Pair* pair)
				{
					if (pair == nullptr)
					{
						return 0;
					}
					return 1 + Size(pair->Left) + Size(pair->Right);
				}

				template<typename K, typename T> bool SortedDictionary<K, T>::IsEmpty() const
				{
					return m_root == NULL;
				}

				template<typename K, typename T> void SortedDictionary<K, T>::Clear()
				{
					Clear(m_root);
					m_root = NULL;
				}

				template<typename K, typename T> void SortedDictionary<K, T>::Clear(const Pair* pair)
				{
					if (pair != nullptr)
					{
						Clear(pair->Left);
						Clear(pair->Right);
						delete pair;
					}
				}

				template <typename K, typename T> void SortedDictionary<K, T>::InOrder()
				{
					InOrder(m_root);
				}

				template <typename K, typename T> void SortedDictionary<K, T>::InOrder(const Pair* node)
				{
					if (node) {
						InOrder(node->Left);
						std::cout << node->Key << " : " << node->Value << std::endl;
						InOrder(node->Right);
					}
				}

				template <typename K, typename T> void SortedDictionary<K, T>::PreOrder()
				{
					PreOrder(m_root);
				}

				template <typename K, typename T> void SortedDictionary<K, T>::PreOrder(const Pair* node)
				{
					if (node) {
						std::cout << node->Key << " : " << node->Value << std::endl;
						PreOrder(node->Left);
						PreOrder(node->Right);
					}
				}

				template <typename K, typename T> void SortedDictionary<K, T>::PostOrder()
				{
					PostOrder(m_root);
				}

				template <typename K, typename T> void SortedDictionary<K, T>::PostOrder(const Pair* node)
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

