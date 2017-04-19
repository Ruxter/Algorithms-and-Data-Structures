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
				* Matice se umí expandovat a redukovat v závislosti na operacích s ní
				* Pokud je èíslo v matici 0 - mezi tìmito dvìma vrcholy není hrana
				* Pokud je èíslo v matici 1 - mezi tìmito dvìma vrcholy existuje hrana
				* Pokud se nachází 1 na diagonále, jedná se o smyèku na daném uzlu
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
					* 
					* @param VertexCount Poèet uzlù
					*/
					AdjacencyMatrix(const int VertexCount);

					/**
					* Destruktor
					*/
					~AdjacencyMatrix();

					/**
					* Metoda pro vytvoøení hrany mezi dvìma vrcholy, poøadí zadávaných vrcholù je bezpøedmìtné, jelikož se jedná o neorientovaný graf
					* 
					* @param FirstVertex Uvedení prvního uzlu
					* @param SecondVertex Uvedení druhého uzlu
					*/
					void AddEdge(const int FirstVertex,const int SecondVertex);

					/**
					* Metoda pro vytvoøení uzlu, matice se pøípadnì expanduje
					* Prvek se vždy vloží na konec posloupnosti
					* 
					* @param Vertex Hodnota uzlu
					*/
					void AddVertex(const int Vertex);

					/**
					* Metoda pro odebrání uzlu, matice se redukuje a realokuje
					* 
					* @param Vertex Hodnota uzlu
					*/
					void RemoveVertex(const int Vertex);

					/**
					* Metoda pro odebrání hrany mezi dvìma vrcholy, poøadí zadávaných vrcholù je bezpøedmìtné, jelikož se jedná o neorientovaný graf
					* 
					* @param FirstVertex Hodnota uzlu
					* @param SecondVertex Hodnota uzlu
					*/
					void RemoveEdge(const int FirstVertex, const int SecondVertex);

					/**
					* Metoda pro zjištìní, zda je mezi dvìma vrcholy hrana, poøadí zadávaných vrcholù je bezpøedmìtné, jelikož se jedná o neorientovaný graf
					* 
					* @param FirstVertex Hodnota uzlu
					* @param SecondVertex Hodnota uzlu
					* 
					* @return true pokud je hranou, false pokud není
					*/
					bool IsEdge(const int FirstVertex, const int SecondVertex);

					/**
					* Metoda pro zjištìní, zda existuje daný uzel
					* 
					* @param Vertex Hodnota uzlu
					* @return true pokud se uzel nachází, false pokud ne
					*/
					bool IsVertex(const int Vertex) const;					

					/**
					* Nastaví všem hranám v matici 0
					*/
					void Clear() const;

					/**
					* Metoda pro výpis matice
					*/
					void Report() const;

					/**
					* Metoda pro výpis uzlù
					*/
					void PrintVertexes() const;
				private:

					/**
					 * Poèet uzlù
					 */
					int mCount;
					
					/**
					* Výchozí poèet uzlù
					*/
					int mDefaultCount = 6;

					/**
					 * Matice
					 */
					int** mMatrix;

					/**
					 * Uzly
					 */
					int* mVertexes;
					
					/**
					* Zjistí index daného uzlu
					* 
					* @param Vertex Hledaný uzel
					* @return index uzlu
					*/
					int VertexIndex(const int Vertex) const;
				};
			}
		}
	}
}