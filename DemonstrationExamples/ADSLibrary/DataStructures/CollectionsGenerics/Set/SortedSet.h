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
					void Add(const T& key);

					/**
					* Metoda pro odebr�n� prvku mno�iny
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
					bool Contains(const T& key) const;

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

					/**
					* Metoda pro pr�nik dvou mno�in
					* @param set je vstupn� mno�ina, se kterou se provede pr�nik
					* @param setOut je v�stupn� mno�ina po proveden� operace
					*/
					void Intersect(const SortedSet* set, SortedSet* setOut);

					/**
					* Metoda pro sjednocen� dvou mno�in
					* @param set je vstupn� mno�ina, se kterou se provede pr�nik
					* @param setOut je v�stupn� mno�ina po proveden� operace
					*/
					void Union(SortedSet* set,  SortedSet* setOut);

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
					* @param newNode reprezentuje nov� element
					* @param sourceNode reprezentuje zdrojov� element
					*/
					void CopyTree(Node*& newNode, Node*& sourceNode);

					/**
					* Priv�tn� rekurzivn� metoda pro vlo�en� prvku na spr�vn� m�sto v mno�in�
					* @param key reprezentuje hodnotu prvku
					* @param root reprezentuje element, kter� se rekurzivn� p�ed�v�
					*/
					Node* Add(Node* root, const T& key);

					/**
					* Priv�tn� rekurzivn� metoda pro odebr�n� prvku z mno�iny a nahrazen� tohoto m�sta vhodn�m prvkem 
					* @param node reprezentuje element, kter� se rekurzivn� p�ed�v�
					* @param key reprezentuje hodnotu prvku 
					* @return Node* vrac� v�sledn� prvek, kter� se d�le rekurzivn� p�ed�v�
					*/
					Node* Remove(Node* node, const T& key);				

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
					bool Contains(const Node* node, const T& key) const;

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� nejprav�j��ho prvku v lev�m podstromu
					* @param node reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @return prvek nutn� pro dal�� rekurze
					*/
					Node* FindMax(Node* node);

					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat z mno�iny v po�ad� inorder
					* @param node reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void InOrder(Node* node);
					
					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat z mno�iny v po�ad� preoder
					* @param node reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void PreOrder(const Node* node);

					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat z mno�iny v po�ad� postorder
					* @param node reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void PostOrder(const Node* node);

					/**
					* Pomocn� z�sobn�k pro pr�ci s mno�inami
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
						else if (node->Right == nullptr) // Jen lev� potomek
						{
							Node* temp = node;
							node = node->Left;
							delete temp;
						}
						else if (node->Left == nullptr) // Jen prav� potomek
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
						stack.push(node->Key); // Slou�� k Intersection a Union mno�in
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
