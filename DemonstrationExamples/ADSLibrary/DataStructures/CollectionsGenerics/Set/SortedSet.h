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
					* 
					* @param set Kopírovaná množina
					*/
					SortedSet(const SortedSet& set);

					/**
					* Destruktor
					*/
					~SortedSet();

					/**
					* Metoda pro vkládání prvku do množiny
					* 
					* @param Key Hodnota vkládaného prvku
					*/
					void Add(const T& Key);

					/**
					* Metoda pro odebrání prvku množiny
					* 
					* @param Key Hodnota odebíraného prvku
					*/
					void Remove(const T& Key);

					/**
					* Metoda pro zjištìní velikosti množiny
					* 
					* @return Poèet prvkù
					*/
					int Size();

					/**
					* Metoda pro zjištìní existence daného prvku v množinì
					* 
					* @param Key Hodnota vyhledávaného prvku
					* @return true pokud existuje, jinak false
					*/
					bool Contains(const T& Key) const;

					/**
					* Metoda pro zjištìní, zda je množina prázdná
					* 
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
					* 
					* @param set Vstupní množina, se kterou se provede prùnik
					* @param SetOut Výstupní množina po provedení operace
					*/
					void Intersect(const SortedSet* set, SortedSet* SetOut);

					/**
					* Metoda pro sjednocení dvou množin
					* 
					* @param set Vstupní množina, se kterou se provede prùnik
					* @param SetOut Výstupní množina po provedení operace
					*/
					void Union(SortedSet* set, SortedSet* SetOut);

				private:
					
					/**
					* Struktura reprezentující jeden prvek v množinì
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
					Node* mRoot;

					/**
					* Privátní rekurzivní metoda pro zkopírování množiny
					* @param NewNode Reprezentuje nový element
					* @param SourceNode Reprezentuje zdrojový element
					*/
					void CopyTree(Node* NewNode, Node* SourceNode);

					/**
					* Privátní rekurzivní metoda pro vložení prvku na správné místo v množinì
					* 
					* @param Key Reprezentuje hodnotu prvku
					* @param Root Reprezentuje element, který se rekurzivnì pøedává
					*/
					Node* Add(Node* Root, const T& Key);

					/**
					* Privátní rekurzivní metoda pro odebrání prvku z množiny a nahrazení tohoto místa vhodným prvkem 
					* 
					* @param node Reprezentuje element, který se rekurzivnì pøedává
					* @param Key Reprezentuje hodnotu prvku 
					* @return vrací výsledný prvek, který se dále rekurzivnì pøedává
					*/
					Node* Remove(Node* node, const T& Key);

					/**
					* Privátní rekurzivní metoda pro korektní odebrání všech prkù z množiny a jejich dealokace
					* 
					* @param Node Reprezentuje element, který se rekurzivnì pøedává jeden po druhém
					*/
					void Clear(const Node* Node);

					/**
					* Privátní rekurzivní metoda pro spoèítání prvkù v množinì
					* 
					* @param Node Reprezentuje element, který se rekurzivnì poèítá jeden po druhém
					* @return poèet prvkù
					*/
					int Size(const Node* Node);

					/**
					* Privátní rekurzivní metoda pro zjištìní existence prvku v množinì
					* 
					* @param Node Reprezentuje element, který se rekurzivnì prochází jeden po druhém
					* @param Key Hodnota hledaného prvku v množinì
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool Contains(const Node* Node, const T& Key) const;

					/**
					* Privátní rekurzivní metoda pro zjištìní nejpravìjšího prvku v levém podstromu
					* 
					* @param Node Reprezentuje element, který se rekurzivnì prochází jeden po druhém
					* @return prvek nutný pro další rekurze
					*/
					Node* FindMax(Node* Node);

					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat z množiny v poøadí inorder
					* 
					* @param Node Reprezentuje element, který se rekurzivnì prochází jeden po druhém
					*/
					void InOrder(Node* Node);
					
					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat z množiny v poøadí preoder
					* 
					* @param Node Reprezentuje element, který se rekurzivnì prochází jeden po druhém
					*/
					void PreOrder(const Node* Node);

					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat z množiny v poøadí postorder
					* 
					* @param Node Reprezentuje element, který se rekurzivnì prochází jeden po druhém
					*/
					void PostOrder(const Node* Node);

					/**
					* Pomocný zásobník pro práci s množinami
					*/
					std::stack<T> mStack;
				};

				template<typename T> SortedSet<T>::SortedSet()
				{
					mRoot = nullptr;
				}

				template<typename T> SortedSet<T>::SortedSet(const SortedSet& set)
				{
					if (set->mRoot == nullptr)
						mRoot = nullptr;
					else
						CopyTree(this->mRoot, set->mRoot);
				}

				template<typename T> void SortedSet<T>::CopyTree(Node* newNode, Node* sourceNode)
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
					Clear(mRoot);
				}

				template<typename T> void SortedSet<T>::Add(const T& key)
				{
					if (mRoot != nullptr)
						Add(mRoot, key);
					else
					{
						mRoot = new Node();
						mRoot->Key = key;
						mRoot->Left = nullptr;
						mRoot->Right = nullptr;
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
					Remove(mRoot, Key);
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
							node = node->Left;
						}
						else if (node->Left == nullptr) // Jen pravý potomek
						{
							node = node->Right;
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
					return Contains(mRoot, key);
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
					return Size(mRoot);
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
					return mRoot == nullptr;
				}

				template<typename T> void SortedSet<T>::Clear()
				{
					Clear(mRoot);
					mRoot = nullptr;
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
					InOrder(mRoot);
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
					PreOrder(mRoot);
				}

				template <class T> void SortedSet<T>::PreOrder(const Node* node)
				{
					if (node) {
						std::cout << node->Key << " ";
						mStack.push(node->Key); // Slouží k Intersection a Union množin
						PreOrder(node->Left);
						PreOrder(node->Right);
					}
				}

				template <class T> void SortedSet<T>::PostOrder()
				{
					PostOrder(mRoot);
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
					PreOrder(mRoot);
					T tmp; 
					for (unsigned int i = 0; i < mStack.size(); i++)
					{
						tmp = mStack.top();
						if (set->Contains(tmp))
						{
							setOut->Add(tmp);
							mStack.pop();
							i--;
						}
						else {
							mStack.pop();
							i--;
						}
					}
				}

				template <class T> void SortedSet<T>::Union(SortedSet* set, SortedSet* newTable)
				{
					PreOrder(mRoot);
					T tmp;
					CopyTree(newTable->mRoot, set->mRoot);
					for (unsigned int i = 0; i < mStack.size(); i++)
					{
						tmp = mStack.top();
						newTable->Add(tmp);
						mStack.pop();
						i--;
					}
				}
			}
		}
	}
}
