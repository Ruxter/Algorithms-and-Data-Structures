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
				template <class K, class T> class Dictionary
				{
				public:
					Dictionary();
					~Dictionary();


				private:
					int m_size;
					int m_count;

					int m_minimalDictioonarySize = 10;

					struct Pair
					{
						K key;

						T Value;

						Pair* Left;

						Pair* Right;
					};

					Pair* m_root;

					Pair* Add(Pair* root, DynamicArray<K>& key, DynamicArray<T>& value);
				};

				template<typename K, typename T> Dictionary<K, T>::Dictionary() : m_count(0)
				{
					m_size = m_minimalDictioonarySize;
					m_root = NULL;

				}

				template<typename K, typename T> Dictionary<K, T>::~Dictionary()
				{

				}				

				template<typename K, typename T> typename Dictionary<K, T>::Pair* Dictionary<K, T>::Add(Pair* root, DynamicArray<K>& Key, DynamicArray<T>& Value)
				{
					if (root == NULL) {
						Pair* newNode = new Pair();
						root = newNode;
						newNode->Key = Key;
						newNode->Value = Value;
						newNode->Right = NULL;
						newNode->Left = NULL;
					}
					else if (Key < root->Key) {
						root->Left = addElement(root->Left, Key, Value);
					}
					else if (Key > root->Key) {
						root->Right = addElement(root->Right, Key, Value);
					}
					else {
						std::cout << "The name is already in use!\n Select a new name\n";
					}
					return root;
				}
			}
		}
	}
}

