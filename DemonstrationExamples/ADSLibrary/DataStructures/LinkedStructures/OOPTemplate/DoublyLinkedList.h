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
					* Vložení prvku na zaèátek seznamu.
					*
					*/
					void InsertBegin(int value);

					/**
					* Vložení prvku na konec seznamu.
					*
					*/
					void InsertEnd(int value);
					/**
					* Nalezení prvku v listu
					*
					*/
					void SearchItem() const;

					/**
					* Odebrání prvku z listu
					*
					*/
					void RemoveItem() const;

					/**
					* Test, je-li seznam prázdný.
					*
					* @return Funkce vrací true pokud je seznam prázdná, jinak false.
					*/
					bool IsEmpty() const;

					/**
					* Spoèítá prvky
					*
					*/
					int Count() const;

					T LastItem() const;

				private:
					/**
					* \brief Struktura reprezentující element seznamu
					*/
					struct Node
					{
						/**
						* Hodnota obsažená v položce.
						*/
						T m_value;
						/**
						* Ukazatel na další položku. Pokud taková položka neexistuje ukazatel má hodnotu NULL.
						*/
						Node* m_next;
						/**
						* Ukazatel na pøedchozí položku. Pokud taková položka neexistuje ukazatel má hodnotu NULL.
						*/
						Node* m_prev;
					};
					/**
					* Nejpøednìjší prvek seznamu
					*/
					Node* head;
					/**
					* Nejzadnìjší prvek seznamu
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
