#pragma once
#include <iostream>
#include <stack>

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Set
			{
				/**
				* SortedSet je uspoøádaná množina realizována jako binární vyhledávací strom.
				*/
				template <class T> class SortedSet
				{
				public:					

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
					void Add(const T& key);

					/**
					* Metoda pro odebrání prvku množiny
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
					bool Contains(const T& key) const;

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

					/**
					* Metoda pro prùnik dvou množin
					* @param set je vstupní množina, se kterou se provede prùnik
					* @param setOut je výstupní množina po provedení operace
					*/
					void Intersect(const SortedSet* set, SortedSet* setOut);

					/**
					* Metoda pro sjednocení dvou množin
					* @param set je vstupní množina, se kterou se provede prùnik
					* @param setOut je výstupní množina po provedení operace
					*/
					void Union(SortedSet* set,  SortedSet* setOut);

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
					* @param newNode reprezentuje nový element
					* @param sourceNode reprezentuje zdrojový element
					*/
					void CopyTree(Node*& newNode, Node*& sourceNode);

					/**
					* Privátní rekurzivní metoda pro vložení prvku na správné místo v množinì
					* @param key reprezentuje hodnotu prvku
					* @param root reprezentuje element, který se rekurzivnì pøedává
					*/
					Node* Add(Node* root, const T& key);

					/**
					* Privátní rekurzivní metoda pro odebrání prvku z množiny a nahrazení tohoto místa vhodným prvkem 
					* @param node reprezentuje element, který se rekurzivnì pøedává
					* @param key reprezentuje hodnotu prvku 
					* @return Node* vrací výsledný prvek, který se dále rekurzivnì pøedává
					*/
					Node* Remove(Node* node, const T& key);				

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
					bool Contains(const Node* node, const T& key) const;

					/**
					* Privátní rekurzivní metoda pro zjištìní nejpravìjšího prvku v levém podstromu
					* @param node reprezentuje element, který se rekurzivnì prochází jeden po druhém
					* @return prvek nutný pro další rekurze
					*/
					Node* FindMax(Node* node);

					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat z množiny v poøadí inorder
					* @param node reprezentuje element, který se rekurzivnì prochází jeden po druhém
					*/
					void InOrder(Node* node);
					
					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat z množiny v poøadí preoder
					* @param node reprezentuje element, který se rekurzivnì prochází jeden po druhém
					*/
					void PreOrder(const Node* node);

					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat z množiny v poøadí postorder
					* @param node reprezentuje element, který se rekurzivnì prochází jeden po druhém
					*/
					void PostOrder(const Node* node);

					/**
					* Pomocný zásobník pro práci s množinami
					*/
					std::stack<T> stack;
				};

				template<typename T> SortedSet<T>::SortedSet()
				{
					m_root = nullptr;
				}

				template<typename T> SortedSet<T>::SortedSet(const SortedSet& set)
				{
					if (set->m_root == nullptr)
						m_root = nullptr;
					else
						CopyTree(this->m_root, set->m_root);
				}

				template<typename T> void SortedSet<T>::CopyTree(Node *& newNode, Node *& sourceNode)
				{
					if (sourceNode == nullptr) newNode = nullptr;
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
					Clear(m_root);
				}

				template<typename T> void SortedSet<T>::Add(const T& key)
				{
					if (m_root != nullptr)
						Add(m_root, key);
					else
					{
						m_root = new Node();
						m_root->Key = key;
						m_root->Left = nullptr;
						m_root->Right = nullptr;
					}
				}

				template<typename T> typename SortedSet<T>::Node* SortedSet<T>::Add(Node* node, const T& Key)
				{
					if (node == nullptr) {
						node = new Node();
						node->Key = Key;
						node->Left = node->Right = nullptr;
					}
					else if (Key == node->Key) return node;
					else if (Key < node->Key) {
						node->Left = Add(node->Left, Key);
					}
					else {
						node->Right = Add(node->Right, Key);
					}
					return node;
				}	
				
				template<typename T> void SortedSet<T>::Remove(const T& Key)
				{
					Remove(m_root, Key);
				}

				template<typename T> typename SortedSet<T>::Node* SortedSet<T>::Remove(Node* node, const T& Key)
				{
					if (node == nullptr) return node;
					if (Key < node->Key) node->Left = Remove(node->Left, Key);
					else if (Key > node->Key) node->Right = Remove(node->Right, Key);
					else{
						if (node->Right == nullptr && node->Left == nullptr) // Bez potomka
						{
							delete node;
							node = nullptr;
						}
						else if (node->Right == nullptr) // Jen levý potomek
						{
							Node* temp = node;
							node = node->Left;
							delete temp;
						}
						else if (node->Left == nullptr) // Jen pravý potomek
						{
							Node* temp = node;
							node = node->Right;
							delete temp;
						}
						else
						{ // Oba potomci
							Node* temp = FindMax(node->Left);
							node->Key = temp->Key;
							node->Left = Remove(node->Left, temp->Key);
						}
					}
					return node;
				}				

				template <typename T> typename SortedSet<T>::Node* SortedSet<T>::FindMax(Node* root)
				{
					if (root == nullptr) return nullptr;
					while (root->Right != nullptr)
					{
						root = root->Right;
					}
					return root;
				}

				template<typename T> bool SortedSet<T>::Contains(const T& key) const
				{
					return Contains(m_root, key);
				}

				template<typename T> bool SortedSet<T>::Contains(const Node* node, const T& key) const
				{
					if (node == nullptr) return false;
					if (key == node->Key) return true;
					if (key < node->Key)  return Contains(node->Left, key);
					return Contains(node->Right, key);
				}

				template<typename T> int SortedSet<T>::Size()
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
					return m_root == nullptr;
				}

				template<typename T> void SortedSet<T>::Clear()
				{
					Clear(m_root);
					m_root = nullptr;
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

				template <class T> void SortedSet<T>::InOrder(Node* node)
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
						stack.push(node->Key); // Slouží k Intersection a Union množin
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

				template <class T> void SortedSet<T>::Intersect(const SortedSet* set, SortedSet* setOut)
				{
					PreOrder(m_root);
					T tmp; 
					for (unsigned int i = 0; i < stack.size(); i++)
					{
						tmp = stack.top();
						if (set->Contains(tmp))
						{
							setOut->Add(tmp);
							stack.pop();
							i--;
						}
						else {
							stack.pop();
							i--;
						}
					}
				}

				template <class T> void SortedSet<T>::Union(SortedSet* set, SortedSet* newTable)
				{
					PreOrder(m_root);
					T tmp;
					CopyTree(newTable->m_root, set->m_root);
					for (unsigned int i = 0; i < stack.size(); i++)
					{
						tmp = stack.top();
						newTable->Add(tmp);
						stack.pop();
						i--;
					}
				}
			}
		}
	}
}
