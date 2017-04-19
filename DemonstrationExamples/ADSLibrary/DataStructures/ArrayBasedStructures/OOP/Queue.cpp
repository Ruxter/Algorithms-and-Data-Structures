#include "Queue.h"
#include <iostream>

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
					this->mQueueSize = this->mDefaultQueueSize;
					this->mItems = new int[this->mDefaultQueueSize];
					this->mHead = 0;
					this->mTail = 0;
				}

				Queue::Queue(const int mQueueSize)
				{
					if (mQueueSize <= 0)
					{
						this->mQueueSize = this->mDefaultQueueSize;
					}
					else
					{
						this->mQueueSize = mQueueSize;
					}
					this->mItems = new int[this->mQueueSize];
					this->mHead = 0;
					this->mTail = 0;
				}

				Queue::~Queue()
				{
					delete[] this->mItems;
				}

				void Queue::Enqueue(const int X)
				{
					this->mItems[this->mTail] = X;
					this->mTail = (this->mTail + 1) % this->mQueueSize;
				}

				int Queue::Dequeue()
				{
					int x = this->mItems[this->mHead];
					this->mHead = (this->mHead + 1) % this->mQueueSize;
					return x;
				}

				int Queue::Peek()
				{
					return this->mItems[this->mHead];
				}

				bool Queue::IsEmpty()
				{
					return this->mHead == this->mTail;
				}

				bool Queue::IsFull()
				{
					return this->mHead == (this->mTail) % this->mQueueSize;
				}

				void Queue::Clear()
				{
					this->mHead = 0;
					this->mTail = 0;
				}

				void Queue::Report()
				{
					cout << "Queue report" << endl;
					cout << "--------------------------" << endl;
					cout << "mHead: " << this->mHead << endl;
					cout << "mTail: " << this->mTail << endl;
					for (int i = 0; i < this->mQueueSize; i++)
					{
						cout << i << "   " << this->mItems[i] << endl;
					}
					cout << "--------------------------" << endl;
					cout << endl;
				}
			}
		}
	}
}
