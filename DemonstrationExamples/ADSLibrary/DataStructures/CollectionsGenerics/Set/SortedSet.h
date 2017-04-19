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
				* SortedSet je uspo��dan� mno�ina realizov�na jako bin�rn� vyhled�vac� strom.
				*/
				template <class T> class SortedSet
				{
				public:					

					/**
					 * Konstruktor
					 */
					SortedSet();

					/**
					* Kop�rovac� konstruktor
					* 
					* @param set Kop�rovan� mno�ina
					*/
					SortedSet(const SortedSet& set);

					/**
					* Destruktor
					*/
					~SortedSet();

					/**
					* Metoda pro vkl�d�n� prvku do mno�iny
					* 
					* @param Key Hodnota vkl�dan�ho prvku
					*/
					void Add(const T& Key);

					/**
					* Metoda pro odebr�n� prvku mno�iny
					* 
					* @param Key Hodnota odeb�ran�ho prvku
					*/
					void Remove(const T& Key);

					/**
					* Metoda pro zji�t�n� velikosti mno�iny
					* 
					* @return Po�et prvk�
					*/
					int Size();

					/**
					* Metoda pro zji�t�n� existence dan�ho prvku v mno�in�
					* 
					* @param Key Hodnota vyhled�van�ho prvku
					* @return true pokud existuje, jinak false
					*/
					bool Contains(const T& Key) const;

					/**
					* Metoda pro zji�t�n�, zda je mno�ina pr�zdn�
					* 
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

					/**
					* Metoda pro pr�nik dvou mno�in
					* 
					* @param set Vstupn� mno�ina, se kterou se provede pr�nik
					* @param SetOut V�stupn� mno�ina po proveden� operace
					*/
					void Intersect(const SortedSet* set, SortedSet* SetOut);

					/**
					* Metoda pro sjednocen� dvou mno�in
					* 
					* @param set Vstupn� mno�ina, se kterou se provede pr�nik
					* @param SetOut V�stupn� mno�ina po proveden� operace
					*/
					void Union(SortedSet* set, SortedSet* SetOut);

				private:
					
					/**
					* Struktura reprezentuj�c� jeden prvek v mno�in�
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
					Node* mRoot;

					/**
					* Priv�tn� rekurzivn� metoda pro zkop�rov�n� mno�iny
					* @param NewNode Reprezentuje nov� element
					* @param SourceNode Reprezentuje zdrojov� element
					*/
					void CopyTree(Node* NewNode, Node* SourceNode);

					/**
					* Priv�tn� rekurzivn� metoda pro vlo�en� prvku na spr�vn� m�sto v mno�in�
					* 
					* @param Key Reprezentuje hodnotu prvku
					* @param Root Reprezentuje element, kter� se rekurzivn� p�ed�v�
					*/
					Node* Add(Node* Root, const T& Key);

					/**
					* Priv�tn� rekurzivn� metoda pro odebr�n� prvku z mno�iny a nahrazen� tohoto m�sta vhodn�m prvkem 
					* 
					* @param node Reprezentuje element, kter� se rekurzivn� p�ed�v�
					* @param Key Reprezentuje hodnotu prvku 
					* @return vrac� v�sledn� prvek, kter� se d�le rekurzivn� p�ed�v�
					*/
					Node* Remove(Node* node, const T& Key);

					/**
					* Priv�tn� rekurzivn� metoda pro korektn� odebr�n� v�ech prk� z mno�iny a jejich dealokace
					* 
					* @param Node Reprezentuje element, kter� se rekurzivn� p�ed�v� jeden po druh�m
					*/
					void Clear(const Node* Node);

					/**
					* Priv�tn� rekurzivn� metoda pro spo��t�n� prvk� v mno�in�
					* 
					* @param Node Reprezentuje element, kter� se rekurzivn� po��t� jeden po druh�m
					* @return po�et prvk�
					*/
					int Size(const Node* Node);

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� existence prvku v mno�in�
					* 
					* @param Node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @param Key Hodnota hledan�ho prvku v mno�in�
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool Contains(const Node* Node, const T& Key) const;

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� nejprav�j��ho prvku v lev�m podstromu
					* 
					* @param Node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @return prvek nutn� pro dal�� rekurze
					*/
					Node* FindMax(Node* Node);

					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat z mno�iny v po�ad� inorder
					* 
					* @param Node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void InOrder(Node* Node);
					
					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat z mno�iny v po�ad� preoder
					* 
					* @param Node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void PreOrder(const Node* Node);

					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat z mno�iny v po�ad� postorder
					* 
					* @param Node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void PostOrder(const Node* Node);

					/**
					* Pomocn� z�sobn�k pro pr�ci s mno�inami
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
						else if (node->Right == nullptr) // Jen lev� potomek
						{
							node = node->Left;
						}
						else if (node->Left == nullptr) // Jen prav� potomek
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
						mStack.push(node->Key); // Slou�� k Intersection a Union mno�in
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
