#include "Queue.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace Procedural
			{
				void Init(Queue& Q)
				{
					Q.Head = nullptr;
					Q.Tail = nullptr;
				}

				void Enqueue(Queue& Q, const int X)
				{
					QueueItem* n = new QueueItem();
					n->Value = X;
					n->Prev = nullptr;
					if (IsEmpty(Q))
					{
						Q.Head = n;
					}
					else
					{
						Q.Tail->Prev = n;
					}
					Q.Tail = n;
				}

				int Dequeue(Queue& Q)
				{
					QueueItem* d = Q.Head;
					int result = d->Value;
					Q.Head = Q.Head->Prev;
					delete d;
					return result;
				}

				int Peek(Queue& Q)
				{
					return Q.Head->Value;
				}

				bool IsEmpty(const Queue& Q)
				{
					return Q.Head == nullptr;
				}

				void Clear(Queue& Q)
				{
					while (Q.Head != nullptr)
					{
						QueueItem* d = Q.Head;
						Q.Head = Q.Head->Prev;
						delete d;
					}
					Q.Head = nullptr;
					Q.Tail = nullptr;
				}

				void Report(const Queue& Q)
				{
					cout << "Queue report" << endl;
					cout << "--------------------------" << endl;
					cout << "Head: "<< Q.Head << endl;
					cout << "Tail: "<< Q.Tail << endl;
					QueueItem* p = Q.Head;
					while (p != nullptr)
					{
						cout << p << "\t" << p->Value << "\t" << p->Prev << endl;
						p = p->Prev;
					}
					cout << "--------------------------" << endl;
					cout << endl;
				}
			}
		}
	}
}
