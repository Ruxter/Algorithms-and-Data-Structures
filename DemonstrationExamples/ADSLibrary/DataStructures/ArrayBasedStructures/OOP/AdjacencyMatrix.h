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
				* Implementace neorientovaného grafu pomocí matice zpùsobem Adjacency Matrix
				* Matice je fixní kapacity.
				* Pokud je èíslo v matici 0 - mezi tìmito dvìma vrcholy není hrana
				* Pokud je èíslo v matici 1 - mezi tìmito dvìma vrcholy existuje hrana
				* Pokud je èíslo v matici 2 - Vrchol má self-loop
				* Matice je symetrická podél diagonály. Tedy pokud vede hrana z vrcholu U do vrcholu V, tím pádem vede i z V do U.
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
					* @param VertexCount Poèet vrcholù
					*/
					AdjacencyMatrix(const int VertexCount);

					/**
					* Destruktor
					*/
					~AdjacencyMatrix();

					/**
					* Metoda pro vytvoøení hrany mezi dvìma vrcholy, poøadí zadávaných vrcholù je bezpøedmìtné, jelikož se jedná o neorientovaný graf
					* @param FirstVertex Uvedení prvního vrcholu
					* @param SecondVertex Uvedení druhého vrcholu
					*/
					void AddEdge(int FirstVertex, int SecondVertex) const;

					/**
					* Metoda pro odebrání hrany mezi dvìma vrcholy, poøadí zadávaných vrcholù je bezpøedmìtné, jelikož se jedná o neorientovaný graf
					* @param FirstVertex Poèet vrcholù
					* @param SecondVertex Poèet vrcholù
					*/
					void RemoveEdge(int FirstVertex, int SecondVertex) const;

					/**
					* Metoda pro zjištìní, zda je mezi dvìma vrcholy hrana, poøadí zadávaných vrcholù je bezpøedmìtné, jelikož se jedná o neorientovaný graf
					* @param FirstVertex Poèet vrcholù
					* @param SecondVertex Poèet vrcholù
					*/
					bool IsEdge(int FirstVertex, int SecondVertex) const;

					/**
					* Metoda pro dealokaci matice
					*/
					void Clear() const;

					/**
					* Metoda pro výpis matice
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