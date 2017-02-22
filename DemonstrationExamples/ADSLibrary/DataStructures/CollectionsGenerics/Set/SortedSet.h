#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Set
			{
				template <class T>
				class SortedSet
				{
				public:
					/**
					 * SortedSet je uspo��dan� mno�ina realizov�na jako bin�rn� vyhled�vac� strom.
					 */

					/**
					 * Konstruktor
					 */
					SortedSet();

					/**
					* Kop�rovac� konstruktor
					*/
					SortedSet(const SortedSet& set);

					/**
					* Destruktor
					*/
					~SortedSet();

					/**
					* Metoda pro vkl�d�n� prvku do mno�iny
					* @param key hodnota vkl�dan�ho prvku
					*/
					void Insert(const T& key);

					/**
					* Metoda pro odebr�n� prvku do mno�iny
					* @param key hodnota odeb�ran�ho prvku
					*/
					void Remove(const T& key);

					/**
					* Metoda pro zji�t�n� velikosti mno�iny
					* @return po�et prvk�
					*/
					int Size();

					/**
					* Metoda pro zji�t�n� existence dan�ho prvku v mno�in�
					* @param key hodnota vyhled�van�ho prvku
					* @return true pokud existuje, jinak false
					*/
					bool Contains(const T& key);

					/**
					* Metoda pro zji�t�n�, zda je mno�ina pr�zdn�
					* @return true pokud ano, jinak false
					*/
					bool IsEmpty() const;

					/**
					* Metoda pro dealokaci mno�iny
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
					
					/**
					* Struktura reprezentuj�c� jeden prvek(list) v mno�in�(BST)
					*/
					struct Node
					{		
						/**
						* Hodnota prvku
						*/
						T Key;
						
						/**
						* Ukazatel na lev�ho potomka
						*/
						Node* Left;
						
						/**
						* Ukazatel na prav�ho potomka
						*/
						Node* Right;						
					};

					/**
					* Ko�en stromu
					*/
					Node* m_root;

					/**
					* Priv�tn� rekurzivn� metoda pro zkop�rov�n� mno�iny
					* @param thisRoot reprezentuje nov� element
					* @param sourceRoot reprezentuje zdrojov� element
					*/
					void CopyTree(Node*& thisRoot, Node*& sourceRoot);

					/**
					* Priv�tn� rekurzivn� metoda pro vlo�en� prvku na spr�vn� m�sto v mno�in�
					* @param key reprezentuje hodnotu prvku
					* @param element reprezentuje element, kter� se rekurzivn� p�ed�v�
					*/
					void Insert(const T& key, Node* element);

					/**
					* Priv�tn� rekurzivn� metoda pro odebr�n� prvku z mno�iny a nahrazen� tohoto m�sta vhodn�m prvkem 
					* @param node reprezentuje element, kter� se rekurzivn� p�ed�v�
					* @param key reprezentuje hodnotu prvku 
					* @return Node* vrac� v�sledn� prvek, kter� se d�le rekurzivn� p�ed�v�
					*/
					Node* Remove(Node* node, const T& key);
				
					/**
					* Metoda pro korektn� odebr�n� ko�ene stromu(strom se mus� chovat jako mno�ina)
					* @param node reprezentuje element, kter� se rekurzivn� p�ed�v�
					*/
					void ReplaceRoot(Node* node);

					/**
					* Priv�tn� rekurzivn� metoda pro korektn� odebr�n� v�ech prk� z mno�iny a jejich dealokace
					* @param node reprezentuje element, kter� se rekurzivn� p�ed�v� jeden po druh�m
					*/
					void Clear(const Node* node);

					/**
					* Priv�tn� rekurzivn� metoda pro spo��t�n� prvk� v mno�in�
					* @param node reprezentuje element, kter� se rekurzivn� po��t� jeden po druh�m
					* @return po�et prvk�
					*/
					int Size(const Node* node);

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� existence prvku v mno�in�
					* @param node reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @param key hodnota prvku v mno�in�
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool Contains(const Node* node, const T& key);

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� nejlev�j��ho prvku v podstromu
					* @param node reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @return prvek nutn� pro dal�� rekurze
					*/
					Node* FindMin(Node* node);

					void InOrder(const Node* node);

					void PreOrder(const Node* node);

					void PostOrder(const Node* node);
				};

				template<typename T> SortedSet<T>::SortedSet()
				{
					m_root = NULL;
				}

				template<typename T> SortedSet<T>::SortedSet(const SortedSet& set)
				{
					if (set->m_root == nullptr)
						m_root = NULL;
					else
						CopyTree(this->m_root, set->m_root);
				}

				template<typename T> void SortedSet<T>::CopyTree(Node *& newNode, Node *& sourceNode)
				{
					if (sourceNode == nullptr) newNode = NULL;
					else
					{
						newNode = new Node();
						newNode->Key = sourceNode->Key;
						CopyTree(newNode->Left, sourceNode->Left);
						CopyTree(newNode->Right, sourceNode->Right);
					}
				}
				
				template<typename T> SortedSet<T>::~SortedSet()
				{
				}

				template<typename T> void SortedSet<T>::Insert(const T& key)
				{
					if (m_root != nullptr)
						Insert(key, m_root);
					else
					{
						m_root = new Node();
						m_root->Key = key;
						m_root->Left = NULL;
						m_root->Right = NULL;
					}
				}

				template<typename T> void SortedSet<T>::Insert(const T& key, Node* node)
				{
					if (key < node->Key)
					{
						if (node->Left != NULL)
							Insert(key, node->Left);
						else
						{
							node->Left = new Node();
							node->Left->Key = key;
							node->Left->Left = NULL;
							node->Left->Right = NULL; 
						}
					}
					else if (key >= node->Key)
					{
						if (node->Right != NULL)
							Insert(key, node->Right);
						else
						{
							node->Right = new Node();
							node->Right->Key = key;
							node->Right->Left = NULL; 
							node->Right->Right = NULL;
						}
					}
				}	
				
				template<typename T> void SortedSet<T>::Remove(const T& key)
				{
					Remove(m_root, key);
				}

				template<typename T> typename SortedSet<T>::Node* SortedSet<T>::Remove(Node* node, const T& Key)
				{
					Node* temp;
					if (node == NULL) return NULL;
					if (Key < node->Key) node->Left = Remove(node->Left, Key);
					if (Key > node->Key) node->Right = Remove(node->Right, Key);
					if (node->Left && node->Right)
					{
						temp = FindMin(node->Right);
						node->Key = temp->Key;
						node->Right = Remove(node->Right, node->Key);
					}
					else
					{
						temp = node;
						if (node->Left == NULL) node = node->Right;
						else if (node->Right == NULL) node = node->Left;
						delete temp;
					}
					return node;
				}


				template <class T> typename SortedSet<T>::Node* SortedSet<T>::FindMin(Node* t)
				{
					if (t == NULL)	return NULL;
					if (t->Left == NULL) return t;
					return FindMin(t->Left);
				}

				template<typename T> void SortedSet<T>::ReplaceRoot(Node* node)
				{	

				}
				

				template<typename T> bool SortedSet<T>::Contains(const T& key)
				{
					return Contains(m_root, key);
				}

				template<typename T> bool SortedSet<T>::Contains(const Node* node, const T& key)
				{
					if (node == nullptr) return false;
					if (key == node->Key) return true;
					if (key < node->Key)  return Contains(node->Left, key);
					return Contains(node->Right, key);
				}

				template<typename T> int  SortedSet<T>::Size()
				{
					return Size(m_root);
				}

				template<typename T> int SortedSet<T>::Size(const Node* node)
				{					
					if (node == nullptr)
					{
						return 0;
					}
					return 1 + Size(node->Left) + Size(node->Right);
				}

				template<typename T> bool SortedSet<T>::IsEmpty() const
				{
					return m_root == NULL;
				}

				template<typename T> void SortedSet<T>::Clear()
				{
					Clear(m_root);
					m_root = NULL;
				}

				template<typename T> void SortedSet<T>::Clear(const Node* node)
				{
					if (node != nullptr)
					{
						Clear(node->Left);
						Clear(node->Right);
						delete node;
					}					
				}

				template <class T> void SortedSet<T>::InOrder()
				{
					InOrder(m_root);
				}

				template <class T> void SortedSet<T>::InOrder(const Node* node)
				{
					if (node) {
						InOrder(node->Left);
						std::cout << node->Key << " ";
						InOrder(node->Right);
					}
				}

				template <class T> void SortedSet<T>::PreOrder()
				{
					PreOrder(m_root);
				}

				template <class T> void SortedSet<T>::PreOrder(const Node* node)
				{
					if (node) {
						std::cout << node->Key << " ";
						PreOrder(node->Left);
						PreOrder(node->Right);
					}
				}

				template <class T> void SortedSet<T>::PostOrder()
				{
					PostOrder(m_root);
				}

				template <class T> void SortedSet<T>::PostOrder(const Node* node)
				{
					if (node) {
						PostOrder(node->Left);
						PostOrder(node->Right);
						std::cout << node->Key << " ";
					}
				}


				

			}
		}
	}
}
