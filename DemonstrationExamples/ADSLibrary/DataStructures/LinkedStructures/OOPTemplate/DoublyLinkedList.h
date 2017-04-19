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
					* Vložení prvku na zaèátek seznamu.
					* @param Value vkládaná hodnota
					*/
					void InsertBegin(T Value);

					/**
					* Vložení prvku na konec seznamu.
					* @param Value vkládaná hodnota
					*/
					void InsertEnd(T Value);

					/**
					* Nalezení prvku v listu.
					* @param Value hodnota kterou chceme zjistit
					* @return vrací true pokud je daný element v seznamu, jinak false.
					*/
					bool Search(T Value);
															
					/**
					* Odebrání prvního prvku ze seznamu - mHead.	
					*/
					void RemoveFirstItem();

					/**
					* Odebrání posledního prvku ze seznamu - mTail.
					*/
					void RemoveLastItem();

					/**
					* Test, je-li seznam prázdný.
					* @return Funkce vrací true pokud je seznam prázdný, jinak false.
					*/
					bool IsEmpty() const;

					/**
					* Spoèítá prvky
					*/
					int Count() const;

					/**
					* @return Funkce vrací poslední prvek ze seznamu.
					*/
					T LastItem();

					/**
					* @return Funkce vrací první prvek ze seznamu.
					*/
					T FirstItem();

					/**
					* Smaže obsah seznamu.
					*/
					void Clear();


				private:
					/**
					* \brief Struktura reprezentující element seznamu
					*/
					struct Node
					{
						/**
						* Hodnota obsažená v položce.
						*/
						T Value;

						/**
						* Ukazatel na další položku. Pokud taková položka neexistuje ukazatel má hodnotu NULL.
						*/
						Node* Next = nullptr;

						/**
						* Ukazatel na pøedchozí položku. Pokud taková položka neexistuje ukazatel má hodnotu NULL.
						*/
						Node* Prev = nullptr;
					};

					/**
					* Nejpøednìjší prvek seznamu
					*/
					Node* mHead;

					/**
					* Nejzadnìjší prvek seznamu
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
