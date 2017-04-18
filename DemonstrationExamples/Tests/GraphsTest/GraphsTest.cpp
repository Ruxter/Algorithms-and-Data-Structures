#include <gtest/gtest.h>
#include "../../ADSLibrary/DataStructures/ArrayBasedStructures/OOP/AdjacencyMatrix.h"
#include "../../ADSLibrary/DataStructures/LinkedStructures/OOP/AdjacencyList.h"

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
	ADSLibrary::DataStructures::LinkedStructures::OOP::AdjacencyList *graph5;

	GraphsTestOOP()
	{
		graph = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix();
		graph2 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix(6);
		graph3 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix(3000);
		graph4 = new ADSLibrary::DataStructures::ArrayBasedStructures::OOP::AdjacencyMatrix(6);
		graph5 = new ADSLibrary::DataStructures::LinkedStructures::OOP::AdjacencyList();
	}

	~GraphsTestOOP()
	{
		delete graph;
		delete graph2;
		delete graph3;
		delete graph4;
		delete graph5;
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
* @param GraphsTestOOP název struktury,
* @param GraphsTestOOP2 název unit testu
*/
TEST_F(GraphsTestOOP, GraphsTestOOP2)
{
	graph2->AddEdge(3, 5);
	graph2->AddEdge(3, 2);
	graph2->AddEdge(3, 4);
	graph2->AddEdge(2, 1);
	graph2->AddEdge(1, 4);
	graph2->AddEdge(1, 0);
	graph2->AddEdge(0, 4);
	graph2->AddEdge(0, 0);
	//graph2->Report();

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
* @param GraphsTestOOP název struktury,
* @param GraphsTestOOP3 název unit testu
*/
TEST_F(GraphsTestOOP, GraphsTestOOP3)
{
	graph3->AddEdge(351, 269);
	graph3->AddEdge(1869, 746);
	graph3->AddEdge(2365, 2365);
	graph3->AddEdge(2, 4);
	graph3->AddEdge(0, 4);
	graph3->AddEdge(1785, 985);
	graph3->AddEdge(2648, 1);
	graph3->AddEdge(0, 0);
	//graph3->Report();

	EXPECT_EQ(true, graph3->IsEdge(351, 269));
	EXPECT_EQ(true, graph3->IsEdge(1785, 985));
	EXPECT_EQ(true, graph3->IsEdge(0, 0));
	EXPECT_EQ(false, graph3->IsEdge(0, 1));

	graph3->RemoveEdge(351, 269);

	EXPECT_EQ(false, graph3->IsEdge(351, 269));
	EXPECT_EQ(false, graph3->IsEdge(269, 351));
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

/*
* Unit test LinkedStructures::OOP::AdjacencyList
* AddVertex, ContainsVertex
* @param GraphsTestOOP název struktury,
* @param GraphsTestOOP5 název unit testu
*/
TEST_F(GraphsTestOOP, GraphsTestOOP5)
{	
	graph5->AddVertex(1);
	graph5->AddVertex(10);
	graph5->AddVertex(2);

	graph5->AddEdge(1, 1);
	graph5->AddEdge(1, 10);
	graph5->AddEdge(1, 2);
	
	graph5->Report();

	EXPECT_EQ(true, graph5->ContainsVertex(1));
	EXPECT_EQ(true, graph5->ContainsVertex(2));
	EXPECT_EQ(true, graph5->ContainsVertex(10));

}
