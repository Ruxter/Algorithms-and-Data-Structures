#include "BinarySearchTree.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				bool BinarySearchTree::SearchIterative(const string Key) const
				{
					Node* p = mRoot;
					while (p != nullptr)
					{
						if (p->Key == Key)
						{
							return true;
						}
						p = Key < p->Key ? p->Left : p->Right;
					}
					return false;
				}

				void BinarySearchTree::InternalInsert(Node*& p, const string Key)
				{
					if (p == nullptr)
					{
						p = new Node();
						p->Key = Key;
						p->Left = p->Right = nullptr;
						return;
					}
					if (Key < p->Key)
					{
						InternalInsert(p->Left, Key);
						return;
					}
					if (p->Key < Key)
					{
						InternalInsert(p->Right, Key);
						return;
					}
				}

				void BinarySearchTree::InternalDelete(Node*& p, const string Key)
				{
					if (p == nullptr)
					{
						return;
					}
					if (Key < p->Key)
					{
						InternalDelete(p->Left, Key);
						return;
					}
					if (p->Key < Key)
					{
						InternalDelete(p->Right, Key);
						return;
					}
					Node *q = p;
					if (p->Right == nullptr)
					{
						p = p->Left;// žádný nebo jen levý potomek
					}
					else
					{
						if (p->Left == nullptr)
						{
							p = p->Right;// existuje jen pravý potomek
						}
						else
						{
							InternalDeleteRightmostFromLeftSubtree(p->Left, p);	// oba potomci
						}
					}
					delete q;
				}

				void BinarySearchTree::InternalDeleteRightmostFromLeftSubtree(Node*& r, Node*& q)
				{
					if (r->Right != nullptr)
						InternalDeleteRightmostFromLeftSubtree(r->Right, q);
					else
					{
						q->Key = r->Key;
						q = r;
						r = r->Left;
					}
				}


				bool BinarySearchTree::InternalSearch(const Node* p, const string Key) const
				{
					if (p == nullptr)
					{
						return false;
					}
					if (p->Key == Key)
					{
						return true;
					}
					if (Key < p->Key)
					{
						return InternalSearch(p->Left, Key);
					}
					else
					{
						return InternalSearch(p->Right, Key);
					}

				}

				void BinarySearchTree::InternalClear(const Node* p)
				{
					if (p != nullptr)
					{
						InternalClear(p->Left);
						InternalClear(p->Right);
						delete p;
					}
				}

				int BinarySearchTree::InternalCount(const Node* p) const
				{
					if (p == nullptr)
					{
						return 0;
					}
					return 1 + InternalCount(p->Left) + InternalCount(p->Right);
				}

				void BinarySearchTree::InternalInorderTraversal(Node* p)
				{
					if (p != nullptr)
					{
						InternalInorderTraversal(p->Left);
						DoSomeAction(p);
						InternalInorderTraversal(p->Right);
					}
				}

				void BinarySearchTree::InternalPreorderTraversal(Node* p)
				{
					if (p != nullptr)
					{
						DoSomeAction(p);
						InternalPreorderTraversal(p->Left);
						InternalPreorderTraversal(p->Right);
					}
				}

				void BinarySearchTree::InternalPostorderTraversal(Node* p)
				{
					if (p != nullptr)
					{
						InternalPostorderTraversal(p->Left);
						InternalPostorderTraversal(p->Right);
						DoSomeAction(p);
					}
				}

				void BinarySearchTree::InternalReportStructure(Node* p, const int Indentation) const
				{
					if (p != nullptr)
					{
						for (int i = 0; i < Indentation; i++)
							cout << "\t";
						cout << p->Key << endl;
						InternalReportStructure(p->Left, Indentation + 1);
						InternalReportStructure(p->Right, Indentation + 1);
					}
				}

				void BinarySearchTree::DoSomeAction(Node* p) const
				{
					cout << p->Key;
				}

			}
		}
	}
}
