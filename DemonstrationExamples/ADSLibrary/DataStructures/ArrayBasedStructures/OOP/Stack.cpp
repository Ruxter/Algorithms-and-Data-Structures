#include "Stack.h"

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOP
			{
				Stack::Stack()
				{
					this->StackSize = DefaultStackSize;
					this->Items = new char[DefaultStackSize];
					this->StackPointer = 0;
				}

				Stack::Stack(const int StackSize)
				{
					if (StackSize <= 0)
					{
						this->StackSize = DefaultStackSize;
					}
					else
					{
						this->StackSize = StackSize;
					}
					this->Items = new char[this->StackSize];
					this->StackPointer = 0;
				}

				Stack::~Stack()
				{
					delete[] this->Items;
				}

				void Stack::Push(const char X)
				{
					this->Items[this->StackPointer] = X;
					this->StackPointer += 1;
				}

				char Stack::Pop()
				{
					this->StackPointer -= 1;					
					return this->Items[this->StackPointer];
				}

				char Stack::Top() const
				{
					return this->Items[this->StackPointer - 1];
				}

				bool Stack::IsEmpty() const
				{
					return this->StackPointer == 0;
				}

				bool Stack::IsFull() const
				{
					return this->StackPointer >= this->StackSize;
				}

				int Stack::Count() const
				{
					return this->StackPointer;
				}

				void Stack::Clear()
				{
					this->StackPointer = 0;
				}
			}
		}
	}
}
