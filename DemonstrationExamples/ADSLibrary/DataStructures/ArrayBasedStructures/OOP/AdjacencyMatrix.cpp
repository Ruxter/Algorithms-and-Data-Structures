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
					mCount = mDefaultCount;
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

				AdjacencyMatrix::AdjacencyMatrix(const int VertexCount)
				{
					if (VertexCount >= 0) mCount = VertexCount;
					else mCount = mDefaultCount;
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
					bool expand = true;
					for (int i = 0; i < mCount; i++)
					{
						if (vertexes[i] == Vertex) return;
						if (vertexes[i] == NULL) 
						{
							vertexes[i] = Vertex;
							expand = false;
							break;
						}
					}

					if (expand)
					{
						mCount++;
						int* newVertexes = new int[mCount];
						for (int i = 0; i < mCount-1; i++)
						{
							newVertexes[i] = vertexes[i];
						}
						newVertexes[mCount-1] = Vertex;
						delete[] vertexes;
						vertexes = newVertexes;

						int** newMatrix = new int*[mCount];
						for (int x = 0; x < mCount; x++)
						{
							newMatrix[x] = new int[mCount];
							for (int y = 0; y < mCount; y++)
							{
								newMatrix[x][y] = 0;
							}
						}

						for (int x = 0; x < mCount-1; x++)
						{
							for (int y = 0; y < mCount-1; y++)
							{
								newMatrix[x][y] = mMatrix[x][y];
							}
						}						
						mMatrix = newMatrix;
					}
				}

				void AdjacencyMatrix::RemoveVertex(const int Vertex)
				{					
					for (int i = 0; i < mCount; i++)
					{
						if (vertexes[i] == Vertex)
						{
							for (int j = i; j < mCount-1; j++)
							{
								vertexes[j] = vertexes[j + 1];
							}							

							int** newMatrix = new int*[mCount-1];
							for (int x = 0; x < mCount; x++)
							{
								newMatrix[x] = new int[mCount-1];
								for (int y = 0; y < mCount; y++)
								{
									newMatrix[x][y] = 0;
								}
							}
							int removedVertex = i;
							int p = 0;
							for (int x = 0; x < mCount-1; ++x)
							{
								if (x == removedVertex)	continue;

								int q = 0;
								for (int y = 0; y < mCount-1; ++y)
								{
									if (y == removedVertex)	continue;

									newMatrix[p][q] = mMatrix[x][y];
									++q;
								}
								++p;
							}			
							mMatrix = newMatrix;
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

				void AdjacencyMatrix::AddEdge(const int FirstVertex, const int SecondVertex)
				{	
					if (IsVertex(FirstVertex) && IsVertex(SecondVertex))
					{
						mMatrix[VertexIndex(FirstVertex)][VertexIndex(SecondVertex)] = 1;
						mMatrix[VertexIndex(SecondVertex)][VertexIndex(FirstVertex)] = 1;
					}																		
				}

				void AdjacencyMatrix::RemoveEdge(const int FirstVertex, const int SecondVertex)
				{
					if (IsEdge(FirstVertex, SecondVertex))
					{
						mMatrix[VertexIndex(FirstVertex)][VertexIndex(SecondVertex)] = 0;
						mMatrix[VertexIndex(SecondVertex)][VertexIndex(FirstVertex)] = 0;
					}									
				}

				bool AdjacencyMatrix::IsEdge(const int FirstVertex, const int SecondVertex) 
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
				void AdjacencyMatrix::PrintVertexes() const
				{
					std::cout << std::endl << "   ";
					for (int i = 0; i < mCount; i++)
					{
						std::cout << vertexes[i] << " ";
					}
				}
			}
		}
	}
}
