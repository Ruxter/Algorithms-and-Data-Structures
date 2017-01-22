#include "Queue.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				Queue::Queue()
				{
					this->Head = nullptr;
					this->Tail = nullptr;
				}

				Queue::~Queue()
				{
					this->Clear();
				}

				void Queue::Enqueue(const int X)
				{
					QueueItem* n = new QueueItem();
					n->Value = X;
					n->Prev = nullptr;
					if (this->IsEmpty())
					{
						this->Head = n;
					}
					else
					{
						this->Tail->Prev = n;
					}
					this->Tail = n;
				}

				int Queue::Dequeue()
				{
					QueueItem* d = this->Head;
					int result = d->Value;
					this->Head = this->Head->Prev;
					delete d;
					return result;
				}

				int Queue::Peek() const
				{
					return this->Head->Value;
				}

				bool Queue::IsEmpty() const
				{
					return this->Head == nullptr;
				}

				void Queue::Clear()
				{
					while (this->Head != nullptr)
					{
						QueueItem* d = this->Head;
						this->Head = this->Head->Prev;
						delete d;
					}
					this->Head = nullptr;
					this->Tail = nullptr;
				}

				void Queue::Report() const
				{
					cout << "Queue report" << endl;
					cout << "--------------------------" << endl;
					cout << "Head: "<< this->Head << endl;
					cout << "Tail: "<< this->Tail << endl;
					QueueItem* p = this->Head;
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
