#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/OOP/AdjacencyMatrix.h"

/*
* Soubor sloužící k testování neuspoøádané množiny. 
*/

/*
* Pomocná struktura pro testování
*/
struct GraphsTestOOP : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix *graph;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix *graph2;

	GraphsTestOOP()
	{
		graph = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix();
		graph2 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix(9);
	}
	~GraphsTestOOP()
	{
		delete graph;
		delete graph2;
	}
};
/*
* Unit test ArrayBasedStructures::OOP::AdjacencyMatrix
* AddVertex, AddEdge, RemoveVertex, Report
* @param GraphsTestOOPTemplate název struktury,
* @param GraphsTestOOP1 název unit testu
*/
TEST_F(GraphsTestOOP, GraphsTestOOP1)
{
	graph->AddVertex(1);
	graph->AddVertex(2);
	graph->AddVertex(8);
	graph->AddVertex(9);
	graph->AddVertex(7);
	graph->AddVertex(5);

	graph->AddEdge(1, 1);
	graph->AddEdge(8, 8);
	graph->AddEdge(1, 7);

	graph->Report();
	graph->RemoveVertex(2);
	graph->Report();
	graph->AddVertex(2);
	graph->Report();

	graph->AddEdge(2, 8);
	graph->AddEdge(8, 5);
	graph->Report();
}
/*
* Unit test ArrayBasedStructures::OOP::AdjacencyMatrix - ctor s parametrem
* AddVertex, AddEdge, IsEdge, Clear, Report, RemoveEdge
* @param GraphsTestOOP název struktury,
* @param GraphsTestOOP2 název unit testu
*/
TEST_F(GraphsTestOOP, GraphsTestOOP2)
{
	graph2->Report();
	graph2->AddVertex(9);
	graph2->AddVertex(5);
	graph2->AddVertex(3);
	graph2->AddVertex(7);
	graph2->AddVertex(6);
	graph2->AddVertex(1);
	graph2->AddVertex(4);
	graph2->AddVertex(8);

	graph2->AddEdge(1, 1);
	graph2->AddEdge(6, 6);
	graph2->AddEdge(1, 7);
	graph2->AddEdge(3, 9);

	graph2->Report();

	graph2->AddVertex(10);
	graph2->Report();

	graph2->AddVertex(19);
	graph2->Report();
	graph2->AddVertex(12);
	graph2->Report();

	EXPECT_EQ(true, graph2->IsEdge(1, 1));
	graph2->RemoveEdge(1, 1);
	EXPECT_EQ(false, graph2->IsEdge(1, 1));
	graph2->Clear();
	EXPECT_EQ(false, graph2->IsEdge(6, 6));
	graph2->Report();
}