#include "Stack.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				Stack::Stack()
				{
					this->StackPointer = nullptr;
				}

				Stack::~Stack()
				{
					Clear();
				}

				void Stack::Push(const char X)
				{
					StackItem* n = new StackItem();
					n->Value = X;
					n->Prev = this->StackPointer;
					this->StackPointer = n;
				}

				char Stack::Pop()
				{
					StackItem* d = this->StackPointer;
					char ch = d->Value;
					this->StackPointer = this->StackPointer->Prev;
					delete d;
					return ch;
				}

				char Stack::Top() const
				{
					return this->StackPointer->Value;
				}

				bool Stack::IsEmpty() const
				{
					return this->StackPointer == nullptr;
				}

				void Stack::Clear()
				{
					while (!this->IsEmpty())
					{
						this->Pop();
					}
				}
			}
		}
	}
}