#pragma once
#include<iostream>
namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Dictionary
			{				
				/**
				* SortedDictionary je uspo��dan� slovn�k/mapa realizov�n/a jako bin�rn� vyhled�vac� strom.
				* Jeden element nazv�n Pair v sob� nese nejen kl��, ale i hodnotu, proto SortedDictionary<K, V>
				*/
				template <class K, class V> class SortedDictionary
				{
				public:
					
					/**
					 * Konstruktor
					 */
					SortedDictionary();

					/**
					* Kop�rovac� konstruktor
					*/
					SortedDictionary(const SortedDictionary& dic);

					/**
					* Destruktor
					*/
					~SortedDictionary();

					/**
					* Metoda pro vkl�d�n� prvku do slovn�ku
					* @param Key kl�� elementu
					* @param Value hodnota elementu
					*/
					void Add(const K& Key, const V& Value);

					/**
					* Metoda pro odebr�n� elementu ze slovn�ku
					* @param Key hodnota odeb�ran�ho elementu
					*/
					void Remove(const K& Key);

					/**
					* Metoda pro zji�t�n� velikosti slovn�ku
					* @return po�et element�
					*/
					int Size();

					/**
					* Metoda pro zji�t�n� existence dan�ho elementu ve slovn�ku
					* @param Key kl�� vyhled�van�ho elementu
					* @return true pokud existuje, jinak false
					*/
					bool Contains(const K& Key);

					/**
					* Metoda pro zji�t�n�, zda je slovn�k pr�zdn�
					* @return true pokud ano, jinak false
					*/
					bool IsEmpty() const;

					/**
					* Metoda pro dealokaci slovn�ku
					*/
					void Clear();

					/**
					* Metoda pro vyps�n� slovn�ku v po�ad� inorder
					*/
					void InOrder();

					/**
					* Metoda pro vyps�n� slovn�ku v po�ad� preorder
					*/
					void PreOrder();

					/**
					* Metoda pro vyps�n� slovn�ku v po�ad� postorder
					*/
					void PostOrder();
					

				private:
					
					/**
					 * Reprezentuje jeden element slovn�ku
					 */
					struct Pair
					{
						K Key;

						V Value;

						Pair* Left;

						Pair* Right;
					};

					/**
					* Ko�en stromu
					*/
					Pair* mRoot;

					/**
					* Priv�tn� rekurzivn� metoda pro vlo�en� elementu na spr�vn� m�sto ve slovn�ku
					* @param pair Element, kter� se rekurzivn� p�ed�v�
					* @param Key Reprezentuje kl�� prvku
					* @param Value Reprezentuje hodnotu prvku
					*/
					Pair* Add(Pair*& pair, const K& Key, const V& Value);

					/**
					* Priv�tn� rekurzivn� metoda pro zkop�rov�n� slovn�ku
					* @param newNode Reprezentuje nov� element
					* @param sourceNode Reprezentuje zdrojov� element
					*/
					void CopyTree(Pair*& newNode, Pair*& sourceNode);

					/**
					* Priv�tn� rekurzivn� metoda pro odebr�n� prvku ze slovn�ku a nahrazen� tohoto m�sta vhodn�m prvkem
					* @param pair Reprezentuje element, kter� se rekurzivn� p�ed�v�
					* @param Key Reprezentuje hodnotu prvku
					* @return Node* Vrac� v�sledn� prvek, kter� se d�le rekurzivn� p�ed�v�
					*/
					Pair* Remove(Pair* pair, const K& Key);

					/**
					* Priv�tn� rekurzivn� metoda pro korektn� odebr�n� v�ech element� ze slovn�ku a jejich dealokace
					* @param pair Reprezentuje element, kter� se rekurzivn� p�ed�v� jeden po druh�m
					*/
					void Clear(const Pair* pair);

					/**
					* Priv�tn� Rekurzivn� metoda pro spo��t�n� element� ve slovn�ku
					* @param pair Reprezentuje element, kter� se rekurzivn� po��t� jeden po druh�m
					* @return Po�et prvk�
					*/
					int Size(const Pair* pair);

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� existence elementu ve slovn�ku
					* @param pair Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @param Key Kl�� prvku ve slovn�ku
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool Contains(const Pair* pair, const K& Key);

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� nejprav�j��ho prvku v lev�m podstromu
					* @param pair Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @return prvek nutn� pro dal�� rekurze
					*/
					Pair* FindMax(Pair* pair);

					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat ze slovn�ku v po�ad� inorder
					* @param pair Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void InOrder(const Pair* pair);
					
					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat ze slovn�ku v po�ad� preoder
					* @param pair Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void PreOrder(const Pair* pair);

					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat ze slovn�ku v po�ad� postorder
					* @param pair Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void PostOrder(const Pair* pair);

				};

				template<typename K, typename V> SortedDictionary<K, V>::SortedDictionary()
				{
					mRoot = nullptr;
				}

				template<typename K, typename V> SortedDictionary<K, V>::SortedDictionary(const SortedDictionary& dic)
				{
					if (dic->mRoot == nullptr) mRoot = nullptr;
					else CopyTree(this->mRoot, dic->mRoot);
				}

				template<typename K, typename V> void SortedDictionary<K, V>::CopyTree(Pair*& newNode, Pair*& sourceNode)
				{
					if (sourceNode == nullptr) newNode = nullptr;
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
					if (mRoot != nullptr)
						Add(mRoot, Key, Value);
					else
					{
						mRoot = new Pair();
						mRoot->Key = Key;
						mRoot->Value = Value;
						mRoot->Left = nullptr;
						mRoot->Right = nullptr;
					}
				}

				template<typename K, typename V> typename SortedDictionary<K, V>::Pair* SortedDictionary<K, V>::Add(Pair*& pair, const K& Key, const V& Value)
				{
					if (pair == nullptr) {
						pair = new Pair();
						pair->Key = Key;
						pair->Value = Value;
						pair->Left = pair->Right = nullptr;
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
					Remove(mRoot, Key);
				}

				template<typename K, typename V> typename SortedDictionary<K, V>::Pair* SortedDictionary<K, V>::Remove(Pair* pair, const K& Key)
				{
					if (pair == nullptr) return pair;
					if (Key < pair->Key) pair->Left = Remove(pair->Left, Key);
					else if (Key > pair->Key) pair->Right = Remove(pair->Right, Key);
					else {
						if (pair->Right == nullptr && pair->Left == nullptr) // Bez potomka
						{
							delete pair;
							pair = nullptr;
						}
						else if (pair->Right == nullptr) // Jen lev� potomek
						{
							Pair* temp = pair;
							pair = pair->Left;
							delete temp;
						}
						else if (pair->Left == nullptr) // Jen prav� potomek
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
					while (root->Right != nullptr)
					{
						root = root->Right;
					}
					return root;
				}

				template<typename K, typename V> bool SortedDictionary<K, V>::Contains(const K& Key)
				{
					return Contains(mRoot, Key);
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
					return Size(mRoot);
				}

				template<typename K, typename V> int SortedDictionary<K, V>::Size(const Pair* pair)
				{
					if (pair == nullptr) return 0;
					return 1 + Size(pair->Left) + Size(pair->Right);
				}

				template<typename K, typename V> bool SortedDictionary<K, V>::IsEmpty() const
				{
					return mRoot == nullptr;
				}

				template<typename K, typename V> void SortedDictionary<K, V>::Clear()
				{
					Clear(mRoot);
					mRoot = nullptr;
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
					InOrder(mRoot);
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
					PreOrder(mRoot);
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
					PostOrder(mRoot);
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

