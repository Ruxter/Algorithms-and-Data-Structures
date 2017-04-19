#pragma once

class DummyClass;

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOPTemplate
			{
				template <typename T>
				class DoublyLinkedList
				{
				public:
					/**
					* Konstruktor
					*/
					DoublyLinkedList();
					
					/**
					* Destuktor
					*/
					~DoublyLinkedList();

					/**
					* Vlo�en� prvku na za��tek seznamu.
					* @param Value vkl�dan� hodnota
					*/
					void InsertBegin(T Value);

					/**
					* Vlo�en� prvku na konec seznamu.
					* @param Value vkl�dan� hodnota
					*/
					void InsertEnd(T Value);

					/**
					* Nalezen� prvku v listu.
					* @param Value hodnota kterou chceme zjistit
					* @return vrac� true pokud je dan� element v seznamu, jinak false.
					*/
					bool Search(T Value);
															
					/**
					* Odebr�n� prvn�ho prvku ze seznamu - mHead.	
					*/
					void RemoveFirstItem();

					/**
					* Odebr�n� posledn�ho prvku ze seznamu - mTail.
					*/
					void RemoveLastItem();

					/**
					* Test, je-li seznam pr�zdn�.
					* @return Funkce vrac� true pokud je seznam pr�zdn�, jinak false.
					*/
					bool IsEmpty() const;

					/**
					* Spo��t� prvky
					*/
					int Count() const;

					/**
					* @return Funkce vrac� posledn� prvek ze seznamu.
					*/
					T LastItem();

					/**
					* @return Funkce vrac� prvn� prvek ze seznamu.
					*/
					T FirstItem();

					/**
					* Sma�e obsah seznamu.
					*/
					void Clear();


				private:
					/**
					* \brief Struktura reprezentuj�c� element seznamu
					*/
					struct Node
					{
						/**
						* Hodnota obsa�en� v polo�ce.
						*/
						T Value;

						/**
						* Ukazatel na dal�� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu NULL.
						*/
						Node* Next = nullptr;

						/**
						* Ukazatel na p�edchoz� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu NULL.
						*/
						Node* Prev = nullptr;
					};

					/**
					* Nejp�edn�j�� prvek seznamu
					*/
					Node* mHead;

					/**
					* Nejzadn�j�� prvek seznamu
					*/
					Node* mTail;

					/**
					* Velikost seznamu
					*/
					int mSize;
				};


				template<typename T> DoublyLinkedList<T>::DoublyLinkedList()
				{
					mHead = nullptr;
					mTail = nullptr;
					mSize = 0;
				}

				template<typename T> DoublyLinkedList<T>::~DoublyLinkedList()
				{
					Clear();
				}

				template<typename T> bool DoublyLinkedList<T>::Search(T Value)
				{
					if (!IsEmpty())
					{
						Node* node = mHead;
						while (node)
						{
							if (node->Value == Value) return true;
							node = node->Next;
						}
						return false;
					}
					return false;
				}
							

				template <typename T> void DoublyLinkedList<T>::InsertBegin(T Value)
				{
					Node* node = new Node();
					node->Value = Value;
					if (mHead == nullptr)
					{
						mHead = node;
						mTail = node;
					}
					else
					{
						mHead->Prev = node;
						node->Next = mHead;
						mHead = node;
					}
					mSize++;
				}

				template <typename T> void DoublyLinkedList<T>::InsertEnd(T Value)
				{
					Node* node = new Node();
					node->Value = Value;
					if (mTail == nullptr)
					{
						mHead = node;
						mTail = node;
					}
					else
					{
						mTail->Next = node;
						node->Prev = mTail;
						mTail = node;
					}
					mSize++;
				}

				template <typename T> void DoublyLinkedList<T>::RemoveFirstItem()
				{
					if (!IsEmpty())
					{
						Node* node = mHead;
						if (mHead == mTail) mTail = nullptr;
						mHead = node->Next;
						mHead->Prev = nullptr;
						delete node;
						mSize--;						
					}					
				}

				template <typename T> void DoublyLinkedList<T>::RemoveLastItem()
				{
					if (!IsEmpty())
					{
						if (mHead == mTail) mHead = nullptr;
						mTail = mTail->Prev;
						mTail->Next = nullptr;
						mSize--;
					}
				}

				template<typename T> bool DoublyLinkedList<T>::IsEmpty() const
				{
					if (Count() <= 0)
					{
						return true;
					}

					return false;
				}

				template<typename T> int DoublyLinkedList<T>::Count() const
				{
					Node* node = mHead;
					int count = 0;
					while (node)
					{
						count++;
						node = node->Next;
					}
					return count;
				}

				template<typename T> T DoublyLinkedList<T>::LastItem()
				{
					return mTail->Value;
				}

				template<typename T> T DoublyLinkedList<T>::FirstItem()
				{
					return mHead->Value;
				}

				template<typename T> void DoublyLinkedList<T>::Clear()
				{
					Node* node= mHead;					
					while (node) 
					{
						mHead = mHead->Next;
						delete node;						
						node = mHead;
					}					
					mTail = mHead = nullptr;
					mSize = 0;
				}					
			}
		}
	}
}
