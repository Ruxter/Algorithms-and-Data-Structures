#include "List.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace Procedural
			{
				void Init(List& L)
				{
					L.Head = NULL;
					L.Current = NULL;
				}

				void Clear(List& L)
				{
					while (L.Head != NULL)
					{
						ListItem* p = L.Head;
						L.Head = L.Head->Next;
						delete p;
					};
					L.Current = NULL;
				}

				void Insert(List& L, const int X)
				{
					ListItem* n = new ListItem;
					n->Value = X;
					n->Prev = NULL;
					n->Next = L.Head;
					if (L.Head != NULL)
					{
						L.Head->Prev = n;
					}
					L.Head = n;
				}

				void Delete(List& L, const int X)
				{
					ListItem* p;
					for (p = L.Head; p != NULL; p = p->Next)
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
						L.Head = p->Next;
					}
					if (p->Next != NULL)
					{
						p->Next->Prev = p->Prev;
					}
					delete p;
				}

				bool Search(const List& L, const int X)
				{
					ListItem* p = L.Head;
					while (p != NULL)
					{
						if (p->Value == X)
							return true;
						p = p->Next;
					}
					return false;
				}

				bool IsEmpty(const List& L)
				{
					return L.Head == NULL;
				}

				int Count(const List& L)
				{
					int counter = 0;
					for (ListItem* p = L.Head; p != NULL; p = p->Next)
					{
						counter += 1;
					}
					return counter;
				}

				void Reset(List& L)
				{
					L.Current = L.Head;
				}

				bool IsEnd(const List& L)
				{
					return L.Current == NULL;
				}

				void MoveNext(List& L)
				{
					L.Current = L.Current->Next;
				}

				int Current(const List& L)
				{
					return L.Current->Value;
				}

				void Report(const List& L)
				{
					cout << "List report" << endl;
					cout << "--------------------------" << endl;
					cout << "Head: " << L.Head << endl;
					cout << "Current: " << L.Current << endl;
					for (ListItem* p = L.Head; p != NULL; p = p->Next)
					{
						cout << p->Value << "\t" << p->Prev << "\t" << p->Next << endl;
					}
					cout << "--------------------------" << endl;
				}
			}
		}
	}
}
