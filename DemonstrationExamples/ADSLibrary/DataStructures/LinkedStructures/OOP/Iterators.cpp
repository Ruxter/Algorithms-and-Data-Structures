#include "Iterators.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				void BinaryTreeIterator::Reset()
				{
					mStack.Clear();
					BinarySearchTree::Node* p = mTree->mRoot;
					while (p != NULL)
					{
						mStack.Push(p);
						p = p->Left;
					}
				}

				void BinaryTreeIterator::MoveNext()
				{
					BinarySearchTree::Node* p = mStack.Pop();
					p = p->Right;
					while (p != NULL)
					{
						mStack.Push(p);
						p = p->Left;
					}
				}

				void BinaryTreeReverseIterator::Reset()
				{
					mStack.Clear();
					BinarySearchTree::Node* p = mTree->mRoot;
					while (p != NULL)
					{
						mStack.Push(p);
						p = p->Right;
					}
				}

				void BinaryTreeReverseIterator::MoveNext()
				{
					BinarySearchTree::Node* p = mStack.Pop();
					p = p->Left;
					while (p != NULL)
					{
						mStack.Push(p);
						p = p->Right;
					}
				}

			}
		}
	}
}