#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace OOP
			{
				/**
				* Implementace neorientovan�ho grafu pomoc� matice zp�sobem Adjacency Matrix
				* Matice je fixn� kapacity.
				* Pokud je ��slo v matici 0 - mezi t�mito dv�ma vrcholy nen� hrana
				* Pokud je ��slo v matici 1 - mezi t�mito dv�ma vrcholy existuje hrana
				* Pokud je ��slo v matici 2 - Vrchol m� self-loop
				* Matice je symetrick� pod�l diagon�ly. Tedy pokud vede hrana z vrcholu U do vrcholu V, t�m p�dem vede i z V do U.
				*/
				class AdjacencyMatrix
				{
				public:

					/**
					 * Konstruktor
					 */
					AdjacencyMatrix();

					/**
					* Konstruktor s volbou kapacity pole
					* @param VertexCount Po�et vrchol�
					*/
					AdjacencyMatrix(const int VertexCount);

					/**
					* Destruktor
					*/
					~AdjacencyMatrix();

					/**
					* Metoda pro vytvo�en� hrany mezi dv�ma vrcholy, po�ad� zad�van�ch vrchol� je bezp�edm�tn�, jeliko� se jedn� o neorientovan� graf
					* @param FirstVertex Uveden� prvn�ho vrcholu
					* @param SecondVertex Uveden� druh�ho vrcholu
					*/
					void AddEdge(int FirstVertex, int SecondVertex) const;

					/**
					* Metoda pro odebr�n� hrany mezi dv�ma vrcholy, po�ad� zad�van�ch vrchol� je bezp�edm�tn�, jeliko� se jedn� o neorientovan� graf
					* @param FirstVertex Po�et vrchol�
					* @param SecondVertex Po�et vrchol�
					*/
					void RemoveEdge(int FirstVertex, int SecondVertex) const;

					/**
					* Metoda pro zji�t�n�, zda je mezi dv�ma vrcholy hrana, po�ad� zad�van�ch vrchol� je bezp�edm�tn�, jeliko� se jedn� o neorientovan� graf
					* @param FirstVertex Po�et vrchol�
					* @param SecondVertex Po�et vrchol�
					*/
					bool IsEdge(int FirstVertex, int SecondVertex) const;

					/**
					* Metoda pro dealokaci matice
					*/
					void Clear() const;

					/**
					* Metoda pro v�pis matice
					*/
					void Report() const;
				private:

					/**
					 * Velikost pole
					 */
					int mCount = 6;

					/**
					 * Matice
					 */
					int** mMatrix;
				};
			}
		}
	}
}