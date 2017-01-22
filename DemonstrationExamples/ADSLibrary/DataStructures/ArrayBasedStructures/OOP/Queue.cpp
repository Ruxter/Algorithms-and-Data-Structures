#include "Queue.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOP
			{
				Queue::Queue()
				{
					this->QueueSize = this->DefaultQueueSize;
					this->Items = new int[this->DefaultQueueSize];
					this->Head = 0;
					this->Tail = 0;
				}

				Queue::Queue(const int QueueSize)
				{
					if (QueueSize <= 0)
					{
						this->QueueSize = this->DefaultQueueSize;
					}
					else
					{
						this->QueueSize = QueueSize;
					}
					this->Items = new int[this->QueueSize];
					this->Head = 0;
					this->Tail = 0;
				}

				Queue::~Queue()
				{
					delete[] this->Items;
				}

				void Queue::Enqueue(const int X)
				{
					this->Items[this->Tail] = X;
					this->Tail = (this->Tail + 1) % this->QueueSize;
				}

				int Queue::Dequeue()
				{
					int x = this->Items[this->Head];
					this->Head = (this->Head + 1) % this->QueueSize;
					return x;
				}

				int Queue::Peek()
				{
					return this->Items[this->Head];
				}

				bool Queue::IsEmpty()
				{
					return this->Head == this->Tail;
				}

				bool Queue::IsFull()
				{
					return this->Head == (this->Tail + 1) % this->QueueSize;
				}

				void Queue::Clear()
				{
					this->Head = 0;
					this->Tail = 0;
				}

				void Queue::Report()
				{
					cout << "Queue report" << endl;
					cout << "--------------------------" << endl;
					cout << "Head: " << this->Head << endl;
					cout << "Tail: " << this->Tail << endl;
					for (int i = 0; i < this->QueueSize; i++)
					{
						cout << i << "   " << this->Items[i] << endl;
					}
					cout << "--------------------------" << endl;
					cout << endl;
				}
			}
		}
	}
}