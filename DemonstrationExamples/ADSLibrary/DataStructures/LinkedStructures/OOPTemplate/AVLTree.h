#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOPTemplate
			{
				/**
				 * AVL-strom s vyvaovacím faktorem na kadém uzlu, tudí není potøeba po kadé operaci zjišovat u všech uzlù jejich vyváenost.
				 */
				template <typename T>
				class AVLTree
				{
				public:
					/**
					 * Konstruktor
					 */
					AVLTree();

					/**
					* Destruktor
					*/
					~AVLTree();

					/**
					* Metoda pro pøidání prvku
					* @param X Vkládanı prvek
					*/
					void Insert(const T& X);

					/**
					* Metoda pro odebrání prvku
					* @param X Odebíranı prvek
					*/
					void Delete(const T& X);

					/**
					* Metoda pro zjištìní, zda je AVL strom prázdnı
					* @return true pokud ano, jinak false
					*/
					bool IsEmpty() const;

					/**
					* Metoda pro zjištìní existence daného prvku v AVL stromu
					* @param X Hodnota vyhledávaného prvku
					* @return true pokud existuje, jinak false
					*/
					bool Contains(const T& X) const;

					/**
					* Metoda pro zjištìní velikosti AVL stromu
					* @return Poèet prvkù
					*/
					int Size();

					/**
					* Metoda pro vypsání AVL stromu v poøadí inorder
					*/
					void InOrder();

					/**
					* Metoda pro vypsání AVL stromu v poøadí preorder
					*/
					void PreOrder();

					/**
					* Metoda pro vypsání AVL stromu v poøadí postorder
					*/
					void PostOrder();

				private:

					/**
					* Struktura reprezentující jeden prvek v AVL stromu
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

						/**
						* Vyvaovací faktor
						*/
						int Balance;
					};

					/**
					* Privátní rekurzivní metoda pro korektní odebrání všech prkù z AVL stromu a jejich dealokace
					* @param node Reprezentuje element, kterı se rekurzivnì pøedává jeden po druhém
					*/
					void  Clear(Node* node);

					/**
					* Privátní rekurzivní metoda pro vloení prvku na správné místo v AVL stromu
					* @param node Reprezentuje element, kterı se rekurzivnì pøedává
					* @param X Reprezentuje hodnotu vkládaného prvku
					* @param rebalance Pøíznak urèující, zda má bıt provedeno potenciální vyvaování
					*/
					void  Insert(Node*& node, const T X, bool& rebalance);

					/**
					* Privátní rekurzivní metoda pro odebrání prvku z AVL stromu
					* @param node Reprezentuje element, kterı se rekurzivnì pøedává
					* @param X Reprezentuje hodnotu odebíraného prvku
					* @param rebalance Pøíznak urèující, zda má bıt provedeno potenciální vyvaování
					*/
					void  Delete(Node*& node, const T X, bool& rebalance);

					/**
					 * Metoda pro vyváení stromu pøi odebrání prvku v pøípadì, kdy se zmenší levı podstrom
					 * @param node Reprezentuje element, kterı se rekurzivnì prochází jeden po druhém
					 * @param rebalance Pøíznak urèující, zda má bıt provedeno potenciální vyvaování
					 */
					void  BalanceLeft(Node*& node, bool& rebalance);

					/**
					* Metoda pro vyváení stromu pøi odebrání prvku v pøípadì, kdy se zmenší pravı podstrom
					* @param node Reprezentuje element, kterı se rekurzivnì prochází jeden po druhém
					* @param rebalance Pøíznak urèující, zda má bıt provedeno potenciální vyvaování
					*/
					void  BalanceRight(Node*& node, bool& rebalance);

					/**
					* Pomocná metoda pro Delete
					* Metoda pro nalezení nejpravìjšího potomka v levém podstromu, a nahrazení odebíraného prvku.
					* @param node Reprezentuje element, kterı se rekurzivnì prochází jeden po druhém
					* @param node2 Reprezentuje element, kterı se rekurzivnì prochází jeden po druhém		
					* @param rebalance	Pøíznak urèující, zda má bıt provedeno potenciální vyvaování		
					*/
					void  DeleteWithBothChildren(Node*& node, Node*& node2, bool& rebalance);

					/**
					* Privátní rekurzivní metoda pro zjištìní existence prvku v AVL stromu
					* @param node Reprezentuje element, kterı se rekurzivnì prochází jeden po druhém
					* @param key Hodnota hledaného prvku v AVL stromu
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool Contains(const Node* node, const T& key) const;

					/**
					* Privátní rekurzivní metoda pro spoèítání prvkù v AVL stromu
					* @param node Reprezentuje element, kterı se rekurzivnì poèítá jeden po druhém
					* @return poèet prvkù
					*/
					int Size(const Node* node);

					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat z AVL stromu v poøadí inorder
					* @param node Reprezentuje element, kterı se rekurzivnì prochází jeden po druhém
					*/
					void InOrder(Node* node);

					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat z AVL stromu v poøadí preoder
					* @param node Reprezentuje element, kterı se rekurzivnì prochází jeden po druhém
					*/
					void PreOrder(const Node* node);

					/**
					* Privátní rekurzivní metoda pro získání a vypsání dat z AVL stromu v poøadí postorder
					* @param node Reprezentuje element, kterı se rekurzivnì prochází jeden po druhém
					*/
					void PostOrder(const Node* node);

					Node* mRoot;
				};

				template<class T> AVLTree<T>::AVLTree()
				{
					mRoot = nullptr;
				}

				template<class T> AVLTree<T>::~AVLTree()
				{
					Clear(mRoot);
				}

				template<class T> void AVLTree<T>::Clear(Node* node)
				{
					if (node != nullptr)
					{
						Clear(node->Left);
						Clear(node->Right);
						delete node;
					};  
				}

				template<class T> void AVLTree<T>::Insert(const T& X)
				{
					bool rebalance = false; //pøíznak urèující, zda má bıt provedeno potenciální vyvaování
					Insert(mRoot, X, rebalance);
				}

				template<class T> void AVLTree<T>::Insert(Node*& node, const T X, bool& rebalance)
				{
					Node  *p1, *p2;
					if (node == nullptr)
					{
						node = new Node;
						node->Key = X;
						node->Left = node->Right = nullptr;
						node->Balance = 0;
						rebalance = true; 
						return;
					};
					if (X < node->Key)
					{
						Insert(node->Left, X, rebalance);
						if (rebalance)
						{
							switch (node->Balance)
							{
							case 1: //po pøidání se nevyváenost vyrovnala
								node->Balance = 0;
								rebalance = false;
								break;
							case 0: //po pøidání bude levı podstrom vyšší ne pravı
								node->Balance = -1;
								break;
							case -1: //ji je potøeba vyváit, jeliko poté by byl faktor > -1 to znaèí nevyváenost
								p1 = node->Left;
								if (p1->Balance == -1)
								{// LL
									node->Left = p1->Right;
									p1->Right = node;
									node->Balance = 0;
									node = p1;
								}
								else
								{//  LR
									p2 = p1->Right;
									p1->Right = p2->Left;
									p2->Left = p1;
									node->Left = p2->Right;
									p2->Right = node;
									node->Balance = (p2->Balance == -1) ? +1 : 0;
									p1->Balance = (p2->Balance == +1) ? -1 : 0;
									node = p2;
								};
								node->Balance = 0;
								rebalance = false;
								break;
							default: break;
							};
						};
						return;
					};
					if (X > node->Key)
					{
						Insert(node->Right, X, rebalance);
						if (rebalance)
						{
							switch (node->Balance)
							{
							case -1:
								node->Balance = 0;
								rebalance = false;
								break;
							case 0:
								node->Balance = +1;
								break;
							case +1:
								p1 = node->Right;
								if (p1->Balance == +1)
								{//  RR
									node->Right = p1->Left;
									p1->Left = node;
									node->Balance = 0;
									node = p1;
								}
								else
								{//  RL
									p2 = p1->Left;
									p1->Left = p2->Right;
									p2->Right = p1;
									node->Right = p2->Left;
									p2->Left = node;
									node->Balance = (p2->Balance == +1) ? -1 : 0;
									p1->Balance = (p2->Balance == -1) ? +1 : 0;
									node = p2;
								};
								node->Balance = 0;
								rebalance = false;
								break;
							default: break;
							};
						};
						return;
					};					
					rebalance = false;
				}

				template<class T> void AVLTree<T>::Delete(const T& X)
				{
					bool rebalance = false; //pøíznak urèující, zda má bıt provedeno potenciální vyvaování
					Delete(mRoot, X, rebalance);
				}

				template<class T> void AVLTree<T>::Delete(Node*& node, const T X, bool& rebalance)
				{
					if (node == nullptr) rebalance = false; //pokud prvek neexistuje
					else
						if (X < node->Key)
						{
							Delete(node->Left, X, rebalance);
							if (rebalance) BalanceLeft(node, rebalance);
						}
						else
							if (X > node->Key)
							{
								Delete(node->Right, X, rebalance);
								if (rebalance) BalanceRight(node, rebalance);
							}
							else
							{//pokud prvek existuje
								Node  *q = node;
								if (q->Right == nullptr)//jen levı potomek
								{
									node = q->Left;
									rebalance = true;
								}
								else
									if (q->Left == nullptr) //jen pravı potomek
									{
										node = q->Right;
										rebalance = true;
									}
									else //oba potomci
									{
										DeleteWithBothChildren(q->Left, q, rebalance);
										if (rebalance) BalanceLeft(node, rebalance);
									};
								delete q;
							};
				}

				template<class T> void AVLTree<T>::BalanceLeft(Node*& node, bool& rebalance)
				{
					Node *p1, *p2;
					int b1, b2;
					switch (node->Balance)
					{
					case -1:
						node->Balance = 0;
						break;
					case 0:
						node->Balance = +1;
						rebalance = false;
						break;
					case 1:
						p1 = node->Right;
						b1 = p1->Balance;
						if (b1 >= 0)
						{// RR rotace
							node->Right = p1->Left;
							p1->Left = node;
							if (b1 == 0)
							{
								node->Balance = +1;
								p1->Balance = -1;
								rebalance = false;
							}
							else
							{
								node->Balance = 0;
								p1->Balance = 0;
							};
							node = p1;
						}
						else
						{// RL
							p2 = p1->Left;
							b2 = p2->Balance;
							p1->Left = p2->Right;
							p2->Right = p1;
							node->Right = p2->Left;
							p2->Left = node;
							node->Balance = (b2 == +1) ? -1 : 0;
							p1->Balance = (b2 == -1) ? +1 : 0;
							node = p2;
							p2->Balance = 0;
						};
						break;
					default: break;
					};
				}

				template<class T> void AVLTree<T>::BalanceRight(Node*& node, bool& rebalance)
				{
					Node *p1, *p2;
					int b1, b2;
					switch (node->Balance)
					{
					case 1:
						node->Balance = 0;
						break;
					case 0:
						node->Balance = -1;
						rebalance = false;
						break;
					case -1:
						p1 = node->Left;
						b1 = p1->Balance;
						if (b1 == -1)
						{//  LL
							node->Left = p1->Right;
							p1->Right = node;
							if (b1 == 0)
							{
								node->Balance = -1;
								p1->Balance = +1;
								rebalance = false;
							}
							else
							{
								node->Balance = 0;
								p1->Balance = 0;
							};
							node = p1;
						}
						else
						{// LR
							p2 = p1->Right;
							b2 = p2->Balance;
							p1->Right = p2->Left;
							p2->Left = p1;
							node->Left = p2->Right;
							p2->Right = node;
							node->Balance = (b2 == -1) ? +1 : 0;
							p1->Balance = (b2 == +1) ? -1 : 0;
							node = p2;
							p2->Balance = 0;
						};
					default: break;
					};
				}

				template<class T> void AVLTree<T>::DeleteWithBothChildren(Node*& node, Node*& node2, bool& rebalance)
				{
					if (node->Right != nullptr)
					{
						DeleteWithBothChildren(node->Right, node2, rebalance);
						if (rebalance) BalanceRight(node, rebalance);
					}
					else
					{
						node2->Key = node->Key;
						node2 = node;
						node = node->Left;
						rebalance = true;
					};
				}

				template<typename T> bool AVLTree<T>::IsEmpty() const
				{
					return mRoot == nullptr;
				}

				template<typename T> bool AVLTree<T>::Contains(const T& key) const
				{
					return Contains(mRoot, key);
				}

				template<typename T> bool AVLTree<T>::Contains(const Node* node, const T& key) const
				{
					if (node == nullptr) return false;
					if (key == node->Key) return true;
					if (key < node->Key)  return Contains(node->Left, key);
					return Contains(node->Right, key);
				}

				template<typename T> int AVLTree<T>::Size()
				{
					return Size(mRoot);
				}

				template<typename T> int AVLTree<T>::Size(const Node* node)
				{
					if (node == nullptr)
					{
						return 0;
					}
					return 1 + Size(node->Left) + Size(node->Right);
				}

				template <class T> void AVLTree<T>::InOrder()
				{
					InOrder(mRoot);
				}

				template <class T> void AVLTree<T>::InOrder(Node* node)
				{
					if (node) {
						InOrder(node->Left);
						std::cout << node->Key << " ";
						InOrder(node->Right);
					}
				}

				template <class T> void AVLTree<T>::PreOrder()
				{
					PreOrder(mRoot);
				}

				template <class T> void AVLTree<T>::PreOrder(const Node* node)
				{
					if (node) {
						std::cout << node->Key << " ";
						PreOrder(node->Left);
						PreOrder(node->Right);
					}
				}

				template <class T> void AVLTree<T>::PostOrder()
				{
					PostOrder(mRoot);
				}

				template <class T> void AVLTree<T>::PostOrder(const Node* node)
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