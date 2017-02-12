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
					* Vlo�en� prvku do seznamu. Prvek je vlo�en p�ed sou�asnou hlavu seznamu tj. stane se novou hlavou seznamu.
					* @param value Vkl�dan� prvek
					*/
					void Insert(T value);

					/**
					* @return Funkce vrac� head ze seznamu.
					*/
					T FirstItem();
					
					/**
					* Test je-li seznam pr�zdn�.
					* @return Funkce vrac� true pokud je seznam pr�zdn�, jinak false.
					*/
					bool IsEmpty() const;

					/**
					* Funkce vrac� po�et prvk� v seznamu.
					* @return Po�et prvk� v seznamu.
					*/
					int Count() const;

					/**
					* Odebr�n� head prvku ze seznamu.
					*/
					void RemoveFirstItem();

					/**
					* Hled�n� prvku v seznamu.
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
						T m_value;
						/**
						* Ukazatel na dal�� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu NULL.
						*/
						Node* m_next = NULL;
					};

					/**
					* Nejp�edn�j�� prvek seznamu
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
