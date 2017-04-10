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
					mMatrix = new int*[mCount];
					for (int i = 0; i < mCount; i++)
					{
						mMatrix[i] = new int[mCount];
						for (int j = 0; j < mCount; j++)
						{
							mMatrix[i][j] = false;
						}						
					}
				}

				AdjacencyMatrix::AdjacencyMatrix(int VertexCount)
				{
					mCount = VertexCount;
					mMatrix = new int*[mCount];
					for (int i = 0; i < mCount; i++)
					{
						mMatrix[i] = new int[mCount];
						for (int j = 0; j < mCount; j++)
						{
							mMatrix[i][j] = false;
						}
					}
				}

				AdjacencyMatrix::~AdjacencyMatrix()
				{
					Clear();
				}

				void AdjacencyMatrix::AddEdge(int FirstVertex, int SecondVertex) const
				{
					if ((FirstVertex >= 0 && FirstVertex < mCount) && (SecondVertex >= 0 && SecondVertex < mCount))
					{
						if (FirstVertex == SecondVertex)
						{
							mMatrix[FirstVertex][SecondVertex] = 2;
							mMatrix[SecondVertex][FirstVertex] = 2;
						}
						else
						{
							mMatrix[FirstVertex][SecondVertex] = 1;
							mMatrix[SecondVertex][FirstVertex] = 1;
						}						
					}					
				}

				void AdjacencyMatrix::RemoveEdge(int FirstVertex, int SecondVertex) const
				{
					if ((FirstVertex >= 0 && FirstVertex < mCount) && (SecondVertex >= 0 && SecondVertex < mCount))
					{
						mMatrix[FirstVertex][SecondVertex] = 0;
						mMatrix[SecondVertex][FirstVertex] = 0;
					}
				}

				bool AdjacencyMatrix::IsEdge(int FirstVertex, int SecondVertex) const
				{
					if ((mMatrix[FirstVertex][SecondVertex] == 1) || (mMatrix[FirstVertex][SecondVertex] == 2)) return true;
					return false;					
				}

				void AdjacencyMatrix::Clear() const
				{
					for (int i = 0; i < mCount; i++)
					{
						delete[] mMatrix[i];
					}	
					delete mMatrix;
				}

				void AdjacencyMatrix::Report() const
				{
					std::cout << std::endl << "    ";
					for (int i = 0; i < mCount; i++)
					{
						std::cout << i << " ";
					}
					std::cout << std::endl;
					std::cout << "   ";
					for (int i = 0; i < mCount; i++)
					{
						std::cout << " _";
					}
					std::cout << std::endl;
					for (int i = 0; i < mCount; i++)
					{
						std::cout << i << " | ";
						for (int j = 0; j < mCount; j++)
						{
							std::cout << mMatrix[i][j] << " ";
						}
						std::cout << std::endl;
					}
				}
			}
		}
	}
}
