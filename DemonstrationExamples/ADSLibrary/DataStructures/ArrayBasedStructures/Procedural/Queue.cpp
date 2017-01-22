#include "Queue.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace Procedural
			{
				void Init(Queue& Q)
				{
					Q.Head = 0;
					Q.Tail = 0;
				}

				void Clear(Queue& Q)
				{
					Q.Head = 0;
					Q.Tail = 0;
				}

				void Enqueue(Queue& Q, const int X)
				{
					Q.Items[Q.Tail] = X;
					Q.Tail = (Q.Tail + 1) % CircularBufferSize;
				}

				int Dequeue(Queue& Q)
				{
					int x = Q.Items[Q.Head];
					Q.Head = (Q.Head + 1) % CircularBufferSize;
					return x;
				}

				int Peek(Queue& Q)
				{
					return Q.Items[Q.Head];
				}

				bool IsEmpty(const Queue& Q)
				{
					return Q.Head == Q.Tail;
				}

				bool IsFull(const Queue& Q)
				{
					return Q.Head == (Q.Tail + 1) % CircularBufferSize;
				}

				void Report(const Queue& Q)
				{
					cout << "Queue report" << endl;
					cout << "--------------------------" << endl;
					cout << "Head: " << Q.Head << endl;
					cout << "Tail: " << Q.Tail << endl;
					for (int i = 0; i < CircularBufferSize; i++)
					{
						cout << i << "   " << Q.Items[i] << endl;
					}
					cout << "--------------------------" << endl;
					cout << endl;
				}
			}
		}
	}
}