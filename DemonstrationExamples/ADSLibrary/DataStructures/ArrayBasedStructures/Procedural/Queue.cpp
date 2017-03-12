#include "Queue.h"
#include <iostream>

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
					return Q.Head == (Q.Tail) % CircularBufferSize;
				}

				void Report(const Queue& Q)
				{
					std::cout << "Queue report" << std::endl;
					std::cout << "--------------------------" << std::endl;
					std::cout << "Head: " << Q.Head << std::endl;
					std::cout << "Tail: " << Q.Tail << std::endl;
					for (int i = 0; i < CircularBufferSize; i++)
					{
						std::cout << i << "   " << Q.Items[i] << std::endl;
					}
					std::cout << "--------------------------" << std::endl;
					std::cout << std::endl;
				}
			}
		}
	}
}
