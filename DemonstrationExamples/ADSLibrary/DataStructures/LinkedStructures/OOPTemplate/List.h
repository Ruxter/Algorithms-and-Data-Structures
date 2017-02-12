#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOPTemplate
			{
				
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
					* @param value Vkládaný prvek
					*/
					void Insert(T value);

					/**
					* @return Funkce vrací head ze seznamu.
					*/
					T FirstItem();
					
					/**
					* Test je-li seznam prázdný.
					* @return Funkce vrací true pokud je seznam prázdný, jinak false.
					*/
					bool IsEmpty() const;

					/**
					* Funkce vrací poèet prvkù v seznamu.
					* @return Poèet prvkù v seznamu.
					*/
					int Count() const;

					/**
					* Odebrání head prvku ze seznamu.
					*/
					void RemoveFirstItem();

					/**
					* Hledání prvku v seznamu.
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
						T m_value;
						/**
						* Ukazatel na další položku. Pokud taková položka neexistuje ukazatel má hodnotu NULL.
						*/
						Node* m_next = NULL;
					};

					/**
					* Nejpøednìjší prvek seznamu
					*/
					Node* head;
					
					/**
					* Velikost seznamu
					*/
					int m_size;
				};

				template<typename T> List<T>::List()
				{
					head = NULL;
					m_size = 0;
				}

				template<typename T> List<T>::~List()
				{
					
				}

				template<typename T> void List<T>::Insert(T value)
				{
					Node* node = new Node();
					node->m_value = value;
					node->m_next = head;
					head = node;
					m_size++;
				}

				template<typename T> T List<T>::FirstItem()
				{
					return head->m_value;
				}

				template<typename T> bool List<T>::IsEmpty() const
				{					
					return (Count() <= 0) ? true : false;
				}

				template<typename T> int List<T>::Count() const
				{
					Node* node = head;
					int count = 0;
					while (node)
					{
						count++;
						node = node->m_next;
					}
					return count;
				}

				template<typename T> void List<T>::RemoveFirstItem()
				{
					Node *n = head;
					head = head->m_next;
					delete n;
					m_size--;
				}				

				template<typename T> bool List<T>::Search(const T value)
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

				template<typename T> void List<T>::Clear()
				{
					Node* node = head;
					while (node)
					{
						head = head->m_next;
						delete node;
						node = head;
					}
					head = NULL;
					m_size = 0;
				}
			}
		}
	}
}
