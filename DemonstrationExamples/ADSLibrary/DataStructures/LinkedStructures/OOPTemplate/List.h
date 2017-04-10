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
				* \brief Seznam implementovan� pomoc� spojov�ch struktur s vyu�it�m %OOPTemplate
				*
				* Implementace jednosm�rn�ho seznamu pomoc� spojov�ch struktur.
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
					* Vlo�en� prvku do seznamu. Prvek je vlo�en p�ed sou�asnou hlavu seznamu tj. stane se novou hlavou seznamu.
					* 
					* @param value Vkl�dan� prvek
					*/
					void Insert(T value);

					/**
					* Vrac� hlavu seznamu
					*
					* @return Hlava seznamu
					*/
					T FirstItem();
					
					/**
					* Test je-li seznam pr�zdn�.
					* 
					* @return Funkce vrac� true pokud je seznam pr�zdn�, jinak false.
					*/
					bool IsEmpty() const;

					/**
					* Funkce vrac� po�et prvk� v seznamu.
					* 
					* @return Po�et prvk� v seznamu.
					*/
					int Count() const;

					/**
					* Odebr�n� mHead prvku ze seznamu.
					*/
					void RemoveFirstItem();

					/**
					* Hled�n� prvku v seznamu.
					* 
					* @param value Hledan� prvek
					* @return Funkce vrac� true v p��pad�, �e je prvek X nalezen, jinak vrac� false.
					*/
					bool Search(const T value);

					/**
					* Smaz�n� cel�ho seznamu.
					*
					*/
					void Clear();

				private:
					/**
					* \brief Struktura reprezentuj�c� polo�ku v seznamu.
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
						Node* Next;
					};

					/**
					* Nejp�edn�j�� prvek seznamu
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
