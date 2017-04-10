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
				private:
					struct Node
					{
						T Key;
						Node* Left;
						Node* Right;
						int Balance;
					};

					void  Clear(Node* p);
					void  DoInsert(Node*& p, const T X, bool& h);
					void  DoDelete(Node*& p, const T X, bool& h);

					/**
					 * Metoda pro vyváení stromu pøi odebrání prvku v pøípadì, kdy se zmenší levı podstrom
					 */
					void  Balance1(Node*& p, bool& h);

					/**
					* Metoda pro vyváení stromu pøi odebrání prvku v pøípadì, kdy se zmenší pravı podstrom
					*/
					void  Balance2(Node*& p, bool& h);
					void  Del(Node*& r, Node*& q, bool& h);

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

				template<class T> void AVLTree<T>::Clear(Node* p)
				{
					if (p != nullptr)
					{
						Clear(p->Left);
						Clear(p->Right);
						delete p; 
					};  
				}

				template<class T> void AVLTree<T>::Insert(const T& X)
				{
					bool rebalance = false; //pøíznak urèující, zda má bıt provedeno potenciální vyvaování
					DoInsert(mRoot, X, rebalance);
				}

				template<class T> void AVLTree<T>::DoInsert(Node*& p, const T X, bool& rebalance)
				{
					Node  *p1, *p2;
					if (p == nullptr)
					{
						p = new Node;
						p->Key = X;
						p->Left = p->Right = nullptr;
						p->Balance = 0;
						rebalance = true; 
						return;
					};
					if (X < p->Key)
					{
						DoInsert(p->Left, X, rebalance);
						if (rebalance)
						{
							switch (p->Balance)
							{
							case 1: //po pøidání se nevyváenost vyrovnala
								p->Balance = 0;
								rebalance = false;
								break;
							case 0: //po pøidání bude levı podstrom vyšší ne pravı
								p->Balance = -1;
								break;
							case -1: //ji je potøeba vyváit, jeliko poté by byl faktor > -1 to znaèí nevyváenost
								p1 = p->Left;
								if (p1->Balance == -1)
								{// LL
									p->Left = p1->Right;
									p1->Right = p;
									p->Balance = 0;
									p = p1;
								}
								else
								{//  LR
									p2 = p1->Right;
									p1->Right = p2->Left;
									p2->Left = p1;
									p->Left = p2->Right;
									p2->Right = p;
									p->Balance = (p2->Balance == -1) ? +1 : 0;
									p1->Balance = (p2->Balance == +1) ? -1 : 0;
									p = p2;
								};
								p->Balance = 0;
								rebalance = false;
								break;
							default: break;
							};
						};
						return;
					};
					if (X > p->Key)
					{
						DoInsert(p->Right, X, rebalance);
						if (rebalance)
						{
							switch (p->Balance)
							{
							case -1:
								p->Balance = 0;
								rebalance = false;
								break;
							case 0:
								p->Balance = +1;
								break;
							case +1:
								p1 = p->Right;
								if (p1->Balance == +1)
								{//  RR
									p->Right = p1->Left;
									p1->Left = p;
									p->Balance = 0;
									p = p1;
								}
								else
								{//  RL
									p2 = p1->Left;
									p1->Left = p2->Right;
									p2->Right = p1;
									p->Right = p2->Left;
									p2->Left = p;
									p->Balance = (p2->Balance == +1) ? -1 : 0;
									p1->Balance = (p2->Balance == -1) ? +1 : 0;
									p = p2;
								};
								p->Balance = 0;
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
					DoDelete(mRoot, X, rebalance);
				}

				template<class T> void AVLTree<T>::DoDelete(Node*& p, const T X, bool& rebalance)
				{
					if (p == nullptr) rebalance = false;
					else
						if (X < p->Key)
						{
							DoDelete(p->Left, X, rebalance);
							if (rebalance) Balance1(p, rebalance);
						}
						else
							if (X > p->Key)
							{
								DoDelete(p->Right, X, rebalance);
								if (rebalance) Balance2(p, rebalance);
							}
							else
							{// x == p->Key
								Node  *q = p;
								if (q->Right == nullptr)
								{
									p = q->Left;
									rebalance = true;
								}
								else
									if (q->Left == nullptr)
									{
										p = q->Right;
										rebalance = true;
									}
									else
									{
										Del(q->Left, q, rebalance);
										if (rebalance) Balance1(p, rebalance);
									};
								delete q;
							};
				}

				template<class T> void AVLTree<T>::Balance1(Node*& p, bool& rebalance)
				{// h = true, levá vìtev se zmenešila
					Node   *p1, *p2;
					int     b1, b2;
					switch (p->Balance)
					{
					case -1:
						p->Balance = 0;
						break;
					case 0:
						p->Balance = +1;
						rebalance = false;
						break;
					case 1:
						p1 = p->Right;
						b1 = p1->Balance;
						if (b1 >= 0)
						{// jednoducha RR rotace
							p->Right = p1->Left;
							p1->Left = p;
							if (b1 == 0)
							{
								p->Balance = +1;
								p1->Balance = -1;
								rebalance = false;
							}
							else
							{
								p->Balance = 0;
								p1->Balance = 0;
							};
							p = p1;
						}
						else
						{// RL
							p2 = p1->Left;
							b2 = p2->Balance;
							p1->Left = p2->Right;
							p2->Right = p1;
							p->Right = p2->Left;
							p2->Left = p;
							p->Balance = (b2 == +1) ? -1 : 0;
							p1->Balance = (b2 == -1) ? +1 : 0;
							p = p2;
							p2->Balance = 0;
						};
						break;
					default: break;
					};
				}

				template<class T> void AVLTree<T>::Balance2(Node*& p, bool& rebalance)
				{// h = true, pravá vìtev se zmenešila
					Node   *p1, *p2;
					int     b1, b2;
					switch (p->Balance)
					{
					case 1:
						p->Balance = 0;
						break;
					case 0:
						p->Balance = -1;
						rebalance = false;
						break;
					case -1:
						p1 = p->Left;
						b1 = p1->Balance;
						if (b1 == -1)
						{//  LL
							p->Left = p1->Right;
							p1->Right = p;
							if (b1 == 0)
							{
								p->Balance = -1;
								p1->Balance = +1;
								rebalance = false;
							}
							else
							{
								p->Balance = 0;
								p1->Balance = 0;
							};
							p = p1;
						}
						else
						{// LR
							p2 = p1->Right;
							b2 = p2->Balance;
							p1->Right = p2->Left;
							p2->Left = p1;
							p->Left = p2->Right;
							p2->Right = p;
							p->Balance = (b2 == -1) ? +1 : 0;
							p1->Balance = (b2 == +1) ? -1 : 0;
							p = p2;
							p2->Balance = 0;
						};
					default: break;
					};
				}

				template<class T> void AVLTree<T>::Del(Node*& r, Node*& q, bool& rebalance)
				{// h = false
					if (r->Right != nullptr)
					{
						Del(r->Right, q, rebalance);
						if (rebalance) Balance2(r, rebalance);
					}
					else
					{
						q->Key = r->Key;
						q = r;
						r = r->Left;
						rebalance = true;
					};
				}
			}
		}
	}
}