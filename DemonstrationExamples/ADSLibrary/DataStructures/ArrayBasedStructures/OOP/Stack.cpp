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
					this->mStackSize = mDefaultStackSize;
					this->mItems = new char[mDefaultStackSize];
					this->mStackPointer = 0;
				}

				Stack::Stack(const int StackSize)
				{
					if (StackSize <= 0)
					{
						this->mStackSize = mDefaultStackSize;
					}
					else
					{
						this->mStackSize = StackSize;
					}
					this->mItems = new char[this->mStackSize];
					this->mStackPointer = 0;
				}

				Stack::~Stack()
				{
					delete[] this->mItems;
				}

				void Stack::Push(const char X)
				{
					this->mItems[this->mStackPointer] = X;
					this->mStackPointer += 1;
				}

				char Stack::Pop()
				{
					this->mStackPointer -= 1;					
					return this->mItems[this->mStackPointer];
				}

				char Stack::Top() const
				{
					return this->mItems[this->mStackPointer - 1];
				}

				bool Stack::IsEmpty() const
				{
					return this->mStackPointer == 0;
				}

				bool Stack::IsFull() const
				{
					return this->mStackPointer >= this->mStackSize;
				}

				int Stack::Count() const
				{
					return this->mStackPointer;
				}

				void Stack::Clear()
				{
					this->mStackPointer = 0;
				}
			}
		}
	}
}
