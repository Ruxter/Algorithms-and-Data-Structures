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
				* Matice se um� expandovat a redukovat v z�vislosti na operac�ch s n�
				* Pokud je ��slo v matici 0 - mezi t�mito dv�ma vrcholy nen� hrana
				* Pokud je ��slo v matici 1 - mezi t�mito dv�ma vrcholy existuje hrana
				* Pokud se nach�z� 1 na diagon�le, jedn� se o smy�ku na dan�m uzlu
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
					* 
					* @param VertexCount Po�et uzl�
					*/
					AdjacencyMatrix(const int VertexCount);

					/**
					* Destruktor
					*/
					~AdjacencyMatrix();

					/**
					* Metoda pro vytvo�en� hrany mezi dv�ma vrcholy, po�ad� zad�van�ch vrchol� je bezp�edm�tn�, jeliko� se jedn� o neorientovan� graf
					* 
					* @param FirstVertex Uveden� prvn�ho uzlu
					* @param SecondVertex Uveden� druh�ho uzlu
					*/
					void AddEdge(const int FirstVertex,const int SecondVertex);

					/**
					* Metoda pro vytvo�en� uzlu, matice se p��padn� expanduje
					* Prvek se v�dy vlo�� na konec posloupnosti
					* 
					* @param Vertex Hodnota uzlu
					*/
					void AddVertex(const int Vertex);

					/**
					* Metoda pro odebr�n� uzlu, matice se redukuje a realokuje
					* 
					* @param Vertex Hodnota uzlu
					*/
					void RemoveVertex(const int Vertex);

					/**
					* Metoda pro odebr�n� hrany mezi dv�ma vrcholy, po�ad� zad�van�ch vrchol� je bezp�edm�tn�, jeliko� se jedn� o neorientovan� graf
					* 
					* @param FirstVertex Hodnota uzlu
					* @param SecondVertex Hodnota uzlu
					*/
					void RemoveEdge(const int FirstVertex, const int SecondVertex);

					/**
					* Metoda pro zji�t�n�, zda je mezi dv�ma vrcholy hrana, po�ad� zad�van�ch vrchol� je bezp�edm�tn�, jeliko� se jedn� o neorientovan� graf
					* 
					* @param FirstVertex Hodnota uzlu
					* @param SecondVertex Hodnota uzlu
					* 
					* @return true pokud je hranou, false pokud nen�
					*/
					bool IsEdge(const int FirstVertex, const int SecondVertex);

					/**
					* Metoda pro zji�t�n�, zda existuje dan� uzel
					* 
					* @param Vertex Hodnota uzlu
					* @return true pokud se uzel nach�z�, false pokud ne
					*/
					bool IsVertex(const int Vertex) const;					

					/**
					* Nastav� v�em hran�m v matici 0
					*/
					void Clear() const;

					/**
					* Metoda pro v�pis matice
					*/
					void Report() const;

					/**
					* Metoda pro v�pis uzl�
					*/
					void PrintVertexes() const;
				private:

					/**
					 * Po�et uzl�
					 */
					int mCount;
					
					/**
					* V�choz� po�et uzl�
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
					* Zjist� index dan�ho uzlu
					* 
					* @param Vertex Hledan� uzel
					* @return index uzlu
					*/
					int VertexIndex(const int Vertex) const;
				};
			}
		}
	}
}