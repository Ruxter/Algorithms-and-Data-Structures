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
					mHead = nullptr;
					mCurrent = nullptr;
				}

				List::~List()
				{
					Clear();
				}

				void List::Clear()
				{
					while (mHead != nullptr)
					{
						ListItem* p = mHead;
						mHead = mHead->Next;
						delete p;
					};
					mCurrent = nullptr;
				}

				void List::Insert(const int X)
				{
					ListItem* n = new ListItem;
					n->Value = X;
					n->Prev = nullptr;
					n->Next = mHead;
					if (mHead != nullptr)
					{
						mHead->Prev = n;
					}
					mHead = n;
				}

				void List::Delete(const int X)
				{
					ListItem* p;
					for (p = mHead; p != nullptr; p = p->Next)
					{
						if (p->Value == X)
						{
							break;
						}
					}
					if (p == nullptr)
					{
						return;
					}
					if (p->Prev != nullptr)
					{
						p->Prev->Next = p->Next;
					}
					else
					{
						mHead = p->Next;
					}
					if (p->Next != nullptr)
					{
						p->Next->Prev = p->Prev;
					}					
					delete p;
				}

				bool List::Search(const int X) const
				{
					ListItem* p = mHead;
					while (p != nullptr)
					{
						if (p->Value == X)
							return true;
						p = p->Next;
					}
					return false;
				}

				bool List::IsEmpty() const
				{
					return mHead == nullptr;
				}

				int List::Count() const
				{
					int counter = 0;
					for (ListItem* p = mHead; p != nullptr; p = p->Next)
					{
						counter += 1;
					}
					return counter;
				}

				void List::Reset()
				{
					mCurrent = mHead;
				}

				bool List::IsEnd() const
				{
					return mCurrent == nullptr;
				}

				void List::MoveNext()
				{
					mCurrent = mCurrent->Next;
				}

				int List::Current() const
				{
					return mCurrent->Value;
				}

				void List::Report()
				{
					cout << "List report" << endl;
					cout << "--------------------------" << endl;
					cout << "Head: " << mHead << endl;
					cout << "Current: " << mCurrent << endl;
					for (ListItem* p = mHead; p != nullptr; p = p->Next)
					{
						cout << p->Value << "\t" << p->Prev << "\t" << p->Next << endl;
					}
					cout << "--------------------------" << endl;
				}
			}
		}
	}
}
