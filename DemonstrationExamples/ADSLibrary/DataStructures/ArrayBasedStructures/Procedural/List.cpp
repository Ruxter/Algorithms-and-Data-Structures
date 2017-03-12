#include "List.h"
#include <iostream>

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace Procedural
			{
				void Init(List& L)
				{
					Clear(L);
				}

				void Clear(List& L)
				{
					L.Head = Nil;
					L.Current = Nil;
					for (int i = 0; i < ListSize; i++)
					{
						L.Data[i].Next = i + 1;
					}
					L.Data[ListSize - 1].Next = Nil;
					L.Free = 0;
				}

				void Insert(List& L, const int X)
				{
					int NewItemIndex = AllocateItem(L);
					if (NewItemIndex != Nil)
					{
						L.Data[NewItemIndex].Value = X;
						L.Data[NewItemIndex].Prev = Nil;
						L.Data[NewItemIndex].Next = L.Head;
						if (L.Head != Nil)
						{
							L.Data[L.Head].Prev = NewItemIndex;
						}
						L.Head = NewItemIndex;
					}
				}

				void Delete(List& L, const int X)
				{
					int p = L.Head;
					while (p != Nil)
					{
						if (L.Data[p].Value == X)
							break;
						p = L.Data[p].Next;
					}
					if (p == Nil)
						return;
					if (L.Data[p].Prev != Nil)
					{
						L.Data[L.Data[p].Prev].Next = L.Data[p].Next;
					}
					else
					{
						L.Head = L.Data[p].Next;
					}
					if (L.Data[p].Next != Nil)
					{
						L.Data[L.Data[p].Next].Prev = L.Data[p].Prev;
					}
					FreeItem(L, p);
				}

				bool Search(const List& L, const int X)
				{
					int p = L.Head;
					while (p != Nil)
					{
						if (L.Data[p].Value == X)
							return true;
						p = L.Data[p].Next;
					}
					return false;
				}

				bool IsEmpty(const List& L)
				{
					return L.Head == Nil;
				}

				int Count(const List& L)
				{
					int counter = 0;
					for (int p = L.Head; p != Nil; p = L.Data[p].Next)
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
					return L.Current == Nil;
				}

				void MoveNext(List& L)
				{
					L.Current = L.Data[L.Current].Next;
				}

				int Current(const List& L)
				{
					return L.Data[L.Current].Value;
				}

				int AllocateItem(List& L)
				{
					if (L.Free != Nil)
					{
						int p = L.Free;
						L.Free = L.Data[L.Free].Next;
						return p;
					}
					std::cerr << "List is full" << std::endl;
					return Nil;
				}

				void FreeItem(List& L, const int Index)
				{
					L.Data[Index].Next = L.Free;
					L.Free = Index;
				}

				void Report(const List& L)
				{
					std::cout << std::endl;
					std::cout << "List report" << std::endl;
					std::cout << "--------------------------" << std::endl;
					std::cout << "Head: " << L.Head << std::endl;
					std::cout << "Current: " << L.Current << std::endl;
					std::cout << "Free: " << L.Free << std::endl;
					std::cout << "--------------------------" << std::endl;
					std::cout << "Index\tValue\tPrev\tNext" << std::endl;
					for (int i = 0; i < ListSize; i++)
					{
						std::cout << i << "\t" << L.Data[i].Value << "\t" << L.Data[i].Prev << "\t" << L.Data[i].Next << std::endl;
					}
					std::cout << "--------------------------" << std::endl;
					std::cout << "Garbage collector: ";
					int p = L.Free;
					while (p != Nil)
					{
						std::cout << p << ", ";
						p = L.Data[p].Next;
					}
					std::cout << std::endl << "--------------------------" << std::endl;
					std::cout << std::endl;
				}

			}
		}
	}
}
