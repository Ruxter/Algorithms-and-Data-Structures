#include "AlgorithmsTest.h"
#include <gtest/gtest.h>
#include "../../ADSLibrary/Algorithms/ArraySearchingAlgorithms/ArraySearchingAlgorithms.h"
#include "../../ADSLibrary/Algorithms/SortingAlgorithms/SortingAlgorithms.h"

using namespace ADSLibrary::Algorithms::ArraySearchingAlgorithms;

/*
* Soubor slou��c� k testov�n� algoritm� pro vyhled�v�n�/�azen� v poli
*/

/*
* Pomocn� struktura pro testov�n�
*/
struct AlgStructTest : testing::Test
{
	void ReportArray(int a[], const int n)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << a[i] << "\t";
		}
		std::cout << "\n";
	}
};

TEST_F(AlgStructTest, SearchingAlgTest)
{
	const int numOfElements = 10;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	EXPECT_EQ(true, LinearSearch1(a, numOfElements, 2));
	EXPECT_EQ(true, LinearSearch1(a, numOfElements, 1));
	EXPECT_EQ(false, LinearSearch1(a, numOfElements, 33));
	EXPECT_EQ(true, LinearSearch1(a, numOfElements, 68));

	EXPECT_EQ(1, LinearSearch2(a, numOfElements, 2));
	EXPECT_EQ(8, LinearSearch2(a, numOfElements, 1));
	EXPECT_EQ(-1, LinearSearch2(a, numOfElements, 33)); // -1 prvek nen� v dan�m poli
	EXPECT_EQ(5, LinearSearch2(a, numOfElements, 68));

	EXPECT_EQ(true, LinearSearchRecursive1(a, numOfElements, 2, 0));
	EXPECT_EQ(true, LinearSearchRecursive1(a, numOfElements, 1, 0));
	EXPECT_EQ(false, LinearSearchRecursive1(a, numOfElements, 33, 0));
	EXPECT_EQ(true, LinearSearchRecursive1(a, numOfElements, 68,0 ));

	EXPECT_EQ(1, LinearSearchRecursive2(a, numOfElements, 2, 0));
	EXPECT_EQ(8, LinearSearchRecursive2(a, numOfElements, 1, 0));
	EXPECT_EQ(-1, LinearSearchRecursive2(a, numOfElements, 33, 0)); 
	EXPECT_EQ(5, LinearSearchRecursive2(a, numOfElements, 68, 0));


	int numOfComparisons, numOfExchanges;
	ADSLibrary::Algorithms::SortingAlgorithms::InsertSort(a, numOfElements, numOfComparisons, numOfExchanges); //sort pot�ebn� pro bin�rn� vyhled�v�n�

	EXPECT_EQ(true, BinarySearch1(a, numOfElements, 2));
	EXPECT_EQ(true, BinarySearch1(a, numOfElements, 1));
	EXPECT_EQ(false, BinarySearch1(a, numOfElements, 33));
	EXPECT_EQ(true, BinarySearch1(a, numOfElements, 68));

	EXPECT_EQ(1, BinarySearch2(a, numOfElements, 2));
	EXPECT_EQ(0, BinarySearch2(a, numOfElements, 1));
	EXPECT_EQ(9, BinarySearch2(a, numOfElements, 12071));
	EXPECT_EQ(5, BinarySearch2(a, numOfElements, 47));
	EXPECT_EQ(-1, BinarySearch2(a, numOfElements, 33));
	EXPECT_EQ(6, BinarySearch2(a, numOfElements, 68));

	EXPECT_EQ(1, BinarySearch3(a, numOfElements, 2));
	EXPECT_EQ(0, BinarySearch3(a, numOfElements, 1));
	EXPECT_EQ(9, BinarySearch3(a, numOfElements, 12071));
	EXPECT_EQ(5, BinarySearch3(a, numOfElements, 47));
	EXPECT_EQ(-5, BinarySearch3(a, numOfElements, 33)); //vrac� z�porn� ��slo, je� je bitov�m dopl�kem indexu v poli, kam m��e b�t prvek vlo�en bez naru�en� posloupnosti

	EXPECT_EQ(true, BinarySearchRecursive1(a, 0, numOfElements - 1, 2));
	EXPECT_EQ(true, BinarySearchRecursive1(a, 0, numOfElements - 1, 1));
	EXPECT_EQ(false, BinarySearchRecursive1(a, 0, numOfElements - 1, 33));
	EXPECT_EQ(true, BinarySearchRecursive1(a, 0, numOfElements - 1, 68));

	EXPECT_EQ(true, BinarySearchRecursive1a(a, 0, numOfElements - 1, 2));
	EXPECT_EQ(true, BinarySearchRecursive1a(a, 0, numOfElements - 1, 1));
	EXPECT_EQ(false, BinarySearchRecursive1a(a, 0, numOfElements - 1, 33));
	EXPECT_EQ(true, BinarySearchRecursive1(a, 0, numOfElements - 1, 68));

	EXPECT_EQ(1, BinarySearchRecursive2(a, 0, numOfElements - 1, 2));
	EXPECT_EQ(0, BinarySearchRecursive2(a, 0, numOfElements - 1, 1));
	EXPECT_EQ(9, BinarySearchRecursive2(a, 0, numOfElements - 1, 12071));
	EXPECT_EQ(5, BinarySearchRecursive2(a, 0, numOfElements - 1, 47));
	EXPECT_EQ(-1, BinarySearchRecursive2(a, 0, numOfElements - 1, 33));
	EXPECT_EQ(6, BinarySearchRecursive2(a, 0, numOfElements - 1, 68));

	EXPECT_EQ(1, BinarySearchRecursive3(a, 0, numOfElements - 1, 2));
	EXPECT_EQ(0, BinarySearchRecursive3(a, 0, numOfElements - 1, 1));
	EXPECT_EQ(9, BinarySearchRecursive3(a, 0, numOfElements - 1, 12071));
	EXPECT_EQ(5, BinarySearchRecursive3(a, 0, numOfElements - 1, 47));
	EXPECT_EQ(-5, BinarySearchRecursive3(a, 0, numOfElements - 1, 33));
}
TEST_F(AlgStructTest, SelectionSortTest)
{
	using namespace ADSLibrary::Algorithms::SortingAlgorithms;
	const int numOfElements = 10;
	int numOfComparisons, numOfExchanges;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	SelectSort(a, numOfElements, numOfComparisons, numOfExchanges);
	ReportArray(a, numOfElements);
}

