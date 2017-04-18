#include "AdjacencyList.h"
#include <iostream>

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace LinkedStructures
		{
			namespace OOP
			{
				AdjacencyList::AdjacencyList()
				{
					table = new VertexNode*[mSize];
					for (int i = 0; i < mSize; i++)
						table[i] = nullptr;
				}

				AdjacencyList::~AdjacencyList()
				{
					for (int i = 0; i < mSize; ++i)
					{
						VertexNode* entry = table[i];
						while (entry != nullptr)
						{
							VertexNode* prev = entry;
							entry = entry->Next;
							delete prev;
						}
					}
					delete[] table;
				}

				int AdjacencyList::HashFunc(const int Value) const
				{
					return std::hash<int>()(Value) % mSize;
				}


				void AdjacencyList::AddVertex(const int Vertex)
				{
					int hash = HashFunc(Vertex);
					VertexNode *prev = nullptr;
					VertexNode *entry = table[hash];

					while (entry != nullptr && entry->Value != Vertex)
					{
						prev = entry;
						entry = entry->Next;
					}

					if (entry == nullptr)
					{
						entry = new VertexNode(Vertex);
						if (prev == nullptr) table[hash] = entry;
						else prev->Next = entry;
					}
					else entry->Value = Vertex;
				}

				bool AdjacencyList::ContainsVertex(const int Vertex) const
				{
					int hash = HashFunc(Vertex);
					VertexNode* entry = table[hash];
					while (entry != nullptr)
					{
						if (entry->Value == Vertex)
						{
							return true;
						}
						entry = entry->Next;
					}
					return false;
				}

				void AdjacencyList::AddEdge(const int FirstVertex, const int SecondVertex)
				{					
					int hash = HashFunc(FirstVertex);
					VertexNode *prev = nullptr;
					VertexNode *entry = table[hash];

					if (FirstVertex == SecondVertex)
					{
						entry->Selfloop = true;
					}

					if (entry->Value != FirstVertex) return;
					while (entry != nullptr)
					{
						prev = entry;
						entry = entry->Next;
					}
					if (entry == nullptr)
					{
						entry = new VertexNode(SecondVertex);
						prev->Next = entry;
					}				
				}

				void AdjacencyList::Report()
				{				
					VertexNode *entry = nullptr;
					VertexNode *prev = nullptr;
					for (int i = 0; i < mSize; i++)
					{
						if (table[i] != nullptr)
						{
							std::cout << table[i]->Value << " -> ";
							prev = table[i];
							entry = table[i]->Next;
							while (entry != nullptr)
							{				
								if (entry->Selfloop) std::cout << entry->Value << ", ";	
								std::cout << entry->Value << ", ";
								entry = entry->Next;
							}
							std::cout << std::endl;
						}							
					}
				}
			}
		}
	}
}
