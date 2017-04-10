#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/OOP/AdjacencyMatrix.h"

/*
* Soubor sloužící k testování neuspoøádané množiny
*/

/*
* Pomocná struktura pro testování
*/
struct GraphsTestOOPTemplate : testing::Test
{
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix *graph;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix *graph2;
	ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix *graph3;

	GraphsTestOOPTemplate()
	{
		graph = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix();
		graph2 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix(6);
		graph3 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix(3000);
	}

	~GraphsTestOOPTemplate()
	{
		delete graph;
		delete graph2;
		delete graph3;
	}
};
/*
* Unit test ArrayBasedStructures::OOP::AdjacencyMatrix
* AddEdge, Report, RemoveEdge, IsEdge
* @param GraphsTestOOPTemplate název struktury,
* @param GraphsTestOOPTemplate1 název unit testu
*/
TEST_F(GraphsTestOOPTemplate, GraphsTestOOPTemplate1)
{
	graph->AddEdge(5, 4);
	graph->AddEdge(4, 3);
	graph->AddEdge(3, 2);
	graph->AddEdge(3, 1);
	graph->AddEdge(1, 0);
	graph->AddEdge(2, 0);
	graph->Report();

	EXPECT_EQ(true, graph->IsEdge(4, 5));
	EXPECT_EQ(false, graph->IsEdge(0, 0));
	EXPECT_EQ(true, graph->IsEdge(3, 1));
	EXPECT_EQ(true, graph->IsEdge(0, 2));

	graph->RemoveEdge(2, 0);

	EXPECT_EQ(false, graph->IsEdge(0, 2));
	EXPECT_EQ(false, graph->IsEdge(2, 0));
}
/*
* Unit test ArrayBasedStructures::OOP::AdjacencyMatrix - ctor s parametrem
* AddEdge, Report, RemoveEdge, IsEdge
* @param GraphsTestOOPTemplate název struktury,
* @param GraphsTestOOPTemplate2 název unit testu
*/
TEST_F(GraphsTestOOPTemplate, GraphsTestOOPTemplate2)
{
	graph2->AddEdge(3, 5);
	graph2->AddEdge(3, 2);
	graph2->AddEdge(3, 4);
	graph2->AddEdge(2, 1);
	graph2->AddEdge(1, 4);
	graph2->AddEdge(1, 0);
	graph2->AddEdge(0, 4);
	graph2->AddEdge(0, 0);
	graph2->Report();

	EXPECT_EQ(true, graph2->IsEdge(3, 5));
	EXPECT_EQ(true, graph2->IsEdge(0, 0));
	EXPECT_EQ(true, graph2->IsEdge(4, 3));
	EXPECT_EQ(false, graph2->IsEdge(0, 2));

	graph->RemoveEdge(6, 0);

	EXPECT_EQ(false, graph->IsEdge(0, 0));
	EXPECT_EQ(false, graph->IsEdge(0, 0));
}

/*
* Unit test ArrayBasedStructures::OOP::AdjacencyMatrix - ctor s parametrem
* AddEdge, Report, RemoveEdge, IsEdge
* @param GraphsTestOOPTemplate název struktury,
* @param GraphsTestOOPTemplate2 název unit testu
*/
TEST_F(GraphsTestOOPTemplate, GraphsTestOOPTemplate3)
{
	graph3->AddEdge(351, 269);
	graph3->AddEdge(1869, 746);
	graph3->AddEdge(2365, 2365);
	graph3->AddEdge(2, 4);
	graph3->AddEdge(0, 4);
	graph3->AddEdge(1785, 985);
	graph3->AddEdge(2648, 1);
	graph3->AddEdge(0, 0);
	graph3->Report();

	EXPECT_EQ(true, graph3->IsEdge(351, 269));
	EXPECT_EQ(true, graph3->IsEdge(1785, 985));
	EXPECT_EQ(true, graph3->IsEdge(0, 0));
	EXPECT_EQ(false, graph3->IsEdge(0, 1));

	graph3->RemoveEdge(351, 269);

	EXPECT_EQ(false, graph3->IsEdge(351, 269));
	EXPECT_EQ(false, graph3->IsEdge(269, 351));
}