TEST_F(AlgStructTest, InsertionsSortTest)
{
	using namespace ADSLibrary::Algorithms::SortingAlgorithms;
	const int numOfElements = 10;
	int numOfComparisons, numOfExchanges;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	InsertSort(a, numOfElements, numOfComparisons, numOfExchanges);
	ReportArray(a, numOfElements);
}

TEST_F(AlgStructTest, BubbleSortsTest)
{
	using namespace ADSLibrary::Algorithms::SortingAlgorithms;
	const int numOfElements = 10;
	int numOfComparisons, numOfExchanges;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	BubbleSort0(a, numOfElements, numOfComparisons, numOfExchanges);
	ReportArray(a, numOfElements);
	BubbleSort1(a, numOfElements, numOfComparisons, numOfExchanges);
	ReportArray(a, numOfElements);
	BubbleSort2(a, numOfElements, numOfComparisons, numOfExchanges);
	ReportArray(a, numOfElements);
	BubbleSort3(a, numOfElements, numOfComparisons, numOfExchanges);
	ReportArray(a, numOfElements);
	BubbleSort4(a, numOfElements, numOfComparisons, numOfExchanges);
}

TEST_F(AlgStructTest, ShakerSortTest)
{
	using namespace ADSLibrary::Algorithms::SortingAlgorithms;
	const int numOfElements = 10;
	int numOfComparisons, numOfExchanges;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	ShakerSort(a, numOfElements, numOfComparisons, numOfExchanges);
	ReportArray(a, numOfElements);
}

TEST_F(AlgStructTest, QuickSortTest)
{
	using namespace ADSLibrary::Algorithms::SortingAlgorithms;
	const int numOfElements = 10;
	int numOfComparisons, numOfExchanges;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	QuickSort(a, numOfElements, numOfComparisons, numOfExchanges);
	ReportArray(a, numOfElements);
}


TEST_F(AlgStructTest, HeapSortTest)
{	
	using namespace ADSLibrary::Algorithms::SortingAlgorithms;
	const int numOfElements = 10;
	int numOfComparisons, numOfExchanges;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	HeapSort(a, numOfElements, numOfComparisons, numOfExchanges);
	ReportArray(a, numOfElements);
}



AlgorithmsTest::AlgorithmsTest()
{
	
}

AlgorithmsTest::~AlgorithmsTest()
{
}