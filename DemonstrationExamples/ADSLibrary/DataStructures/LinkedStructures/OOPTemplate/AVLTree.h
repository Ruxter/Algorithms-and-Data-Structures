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
				 * AVL-strom s vyva�ovac�m faktorem na ka�d�m uzlu, tud� nen� pot�eba po ka�d� operaci zji��ovat u v�ech uzl� jejich vyv�enost.
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
					* Metoda pro p�id�n� prvku
					* @param X Vkl�dan� prvek
					*/
					void Insert(const T& X);

					/**
					* Metoda pro odebr�n� prvku
					* @param X Odeb�ran� prvek
					*/
					void Delete(const T& X);

					/**
					* Metoda pro zji�t�n�, zda je AVL strom pr�zdn�
					* @return true pokud ano, jinak false
					*/
					bool IsEmpty() const;

					/**
					* Metoda pro zji�t�n� existence dan�ho prvku v AVL stromu
					* @param X Hodnota vyhled�van�ho prvku
					* @return true pokud existuje, jinak false
					*/
					bool Contains(const T& X) const;

					/**
					* Metoda pro zji�t�n� velikosti AVL stromu
					* @return Po�et prvk�
					*/
					int Size();

					/**
					* Metoda pro vyps�n� AVL stromu v po�ad� inorder
					*/
					void InOrder();

					/**
					* Metoda pro vyps�n� AVL stromu v po�ad� preorder
					*/
					void PreOrder();

					/**
					* Metoda pro vyps�n� AVL stromu v po�ad� postorder
					*/
					void PostOrder();

				private:

					/**
					* Struktura reprezentuj�c� jeden prvek v AVL stromu
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

						/**
						* Vyva�ovac� faktor
						*/
						int Balance;
					};

					/**
					* Priv�tn� rekurzivn� metoda pro korektn� odebr�n� v�ech prk� z AVL stromu a jejich dealokace
					* @param node Reprezentuje element, kter� se rekurzivn� p�ed�v� jeden po druh�m
					*/
					void  Clear(Node* node);

					/**
					* Priv�tn� rekurzivn� metoda pro vlo�en� prvku na spr�vn� m�sto v AVL stromu
					* @param node Reprezentuje element, kter� se rekurzivn� p�ed�v�
					* @param X Reprezentuje hodnotu vkl�dan�ho prvku
					* @param rebalance P��znak ur�uj�c�, zda m� b�t provedeno potenci�ln� vyva�ov�n�
					*/
					void  Insert(Node*& node, const T X, bool& rebalance);

					/**
					* Priv�tn� rekurzivn� metoda pro odebr�n� prvku z AVL stromu
					* @param node Reprezentuje element, kter� se rekurzivn� p�ed�v�
					* @param X Reprezentuje hodnotu odeb�ran�ho prvku
					* @param rebalance P��znak ur�uj�c�, zda m� b�t provedeno potenci�ln� vyva�ov�n�
					*/
					void  Delete(Node*& node, const T X, bool& rebalance);

					/**
					 * Metoda pro vyv�en� stromu p�i odebr�n� prvku v p��pad�, kdy se zmen�� lev� podstrom
					 * @param node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					 * @param rebalance P��znak ur�uj�c�, zda m� b�t provedeno potenci�ln� vyva�ov�n�
					 */
					void  BalanceLeft(Node*& node, bool& rebalance);

					/**
					* Metoda pro vyv�en� stromu p�i odebr�n� prvku v p��pad�, kdy se zmen�� prav� podstrom
					* @param node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @param rebalance P��znak ur�uj�c�, zda m� b�t provedeno potenci�ln� vyva�ov�n�
					*/
					void  BalanceRight(Node*& node, bool& rebalance);

					/**
					* Pomocn� metoda pro Delete
					* Metoda pro nalezen� nejprav�j��ho potomka v lev�m podstromu, a nahrazen� odeb�ran�ho prvku.
					* @param node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @param node2 Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m		
					* @param rebalance	P��znak ur�uj�c�, zda m� b�t provedeno potenci�ln� vyva�ov�n�		
					*/
					void  DeleteWithBothChildren(Node*& node, Node*& node2, bool& rebalance);

					/**
					* Priv�tn� rekurzivn� metoda pro zji�t�n� existence prvku v AVL stromu
					* @param node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					* @param key Hodnota hledan�ho prvku v AVL stromu
					* @return true pokud prvek existuje, false nikoliv
					*/
					bool Contains(const Node* node, const T& key) const;

					/**
					* Priv�tn� rekurzivn� metoda pro spo��t�n� prvk� v AVL stromu
					* @param node Reprezentuje element, kter� se rekurzivn� po��t� jeden po druh�m
					* @return po�et prvk�
					*/
					int Size(const Node* node);

					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat z AVL stromu v po�ad� inorder
					* @param node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void InOrder(Node* node);

					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat z AVL stromu v po�ad� preoder
					* @param node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
					*/
					void PreOrder(const Node* node);

					/**
					* Priv�tn� rekurzivn� metoda pro z�sk�n� a vyps�n� dat z AVL stromu v po�ad� postorder
					* @param node Reprezentuje element, kter� se rekurzivn� proch�z� jeden po druh�m
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
					bool rebalance = false; //p��znak ur�uj�c�, zda m� b�t provedeno potenci�ln� vyva�ov�n�
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
							case 1: //po p�id�n� se nevyv�enost vyrovnala
								node->Balance = 0;
								rebalance = false;
								break;
							case 0: //po p�id�n� bude lev� podstrom vy��� ne� prav�
								node->Balance = -1;
								break;
							case -1: //ji� je pot�eba vyv�it, jeliko� pot� by byl faktor > -1 to zna�� nevyv�enost
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
					bool rebalance = false; //p��znak ur�uj�c�, zda m� b�t provedeno potenci�ln� vyva�ov�n�
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
								if (q->Right == nullptr)//jen lev� potomek
								{
									node = q->Left;
									rebalance = true;
								}
								else
									if (q->Left == nullptr) //jen prav� potomek
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