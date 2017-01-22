#include "List.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				List::List()
				{
					mHead = NULL;
					mCurrent = NULL;
				}

				List::~List()
				{
					Clear();
				}

				void List::Clear()
				{
					while (mHead != NULL)
					{
						ListItem* p = mHead;
						mHead = mHead->Next;
						delete p;
					};
					mCurrent = NULL;
				}

				void List::Insert(const int X)
				{
					ListItem* n = new ListItem;
					n->Value = X;
					n->Prev = NULL;
					n->Next = mHead;
					if (mHead != NULL)
					{
						mHead->Prev = n;
					}
					mHead = n;
				}

				void List::Delete(const int X)
				{
					ListItem* p;
					for (p = mHead; p != NULL; p = p->Next)
					{
						if (p->Value == X)
						{
							break;
						}
					}
					if (p == NULL)
					{
						return;
					}
					if (p->Prev != NULL)
					{
						p->Prev->Next = p->Next;
					}
					else
					{
						mHead = p->Next;
					}
					if (p->Next != NULL)
					{
						p->Next->Prev = p->Prev;
					}
					delete p;
				}

				bool List::Search(const int X)
				{
					ListItem* p = mHead;
					while (p != NULL)
					{
						if (p->Value == X)
							return true;
						p = p->Next;
					}
					return false;
				}

				bool List::IsEmpty()
				{
					return mHead == NULL;
				}

				int List::Count()
				{
					int counter = 0;
					for (ListItem* p = mHead; p != NULL; p = p->Next)
					{
						counter += 1;
					}
					return counter;
				}

				void List::Reset()
				{
					mCurrent = mHead;
				}

				bool List::IsEnd()
				{
					return mCurrent == NULL;
				}

				void List::MoveNext()
				{
					mCurrent = mCurrent->Next;
				}

				int List::Current()
				{
					return mCurrent->Value;
				}

				void List::Report()
				{
					cout << "List report" << endl;
					cout << "--------------------------" << endl;
					cout << "Head: " << mHead << endl;
					cout << "Current: " << mCurrent << endl;
					for (ListItem* p = mHead; p != NULL; p = p->Next)
					{
						cout << p->Value << "\t" << p->Prev << "\t" << p->Next << endl;
					}
					cout << "--------------------------" << endl;
				}
			}
		}
	}
}
