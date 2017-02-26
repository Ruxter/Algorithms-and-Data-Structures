#pragma once
#include <wchar.h>
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
					void Add(const K& Key, const T& Value);

				private:
					
					struct Pair
					{
						K Key;

						T Value;

						Pair* Left;

						Pair* Right;
					};

					Pair* m_root;

					Pair* Add(Pair* pair, const K& Key, const T& Value);
				};

				template<typename K, typename T> SortedDictionary<K, T>::SortedDictionary()
				{
					m_root = NULL;
				}

				template<typename K, typename T> SortedDictionary<K, T>::~SortedDictionary()
				{

				}

				template<typename K, typename T> void SortedDictionary<K, T>::Add(const K& Key, const T& Value)
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

				template<typename K, typename T> typename SortedDictionary<T, K>::Pair* SortedDictionary<K, T>::Add(Pair* pair, const K& Key, const T& Value)
				{
					if (pair == NULL) {
						pair = new Pair();
						pair->Key = Key;
						pair->Left = pair->Right = NULL;
					}
					else if (Key <= pair->Key) {
						pair->Left = Insert(pair->Left, Key);
					}
					else {
						pair->Right = Insert(pair->Right, Key);
					}
					return pair;
				}
			}
		}
	}
}

