#include "ListWithSentinel.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				ListWithSentinel::ListWithSentinel()
				{
					mNil = new ListItem;
					mNil->Next = mNil->Prev = mNil;
					mCurrent = mNil;
				}

				ListWithSentinel::~ListWithSentinel()
				{
					Clear();
					delete mNil;
				}

				void ListWithSentinel::Clear()
				{
					ListItem* h = mNil->Next;
					while (h != mNil)
					{
						ListItem* p = h;
						h = h->Next;
						delete p;
					};
					mNil->Next = mNil->Prev = mNil;
					mCurrent = mNil;
				}

				void ListWithSentinel::Insert(const int X)
				{
					ListItem* n = new ListItem;
					n->Value = X;
					n->Next = mNil->Next;
					mNil->Next->Prev = n;
					mNil->Next = n;
					n->Prev = mNil;
				}

				void ListWithSentinel::Delete(const int X)
				{
					ListItem* p;
					for (p = mNil->Next; p != mNil; p = p->Next)
					{
						if (p->Value == X)
						{
							break;
						}
					}
					if (p == mNil)
					{
						return;
					}
					p->Prev->Next = p->Next;
					p->Next->Prev = p->Prev;
					delete p;
				}

				bool ListWithSentinel::Search(const int X)
				{
					ListItem* p = mNil->Next;
					while (p != mNil)
					{
						if (p->Value == X)
							return true;
						p = p->Next;
					}
					return false;
				}

				bool ListWithSentinel::IsEmpty()
				{
					return mNil->Next == mNil;
				}

				int ListWithSentinel::Count()
				{
					int counter = 0;
					for (ListItem* p = mNil->Next; p != mNil; p = p->Next)
					{
						counter += 1;
					}
					return counter;
				}

				void ListWithSentinel::Reset()
				{
					mCurrent = mNil->Next;
				}

				bool ListWithSentinel::IsEnd()
				{
					return mCurrent == mNil;
				}

				void ListWithSentinel::MoveNext()
				{
					mCurrent = mCurrent->Next;
				}

				int ListWithSentinel::Current()
				{
					return mCurrent->Value;
				}

				void ListWithSentinel::Report()
				{
					cout << "List report" << endl;
					cout << "--------------------------" << endl;
					cout << "Sentinel Nil: " << mNil << endl;
					cout << "         Nil->Prev: " << mNil->Prev << endl;
					cout << "         Nil->Next: " << mNil->Next << endl;
					cout << "Current: " << mCurrent << endl;
					for (ListItem* p = mNil->Next; p != mNil; p = p->Next)
					{
						cout << p->Value << "\t" << p->Prev << "\t" << p->Next << endl;
					}
					cout << "--------------------------" << endl;
				}
			}
		}
	}
}
