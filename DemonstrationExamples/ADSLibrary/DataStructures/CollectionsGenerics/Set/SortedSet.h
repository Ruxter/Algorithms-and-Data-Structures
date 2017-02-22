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
					 * SortedSet je uspoøádaná množina realizována jako binární vyhledávací strom.
					 */

					/**
					 * Konstruktor
					 */
					SortedSet();

					/**
					* Kopírovací konstruktor
					*/
					SortedSet(const SortedSet& set);

					/**
					* Destruktor
					*/
					~SortedSet();

					/**
					* Metoda pro vkládání prvku do množiny
					* @param key hodnota vkládaného prvku
					*/
					void Insert(const T& key);

					/**
					* Metoda pro odebrání prvku do množiny
					* @param key hodnota odebíraného prvku
					*/
					void Remove(const T& key);

					/**
					* Metoda pro zjištìní velikosti množiny
					* @return poèet prvkù
					*/
					int Size();

					/**
					* Metoda pro zjištìní existence daného prvku v množinì
					* @param key hodnota vyhledávaného prvku
					* @return true pokud existuje, jinak false
					*/
					bool Contains(const T& key);

					/**
					* Metoda pro zjištìní, zda je množina prázdná
					* @return true pokud ano, jinak false
					*/
					bool IsEmpty() const;

					/**
					* Metoda pro dealokaci množiny
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
					
					/**
					* Struktura reprezentující jeden prvek(list) v množinì(BST)
					*/
					struct Node
					{		
						/**
						* Hodnota prvku
						*/
						T Key;
						
						/**
						* Ukazatel na levého potomka
						*/
						Node* Left;
						
						/**
						* Ukazatel na pravého potomka
						*/
						Node* Right;						
					};

					/**
					* Koøen stromu
					*/
					Node* m_root;

					/**
					* Privátní rekurzivní metoda pro zkopírování množiny
					* @param thisRoot reprezentuje nový element
					* @param sourceRoot reprezentuje zdrojový element
					*/
					void CopyTree(Node*& thisRoot, Node*& sourceRoot);

					/**
					* Privátní rekurzivní metoda pro vložení prvku na správné místo v množinì
					* @param key reprezentuje hodnotu prvku
					* @param element reprezentuje element, který se rekurzivnì pøedává
					*/
					void Insert(const T& key, Node* element);

					/**
					* Privátní rekurzivní metoda pro odebrání prvku z množiny a nahrazení tohoto místa vhodným prvkem 
					* @param node reprezentuje element, který se rekurzivnì pøedává
					* @param key reprezentuje hodnotu prvku 
					* @return Node* vrací výsledný prvek, který se dále rekurzivnì pøedává
					*/
					Node* Remove(Node* node, const T& key);
				
					/**
					* Metoda pro korektní odebrání koøene stromu(strom se musí chovat jako množina)
					* @param node reprezentuje element, který se rekurzivnì pøedává
					*/
					void ReplaceRoot(Node* node);

					/**
					* Privátní rekurzivní metoda pro korektní odebrání všech prkù z množiny a jejich dealokace
					* @param node reprezentuje element, který se rekurzivnì pøedává jeden po druhém
					*/
					void Clear(const Node* node);

					/**
					* Privátní rekurzivní metoda pro spoèítání prvkù v množinì
					* @param node reprezentuje element, který se rekurzivnì poèítá jeden po druhém
					* @return poèet prvkù
					*/
					int Size(const Node* node);

					/**
					* Privátní rekurzivní metoda pro zjištìní existence prvku v množinì
					* @param node reprezentuje element, který se rekurzivnì prochází jeden po druhém
					* @param key hodnota prvku v množinì
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool Contains(const Node* node, const T& key);

					/**
					* Privátní rekurzivní metoda pro zjištìní nejlevìjšího prvku v podstromu
					* @param node reprezentuje element, který se rekurzivnì prochází jeden po druhém
					* @return prvek nutný pro další rekurze
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
