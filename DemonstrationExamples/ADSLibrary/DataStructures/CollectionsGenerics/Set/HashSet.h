#pragma once
#include <memory>

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Set
			{
				template <class T> class HashSet
				{
				public:
					HashSet();
					~HashSet();
					void Add(const T& Item);
					bool Remove(const T& Item);
					bool Contains(const T& Item);
					int Size();
					bool IsEmpty();
					bool Clear();

				private:

					int hashFunc(const T& neco);
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
					return 0;
				}

				template<typename T> bool HashSet<T>::IsEmpty()
				{
					return true;
				}

				template<typename T> bool HashSet<T>::Clear()
				{
					return true;
				}
				template<typename T> int HashSet<T>::hashFunc(const T& neco)
				{
				}
			}
		}
	}
}
