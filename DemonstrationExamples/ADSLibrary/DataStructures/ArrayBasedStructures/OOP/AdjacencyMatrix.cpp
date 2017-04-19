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
					mVertexes = new int[mCount];
					for (int j = 0; j < mCount; j++)
					{
						mVertexes[j] = NULL;
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
					mVertexes = new int[mCount];
					for (int j = 0; j < mCount; j++)
					{
						mVertexes[j] = NULL;
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
					for (int x = 0; x < mCount; x++)
					{
						delete[] mMatrix[x];
					}
					delete[] mMatrix;
					delete[] mVertexes;
				}

				void AdjacencyMatrix::AddVertex(const int Vertex)
				{		
					bool expand = true;
					for (int i = 0; i < mCount; i++)
					{
						if (mVertexes[i] == Vertex) return;
						if (mVertexes[i] == NULL) 
						{
							mVertexes[i] = Vertex;
							expand = false;
							break;
						}
					}

					if (expand)
					{
						mCount++;
						int* newmVertexes = new int[mCount];
						for (int i = 0; i < mCount-1; i++)
						{
							newmVertexes[i] = mVertexes[i];
						}
						newmVertexes[mCount-1] = Vertex;
						delete[] mVertexes;
						mVertexes = newmVertexes;

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
						for (int x = 0; x < mCount-1; x++)
						{
							delete[] mMatrix[x];
						}
						delete[] mMatrix;
						mMatrix = newMatrix;						
					}
				}

				void AdjacencyMatrix::RemoveVertex(const int Vertex)
				{					
					for (int i = 0; i < mCount; i++)
					{
						if (mVertexes[i] == Vertex)
						{
							mCount--;
							for (int j = i; j < mCount; j++)
							{
								mVertexes[j] = mVertexes[j + 1];
							}							

							int** newMatrix = new int*[mCount];
							for (int x = 0; x < mCount; x++)
							{
								newMatrix[x] = new int[mCount];
								for (int y = 0; y < mCount; y++)
								{
									newMatrix[x][y] = 0;
								}
							}
							int removedVertex = i;
							int p = 0;
							for (int x = 0; x < mCount; ++x)
							{
								if (x == removedVertex)	continue;

								int q = 0;
								for (int y = 0; y < mCount; ++y)
								{
									if (y == removedVertex)	continue;

									newMatrix[p][q] = mMatrix[x][y];
									++q;
								}
								++p;
							}	
							for (int x = 0; x < mCount; x++)
							{
								delete[] mMatrix[x];
							}
							delete[] mMatrix;
							mMatrix = newMatrix;
						}						
					}
				}

				bool AdjacencyMatrix::IsVertex(const int Vertex) const
				{
					for (int i = 0; i < mCount; i++)
					{
						if (mVertexes[i] == Vertex) return true;
					}
					return false;
				}

				int AdjacencyMatrix::VertexIndex(const int Vertex) const
				{
					for (int i = 0; i < mCount; i++)
					{
						if (mVertexes[i] == Vertex) return i;
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
						std::cout << mVertexes[i] << " ";
					}
					std::cout << std::endl << "   ";
					for (int i = 0; i < mCount; i++)
					{
						std::cout << "_ ";
					}

					for (int i = 0; i < mCount; i++)
					{
						std::cout << std::endl << mVertexes[i] << "| ";
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
						std::cout << mVertexes[i] << " ";
					}
				}
			}
		}
	}
}
