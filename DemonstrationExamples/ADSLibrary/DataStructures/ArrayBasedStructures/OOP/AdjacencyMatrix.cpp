#include "AdjacencyMatrix.h"
#include <iostream>

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOP
			{
				AdjacencyMatrix::AdjacencyMatrix()
				{
					vertexes = new int[mCount];
					for (int j = 0; j < mCount; j++)
					{
						vertexes[j] = NULL;
					}
					mMatrix = new int*[mCount];
					for (int i = 0; i < mCount; i++)
					{
						mMatrix[i] = new int[mCount];
						for (int j = 0; j < mCount; j++)
						{
							mMatrix[i][j] = 0;
						}						
					}
				}

				AdjacencyMatrix::AdjacencyMatrix(int VertexCount)
				{
					if (VertexCount >= 0) mCount = VertexCount;
					else return;
					vertexes = new int[mCount];
					for (int j = 0; j < mCount; j++)
					{
						vertexes[j] = NULL;
					}
					mMatrix = new int*[mCount];
					for (int i = 0; i < mCount; i++)
					{
						mMatrix[i] = new int[mCount];
						for (int j = 0; j < mCount; j++)
						{
							mMatrix[i][j] = 0;
						}
					}
				}

				AdjacencyMatrix::~AdjacencyMatrix()
				{
					for (int i = 0; i < mCount; i++)
					{
						delete[] mMatrix[i];
					}
					delete[] mMatrix;
					delete[] vertexes;
				}

				void AdjacencyMatrix::AddVertex(const int Vertex)
				{		
					for (int i = 0; i < mCount; i++)
					{
						if (vertexes[i] == Vertex) return;
						if (vertexes[i] == NULL) 
						{
							vertexes[i] = Vertex;
							break;
						}
					}
				}

				void AdjacencyMatrix::RemoveVertex(const int Vertex)
				{
					int position;
					for (int i = 0; i < mCount; i++)
					{
						if (vertexes[i] == Vertex)
						{
							position = i;
							for (int j = position; j < mCount; j++)
							{
								vertexes[j] = vertexes[j + 1];
							}								
							
							mCount--;							
						}						
					}
				}

				bool AdjacencyMatrix::IsVertex(const int Vertex) const
				{
					for (int i = 0; i < mCount; i++)
					{
						if (vertexes[i] == Vertex) return true;
					}
					return false;
				}

				int AdjacencyMatrix::VertexIndex(const int Vertex) const
				{
					for (int i = 0; i < mCount; i++)
					{
						if (vertexes[i] == Vertex) return i;
					}
					return -1;
				}

				void AdjacencyMatrix::AddEdge(int FirstVertex, int SecondVertex)
				{	
					if (IsVertex(FirstVertex) && IsVertex(SecondVertex))
					{
						mMatrix[VertexIndex(FirstVertex)][VertexIndex(SecondVertex)] = 1;
						mMatrix[VertexIndex(SecondVertex)][VertexIndex(FirstVertex)] = 1;
					}																		
				}

				void AdjacencyMatrix::RemoveEdge(int FirstVertex, int SecondVertex)
				{
					if (IsEdge(FirstVertex, SecondVertex))
					{
						mMatrix[VertexIndex(FirstVertex)][VertexIndex(SecondVertex)] = 0;
						mMatrix[VertexIndex(SecondVertex)][VertexIndex(FirstVertex)] = 0;
					}									
				}

				bool AdjacencyMatrix::IsEdge(int FirstVertex, int SecondVertex) 
				{
					if (mMatrix[VertexIndex(FirstVertex)][VertexIndex(SecondVertex)] == 1) return true;
					return false;					
				}

				void AdjacencyMatrix::Clear() const
				{
					for (int i = 0; i < mCount; i++)
					{
						for (int j = 0; j < mCount; j++)
						{
							mMatrix[i][j] = 0;
						}
					}	

					for (int i = 0; i < mCount; i++)
					{
						vertexes[i] = NULL;
					}					
				}

				void AdjacencyMatrix::Report() const
				{
					std::cout << std::endl << "   ";
					for (int i = 0; i < mCount; i++)
					{
						std::cout << vertexes[i] << " ";
					}
					std::cout << std::endl << "   ";
					for (int i = 0; i < mCount; i++)
					{
						std::cout << "_ ";
					}

					for (int i = 0; i < mCount; i++)
					{
						std::cout << std::endl << vertexes[i] << "| ";
						for (int j = 0; j < mCount; ++j)
						{
							std::cout << mMatrix[i][j] << ' ';
						}
						std::cout << std::endl;
					}
					
				}
			}
		}
	}
}
