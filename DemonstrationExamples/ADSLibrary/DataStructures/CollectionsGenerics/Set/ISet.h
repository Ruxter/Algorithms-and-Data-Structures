#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Set
			{
				template <class T> class Iset
				{
				public:
					virtual ~Iset() = 0;
					virtual void Add(const T& Key){};
					virtual bool Remove(const T& Item) = 0;
					virtual bool Contains(const T& Item) = 0;
					virtual int Size() = 0;
					virtual bool IsEmpty() = 0;					
					virtual void Clear(const T* p) = 0;
				};
			}
		}
	}
}