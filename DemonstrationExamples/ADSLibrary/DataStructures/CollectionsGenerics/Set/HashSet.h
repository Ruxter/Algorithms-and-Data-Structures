#pragma once
#include "ISet.h"
namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Set
			{
				template <class T> class HashSet : public Iset<T>
				{
				public:
					HashSet();
					~HashSet();
					void Add(const T& Item) override;
					bool Remove(const T& Item) override;
					bool Contains(const T& Item) override;
					int Size() override;
					bool IsEmpty() override;
					bool Clear() override;

				private:

					T<HashSet> set;
					
				};

				template<typename T> HashSet<T>::HashSet()
				{
					
				}

				template<typename T> HashSet<T>::~HashSet()
				{
					
				}

				template<typename T> void HashSet<T>::Add(const T& Item)
				{
					
				}

				template<typename T> bool HashSet<T>::Remove(const T& Item)
				{
					return true;
				}

				template<typename T> bool HashSet<T>::Contains(const T& Item)
				{
					return true;
				}

				template<typename T> int HashSet<T>::Size()
				{
					return set.size();
				}

				template<typename T> bool HashSet<T>::IsEmpty()
				{
					return true;
				}

				template<typename T> bool HashSet<T>::Clear()
				{
					return true;
				}
			}
		}
	}
}