#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOPTemplate
			{
				/**
				* \brief Seznam implementovaný pomocí spojových struktur s využitím %OOPTemplate
				*
				* Implementace jednosmìrného seznamu pomocí spojových struktur.
				*/
				template <typename T>
				class List
				{
				public:
					/**
					* Konstruktor
					*/
					List();

					/**
					* Destuktor
					*/
					~List();

					/**
					* Vložení prvku do seznamu. Prvek je vložen pøed souèasnou hlavu seznamu tj. stane se novou hlavou seznamu.
					* 
					* @param value Vkládaný prvek
					*/
					void Insert(T value);

					/**
					* Vrací hlavu seznamu
					*
					* @return Hlava seznamu
					*/
					T FirstItem();
					
					/**
					* Test je-li seznam prázdný.
					* 
					* @return Funkce vrací true pokud je seznam prázdný, jinak false.
					*/
					bool IsEmpty() const;

					/**
					* Funkce vrací poèet prvkù v seznamu.
					* 
					* @return Poèet prvkù v seznamu.
					*/
					int Count() const;

					/**
					* Odebrání mHead prvku ze seznamu.
					*/
					void RemoveFirstItem();

					/**
					* Hledání prvku v seznamu.
					* 
					* @param value Hledaný prvek
					* @return Funkce vrací true v pøípadì, že je prvek X nalezen, jinak vrací false.
					*/
					bool Search(const T value);

					/**
					* Smazání celého seznamu.
					*
					*/
					void Clear();

				private:
					/**
					* \brief Struktura reprezentující položku v seznamu.
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
						Node* Next;
					};

					/**
					* Nejpøednìjší prvek seznamu
					*/
					Node* mHead;
					
					/**
					* Velikost seznamu
					*/
					int mSize;
				};

				template<typename T> List<T>::List()
				{
					mHead = nullptr;
					mSize = 0;
				}

				template<typename T> List<T>::~List()
				{
					
				}

				template<typename T> void List<T>::Insert(T value)
				{
					Node* node = new Node();
					node->Value = value;
					node->Next = mHead;
					mHead = node;
					mSize++;
				}

				template<typename T> T List<T>::FirstItem()
				{
					return mHead->Value;
				}

				template<typename T> bool List<T>::IsEmpty() const
				{					
					return (Count() <= 0) ? true : false;
				}

				template<typename T> int List<T>::Count() const
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

				template<typename T> void List<T>::RemoveFirstItem()
				{
					if(!IsEmpty())
					{
						mHead = mHead->Next;
						mSize--;
					}					
				}				

				template<typename T> bool List<T>::Search(const T value)
				{
					if (!IsEmpty())
					{
						Node* node = mHead;
						while (node)
						{
							if (node->Value == value) return true;
							node = node->Next;
						}
						return false;
					}
					return false;
				}

				template<typename T> void List<T>::Clear()
				{
					Node* node = mHead;
					while (node)
					{
						mHead = mHead->Next;
						delete node;
						node = mHead;
					}
					mHead = nullptr;
					mSize = 0;
				}
			}
		}
	}
}
