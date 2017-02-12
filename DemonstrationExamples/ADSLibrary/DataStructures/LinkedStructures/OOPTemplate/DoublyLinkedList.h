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
					void InsertBegin(T value);
					/**
					* Vložení prvku na konec seznamu.
					*
					*/
					void InsertEnd(T value);
					/**
					* Nalezení prvku v listu.
					* @return Funkce vrací true pokud je daný element v seznamu, jinak false.
					*/
					bool SearchItem(T Item) const;					
					/**
					* Odebrání prvního prvku ze seznamu-
					*
					*/
					void RemoveFirstItem();
					/**
					* Odebrání posledního prvku ze seznamu-
					*
					*/
					void RemoveLastItem();
					/**
					* Test, je-li seznam prázdný.
					*
					* @return Funkce vrací true pokud je seznam prázdný, jinak false.
					*/
					bool IsEmpty() const;
					/**
					* Spoèítá prvky
					*
					*/
					int Count() const;
					/**
					* @return Funkce vrací poslední prvek ze seznamu.
					*/
					T LastItem() const;

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

				template<typename T> bool DoublyLinkedList<T>::SearchItem(T value) const
				{
					if (!IsEmpty())
					{
						Node* node = head;
						while (node)
						{
							if (node->m_value == value) return true;
							node = node->m_next;
						}
						return false;
					}
					return false;
				}

				template <typename T> void DoublyLinkedList<T>::InsertBegin(T value)
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

				template <typename T> void DoublyLinkedList<T>::InsertEnd(T value)
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

				template <typename T> void DoublyLinkedList<T>::RemoveFirstItem()
				{
					if (!IsEmpty())
					{
						Node* node = head;
						if (head == tail) tail = NULL;
						head = node->m_next;
						head->m_prev = NULL;
						delete node;
						m_size--;						
					}					
				}

				template <typename T> void DoublyLinkedList<T>::RemoveLastItem()
				{
					if (!IsEmpty())
					{
						if (head == tail) head = NULL;	
						
						tail = tail->m_prev;
						tail->m_next = NULL;
						m_size--;
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

				template<typename T> void DoublyLinkedList<T>::Clear()
				{
					Node* node= head;					
					while (node) 
					{
						head = head->m_next;
						delete node;						
						node = head;
					}					
					tail = head = NULL;
					m_size = Count();
				}			
			}
		}
	}
}
