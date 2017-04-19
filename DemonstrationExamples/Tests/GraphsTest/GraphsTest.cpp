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
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix *graph3;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix *graph4;

	GraphsTestOOP()
	{
		graph = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix();
		graph2 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix(10);
		graph3 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix(3000);
		graph4 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix(6);
	}
	~GraphsTestOOP()
	{
		delete graph;
		delete graph2;
		delete graph3;
		delete graph4;
	}
};
/*
* Unit test ArrayBasedStructures::OOP::AdjacencyMatrix
* AddEdge, Report, RemoveEdge, IsEdge
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
}
/*
* Unit test ArrayBasedStructures::OOP::AdjacencyMatrix - ctor s parametrem
* AddEdge, Report, RemoveEdge, IsEdge
* @param GraphsTestOOP název struktury,
* @param GraphsTestOOP2 název unit testu
*/
TEST_F(GraphsTestOOP, GraphsTestOOP2)
{
	graph2->AddVertex(9);
	graph2->AddVertex(5);
	graph2->AddVertex(3);
	graph2->AddVertex(7);
	graph2->AddVertex(6);
	graph2->AddVertex(1);

	graph2->AddEdge(1, 1);
	graph2->AddEdge(6, 6);
	graph2->AddEdge(1, 7);
	graph2->AddEdge(3, 9);

	graph2->Report();
}

/*
* Unit test ArrayBasedStructures::OOP::AdjacencyMatrix - ctor s parametrem
* AddEdge, Report, RemoveEdge, IsEdge
* @param GraphsTestOOP název struktury,
* @param GraphsTestOOP3 název unit testu
*/
TEST_F(GraphsTestOOP, GraphsTestOOP3)
{
	graph->AddVertex(8);
	graph->AddVertex(7);
	graph->AddVertex(9);
	graph->AddVertex(1);
	graph->AddVertex(5);
	graph->AddVertex(4);
	graph->Report();


	graph->AddVertex(2);
	graph->Report();
}
/*
* Unit test ArrayBasedStructures::OOP::AdjacencyMatrix - ctor s parametrem
* AddEdge, Report, RemoveEdge, IsEdge
* @param GraphsTestOOP název struktury,
* @param GraphsTestOOP4 název unit testu
*/
TEST_F(GraphsTestOOP, GraphsTestOOP4)
{
	graph4->AddEdge(1, 1);
	graph4->AddEdge(1, 2);
	graph4->AddEdge(2, 4);
	graph4->AddEdge(4, 3);
	graph4->AddEdge(3, 5);
	graph4->AddEdge(1, 3);
	graph4->Report();

	EXPECT_EQ(true, graph4->IsEdge(1, 1));
	EXPECT_EQ(true, graph4->IsEdge(1, 2));
	EXPECT_EQ(true, graph4->IsEdge(3, 4));
	EXPECT_EQ(false, graph4->IsEdge(0, 1));

	graph4->RemoveEdge(1, 3);

	EXPECT_EQ(false, graph4->IsEdge(1, 3));
	EXPECT_EQ(false, graph4->IsEdge(40, 8));
}
