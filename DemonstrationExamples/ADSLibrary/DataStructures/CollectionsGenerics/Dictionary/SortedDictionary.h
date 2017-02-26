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
					* Metoda pro p�id�n� prvku, jeden prvek nese kl�� a hodnotu
					* @param Key kl�� prvku
					* @param Value hodnota prvku
					*/
					void Add(const K& Key, const T& Value);

					/**
					* Metoda pro odebr�n� prvku do mno�iny
					* @param Key hodnota odeb�ran�ho prvku
					*/
					void Remove(const K& Key);

					/**
					* Metoda pro zji�t�n� velikosti mno�iny
					* @return po�et prvk�
					*/
					int Size();

					/**
					* Metoda pro zji�t�n� existence dan�ho prvku v mno�in�
					* @param Key kl�� vyhled�van�ho prvku
					* @return true pokud existuje, jinak false
					*/
					bool ContainsKey(const K& Key);

					/**
					* Metoda pro zji�t�n�, zda je mno�ina pr�zdn�
					* @return true pokud ano, jinak false
					*/
					bool IsEmpty() const;

					/**
					* Metoda pro dealokaci slovn�ku
					*/
					void Clear();

					/**
					* Metoda pro vyps�n� mno�iny v po�ad� inorder
					*/
					void InOrder();

					/**
					* Metoda pro vyps�n� mno�iny v po�ad� preorder
					*/
					void PreOrder();

					/**
					* Metoda pro vyps�n� mno�iny v po�ad� postorder
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
					* Priv�tn� rekurzivn� metoda pro odebr�n� prvku z mno�iny a nahrazen� tohoto m�sta vhodn�m prvkem
					* @param pair reprezentuje element, kter� se rekurzivn� p�ed�v�
					* @param Key reprezentuje hodnotu prvku
					* @return Node* vrac� v�sledn� prvek, kter� se d�le rekurzivn� p�ed�v�
					*/
					Pair* Remove(Pair* pair, const K& Key);

					/**
					* Priv�tn� rekurzivn� metoda pro korektn� odebr�n� v�ech prk� z mno�iny a jejich dealokace
					* @param pair reprezentuje element, kter� se rekurzivn� p�ed�v� jeden po druh�m
					*/
					void Clear(const Pair* pair);

					/**
					* Priv�tn� rekurzivn� metoda pro spo��t�n� prvk� v mno�in�
					* @param pair reprezentuje element, kter� se rekurzivn� po��t� jeden po druh�m
					* @return po�et prvk�
					*/
					int Size(const Pair* pair);

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� existence prvku v mno�in�
					* @param pair reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @param Key kl�� prvku v mno�in�
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool ContainsKey(const Pair* pair, const K& Key);

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� nejprav�j��ho prvku v lev�m podstromu
					* @param pair reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @return prvek nutn� pro dal�� rekurze
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
						else if (pair->Right == NULL) // Jen lev� potomek
						{
							Pair* temp = pair;
							pair = pair->Left;
							delete temp;
						}
						else if (pair->Left == NULL) // Jen prav� potomek
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

