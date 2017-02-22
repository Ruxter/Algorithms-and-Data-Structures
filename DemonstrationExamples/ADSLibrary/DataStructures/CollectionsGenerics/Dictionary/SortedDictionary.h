#pragma once
#include "../../ArrayBasedStructures/OOPTemplate/DynamicArray.h"
#include <wchar.h>
#include <iostream>
using namespace ADSLibrary::DataStructures::ArrayBasedStructures::OOPTemplate;
namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace CollectionsGenerics
		{
			namespace Dictionary
			{
				template <class K, class T> class SortedDictionary
				{
				public:
					SortedDictionary();
					~SortedDictionary();
					void Add(const T& Key, const T& Value);

				private:
					
					struct Pair
					{
						K Key;

						T Value;

						Pair* Left;

						Pair* Right;
					};

					Pair* m_root;

					void Add(Pair* root, const T& Key, const T& Value);
				};

				template<typename K, typename T> SortedDictionary<K, T>::SortedDictionary()
				{
					m_root = NULL;
				}

				template<typename K, typename T> SortedDictionary<K, T>::~SortedDictionary()
				{

				}

				template<typename K, typename T> void SortedDictionary<K, T>::Add(const T& Key, const T& Value)
				{
					if (m_root != nullptr)
						Add(m_root, Key, Value);
					else
					{
						m_root = new Pair();
						m_root->Key = Key;
						m_root->Value = Value;
						m_root->Left = NULL;
						m_root->Right = NULL;
					}
				}

				template<typename K, typename T> void SortedDictionary<K, T>::Add(Pair* node, const T& Key, const T& Value)
				{
					if (Key < node->Key)
					{
						if (node->Left != NULL)
							Add(node->Left, Key, Value);
						else
						{
							node->Left = new Pair();
							node->Left->Key = Key;
							node->Left->Value = Value;
							node->Left->Left = NULL;
							node->Left->Right = NULL;
						}
					}
					else if (Key >= node->Key)
					{
						if (node->Right != NULL)
							Add(node->Right, Key, Value);
						else
						{
							node->Right = new Pair();
							node->Right->Key = Key;
							node->Right->Value = Value;
							node->Right->Left = NULL;
							node->Right->Right = NULL;
						}
					}
				}
			}
		}
	}
}

