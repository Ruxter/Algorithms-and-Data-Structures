#pragma once
#include "../../ArrayBasedStructures/OOPTemplate/DynamicArray.h"
using namespace ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate;
namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Dictionary
			{
				template <class T> class Dictionary
				{
				public:
					Dictionary();
					~Dictionary();
					void Add(DynamicArray<T>& key, DynamicArray<T>& value);

				private:
					int m_size;
					int m_count;

					int m_minimalDictioonarySize = 10;
				};

				template<typename T> Dictionary<T>::Dictionary() : m_count(0)
				{
					m_size = m_minimalDictioonarySize;					
				}

				template<typename T> Dictionary<T>::~Dictionary()
				{

				}

				template<typename T> void Dictionary<T>::Add(DynamicArray<T>& key, DynamicArray<T>& value)
				{

				}
			}
		}
	}
}
