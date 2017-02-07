#pragma once
#include <stdio.h>

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
					*
					*/
					void InsertBegin(int value);

					/**
					* Vlo�en� prvku na konec seznamu.
					*
					*/
					void InsertEnd(int value);
					/**
					* Nalezen� prvku v listu
					*
					*/
					void SearchItem() const;

					/**
					* Odebr�n� prvku z listu
					*
					*/
					void RemoveItem() const;

					/**
					* Test, je-li seznam pr�zdn�.
					*
					* @return Funkce vrac� true pokud je seznam pr�zdn�, jinak false.
					*/
					bool IsEmpty() const;

					/**
					* Spo��t� prvky
					*
					*/
					int Count() const;

					T LastItem() const;

				private:
					/**
					* \brief Struktura reprezentuj�c� element seznamu
					*/
					struct Node
					{
						/**
						* Hodnota obsa�en� v polo�ce.
						*/
						T m_value;
						/**
						* Ukazatel na dal�� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu NULL.
						*/
						Node* m_next;
						/**
						* Ukazatel na p�edchoz� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu NULL.
						*/
						Node* m_prev;
					};
					/**
					* Nejp�edn�j�� prvek seznamu
					*/
					Node* head;
					/**
					* Nejzadn�j�� prvek seznamu
					*/
					Node* tail;
					/**
					* Velikost seznamu
					*/
					int m_size;
				};

				template<typename T> DoublyLinkedList<T>::DoublyLinkedList()
				{
					head = NULL;
					tail = NULL;
					m_size = 0;
				}

				template<typename T> DoublyLinkedList<T>::~DoublyLinkedList()
				{

				}

				template <typename T> void DoublyLinkedList<T>::InsertBegin(int value)
				{
					Node* node = new Node();
					node->m_value = value;
					if (head == NULL)
					{
						head = node;
						tail = node;
					}
					else
					{
						head->m_prev = node;
						node->m_next = head;
						head = node;
					}
					m_size++;
				}

				template <typename T> void DoublyLinkedList<T>::InsertEnd(int value)
				{
					Node* node = new Node();
					node->m_value = value;
					if (tail == NULL)
					{
						head = node;
						tail = node;
					}
					else
					{
						tail->m_next = node;
						node->m_prev = tail;
						tail = node;
					}
					m_size++;
				}

				template<typename T> bool DoublyLinkedList<T>::IsEmpty() const
				{
					if (m_size <= 0)
					{
						return true;
					}

					return false;
				}

				template<typename T> int DoublyLinkedList<T>::Count() const
				{
					Node* node = head;
					int count = 0;
					while (node != NULL)
					{
						count++;
						node = node->m_next;
					}
					return count;
				}

				template<typename T> T DoublyLinkedList<T>::LastItem() const
				{
					Node* node = tail;
					return node->m_value;
				}

			}
		}
	}
}
